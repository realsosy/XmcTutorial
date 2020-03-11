/**********************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification,are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share
 * modifications, enhancements or bug fixes with Infineon Technologies AG
 * dave@infineon.com).
 *******************************************************************************
 **                                                                            **
 **                                                                            **
 ** PLATFORM : Infineon XMC4000 Series                                         **
 **                                                                            **
 ** AUTHOR : Application Engineering Team                                      **
 **                                                                            **
 ** version 4.0.0 (Initial version)			                                      **
 **                                                                            **
 ** MODIFICATION DATE : Nov, 13, 2015                                          **
 **                                                                            **
 *******************************************************************************/


#include<Dave.h>
#include "ADXL345.h"

#define BUFFER_SIZE 8

uint8_t I2C_TxDataSize = 4;
uint8_t I2C_RxDataSize = 4;

/*Data for the Master*/
uint8_t I2C_MasterDataTx[BUFFER_SIZE];
uint8_t I2C_MasterDataRx[BUFFER_SIZE];
bool I2C_MasterTxEnable = false;
bool I2C_MasterRxEnable = false;
bool I2C_MasterTransEnable = false;

uint8_t I2C_SlaveAddress = 0xA6;  /* 0x53: ADXL345 alternate address, A6 for write, A7 for read */

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
void ADXL345_GetXYZ(void);
void ADXL345_GetXYZ_Multiple(void);
void ADXL345_GetXYZ_Polling(void);
void TestAdxl345(void);


void CB_MasterReceiveComplete(){
	if(bXyzComplete==false) {
		AccelX = (int16_t)( ((uint16_t)I2C_MasterDataRx[1] << 8) | I2C_MasterDataRx[0] );
		AccelY = (int16_t)( ((uint16_t)I2C_MasterDataRx[3] << 8) | I2C_MasterDataRx[2] );
		AccelZ = (int16_t)( ((uint16_t)I2C_MasterDataRx[5] << 8) | I2C_MasterDataRx[4] );
		bXyzComplete = true;
	}
}

void CB_MasterTransmitComplete(){

}

void ADXL345_WriteRegister(uint8_t reg, uint8_t value){
	I2C_MasterDataTx[0] =  reg;
	I2C_MasterDataTx[1] =  value;
	while( I2C_MASTER_IsRxBusy(&dhI2C_MASTER) == true) { };
	I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, 2, true);
}

uint8_t ADXL345_ReadRegister(uint8_t reg){
	I2C_MasterDataTx[0] =  reg;
	I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, 1, false);
    while(I2C_MASTER_IsTxBusy(&dhI2C_MASTER));
	I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, 1, true, true);
	while(I2C_MASTER_IsRxBusy(&dhI2C_MASTER));
	return(I2C_MasterDataRx[0]);
}

bool ADXL345_Begin(void){
	uint8_t device_id;
	device_id = ADXL345_ReadRegister(ADXL345_DEVID);
	if(device_id != 0xE5)
	{
		return false;
	}

	ADXL345_WriteRegister(ADXL345_BW_RATE, 0x0A); /* Set Conversion Rate 100Hz */

	ADXL345_WriteRegister(ADXL345_POWER_CTL, 0x08); /* Enable measurements */

	return(true);
}

void ADXL345_GetXYZ(void){
	bXyzComplete = false;
	I2C_MasterDataTx[0] =  ADXL345_DATAX0;
	I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, 1, false);
    while(I2C_MASTER_IsTxBusy(&dhI2C_MASTER));
	I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, 6, true, true);
}

void ADXL345_GetXYZ_Multiple(void){
	I2C_MasterDataTx[0] =  ADXL345_DATAX0;
	I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, 1, false);
    while(I2C_MASTER_IsTxBusy(&dhI2C_MASTER));
	I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, 6, true, true);
	while(I2C_MASTER_IsRxBusy(&dhI2C_MASTER));
	AccelX = (int16_t)( ((uint16_t)I2C_MasterDataRx[1] << 8) | I2C_MasterDataRx[0] );
	AccelY = (int16_t)( ((uint16_t)I2C_MasterDataRx[3] << 8) | I2C_MasterDataRx[2] );
	AccelZ = (int16_t)( ((uint16_t)I2C_MasterDataRx[5] << 8) | I2C_MasterDataRx[4] );
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


void TestAdxl345(){

	// Get XYZ using ISR
	ADXL345_GetXYZ();

	// Get XYZ using Polling
	//ADXL345_GetXYZ_Polling();

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

	status = DAVE_Init();      /* Initialization of DAVE APPs  */

	if(status == DAVE_STATUS_FAILURE)
	{
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler */
		XMC_DEBUG(("DAVE Apps initialization failed with status %d\n", status));
		while(1U)
		{
		}
	}

	ADXL345_Begin();

	SysTimer10mId = SYSTIMER_CreateTimer(100000, SYSTIMER_MODE_PERIODIC, SysTimer10m, NULL);

	SYSTIMER_StartTimer(SysTimer10mId);

	while(1){

		if(I2C_MasterTxEnable != false)
		{
			while( I2C_MASTER_IsTxBusy(&dhI2C_MASTER) == true) { };
			I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, I2C_TxDataSize, true);
			I2C_MasterTxEnable = false;
		}

		if(I2C_MasterRxEnable != false)
		{
			while( I2C_MASTER_IsRxBusy(&dhI2C_MASTER) == true) { };
			I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, I2C_RxDataSize, true, true);
			I2C_MasterRxEnable = false;
		}

		if(I2C_MasterTransEnable != false){
			while( I2C_MASTER_IsTxBusy(&dhI2C_MASTER) == true) { };
			I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, I2C_TxDataSize, false);
			while( I2C_MASTER_IsTxBusy(&dhI2C_MASTER) == true) { };
			I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, I2C_RxDataSize, true, true);
			while( I2C_MASTER_IsRxBusy(&dhI2C_MASTER) == true) { };
			I2C_MasterTransEnable = false;
		}

		if(SysTimer10mFlag == true){
			if (AccelScanEnable == true){
				TestAdxl345();
			}
			SysTimer10mFlag = false;
		}

	}
}



