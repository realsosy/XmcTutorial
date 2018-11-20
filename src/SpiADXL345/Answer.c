/*
 * main.c
 *
 *  Created on: 2017 Aug 06 23:19:56
 *  Author: Wootaik
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

#include "ADXL345.h"

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
#define BUFFER_SIZE                  12


uint8_t FrameByte = 2;

/*Data for the Master*/
uint8_t MasterDataTx[BUFFER_SIZE] = {1};
uint8_t MasterDataRx[BUFFER_SIZE] = {2};
uint8_t MasterTxEnable = false;
uint8_t MasterRxEnable = false;
uint8_t MasterTransEnable = false;

uint32_t SysTimer10mId;
bool SysTimer10mFlag=false;

bool bXyzComplete = false;
int16_t AccelX;
int16_t AccelY;
int16_t AccelZ;
bool AccelScanEnable = true;

void ADXL345_WriteRegister(uint8_t reg, uint8_t value);
uint8_t ADXL345_ReadRegister(uint8_t reg);
bool ADXL345_Begin(void);

void ADXL345_WriteRegister(uint8_t reg, uint8_t value){
	MasterDataTx[0] = 0x00 | reg;
	MasterDataTx[1] = value;
	while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
	SPI_MASTER_Transfer(&dhSPI_MASTER, MasterDataTx, MasterDataRx, FrameByte);
}

uint8_t ADXL345_ReadRegister(uint8_t reg){
	MasterDataTx[0] = 0x80 | reg;
	MasterDataTx[1] = 0xFF;
	SPI_MASTER_Transfer(&dhSPI_MASTER, MasterDataTx, MasterDataRx, FrameByte);
	while(SPI_MASTER_IsRxBusy(&dhSPI_MASTER))  {  } /*Wait until MasterDataRx updated */
	return(MasterDataRx[1]);
}

bool ADXL345_Begin(void){
	uint8_t device_id;

	/* Get & Check DEVID */
	device_id = ADXL345_ReadRegister(ADXL345_DEVID);
	if(device_id != 0xE5)
	{
		return false;
	}

	ADXL345_WriteRegister(ADXL345_POWER_CTL, 0x08); /* Enable measurements */
	ADXL345_WriteRegister(ADXL345_BW_RATE, 0x0D); /* Set Conversion Rate 800Hz */


	return(true);
}

void ADXL345_GetXYZ_Polling(void){
	uint16_t upper, lower;
	lower = ADXL345_ReadRegister(ADXL345_DATAX0);
	upper = ADXL345_ReadRegister(ADXL345_DATAX1);
	AccelX = (int16_t) ( (upper << 8) | lower);
	lower = ADXL345_ReadRegister(ADXL345_DATAY0);
	upper = ADXL345_ReadRegister(ADXL345_DATAY1);
	AccelY = (int16_t) ( (upper << 8) | lower);
	lower = ADXL345_ReadRegister(ADXL345_DATAZ0);
	upper = ADXL345_ReadRegister(ADXL345_DATAZ1);
	AccelZ = (int16_t) ( (upper << 8) | lower);
}

void ISR_SpiMasterRx(){
	//DIGITAL_IO_ToggleOutput(&dhDO_SPI_MASTER);

	// Get XYZ using ISR
	if(bXyzComplete==false) {
		AccelX = (int16_t)( ((uint16_t)MasterDataRx[3] << 8) | MasterDataRx[1] );
		AccelY = (int16_t)( ((uint16_t)MasterDataRx[7] << 8) | MasterDataRx[5] );
		AccelZ = (int16_t)( ((uint16_t)MasterDataRx[11] << 8) | MasterDataRx[9] );
		bXyzComplete = true;
	}
}

void ADXL345_GetXYZ(void){
	// Get XYZ using ISR
	MasterDataTx[0] = 0x80|ADXL345_DATAX0;
	MasterDataTx[1] = 0;
	MasterDataTx[2] = 0x80|ADXL345_DATAX1;
	MasterDataTx[3] = 0;
	MasterDataTx[4] = 0x80|ADXL345_DATAY0;
	MasterDataTx[5] = 0;
	MasterDataTx[6] = 0x80|ADXL345_DATAY1;
	MasterDataTx[7] = 0;
	MasterDataTx[8] = 0x80|ADXL345_DATAZ0;
	MasterDataTx[9] = 0;
	MasterDataTx[10] = 0x80|ADXL345_DATAZ1;
	MasterDataTx[11] = 0;

	bXyzComplete = false;
	SPI_MASTER_Transfer(&dhSPI_MASTER, MasterDataTx, MasterDataRx, FrameByte*6);
}

void TestAdxl345(){

	// Get XYZ using ISR
//	ADXL345_GetXYZ();

	// Get XYZ using Polling
	ADXL345_GetXYZ_Polling();

	if(AccelX >= 0){
		PWM_SetDutyCycle(&dhPWM_XPlus, AccelX<<4);
		PWM_SetDutyCycle(&dhPWM_XMinus, 0);
	}
	else{
		PWM_SetDutyCycle(&dhPWM_XPlus, 0);
		PWM_SetDutyCycle(&dhPWM_XMinus, (-1*AccelX)<<4);
	}
}

void SysTimer10m(){
	SysTimer10mFlag = true;
}

int main(void)
{
	DAVE_STATUS_t status;

	status = DAVE_Init();           /* Initialization of DAVE APPs  */

	if(status != DAVE_STATUS_SUCCESS)
	{
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while(1U)
		{

		}
	}

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */

	SPI_MASTER_DisableSlaveSelectSignal(&dhSPI_MASTER);
	SPI_MASTER_EnableSlaveSelectSignal(&dhSPI_MASTER, SPI_MASTER_SS_SIGNAL_0);

	ADXL345_Begin();

	SysTimer10mId = SYSTIMER_CreateTimer(10000, SYSTIMER_MODE_PERIODIC, SysTimer10m, NULL);

	SYSTIMER_StartTimer(SysTimer10mId);

	while(1U)
	{
		if(MasterTxEnable == true){
			while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
			SPI_MASTER_Transmit(&dhSPI_MASTER, MasterDataTx, FrameByte);
			MasterTxEnable = false;
		}

		if(MasterRxEnable == true){
			while(SPI_MASTER_IsRxBusy(&dhSPI_MASTER))  {  }
			SPI_MASTER_Receive(&dhSPI_MASTER, MasterDataRx, FrameByte);
			MasterRxEnable = false;
		}

		if(MasterTransEnable == true){
			while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
			SPI_MASTER_Transfer(&dhSPI_MASTER, MasterDataTx, MasterDataRx, FrameByte);
			MasterTransEnable = false;
		}

		if(SysTimer10mFlag == true){
			if (AccelScanEnable == true){
				TestAdxl345();
			}
			SysTimer10mFlag = false;
		}

	}
}
