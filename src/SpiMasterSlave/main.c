/*
 * main.c
 *
 *  Created on: 2017 Aug 06 23:19:56
 *  Author: Wootaik
 */

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
#define BUFFER_SIZE                  4
uint8_t FrameByte = 2;

/*Data for the Master*/
uint8_t MasterDataTx[BUFFER_SIZE] = {11,12,13,14};
uint8_t MasterDataRx[BUFFER_SIZE] = {21,22,23,24};
uint8_t MasterTxEnable = false;
uint8_t MasterRxEnable = false;
uint8_t MasterTransEnable = false;


/*Data for the Slave*/
uint8_t SlaveDataTx[BUFFER_SIZE] = {31,32,33,34};
uint8_t SlaveDataRx[BUFFER_SIZE] = {41,42,43,44};
uint8_t SlaveEcho = false;

void ISR_SpiMasterRx(){
	DIGITAL_IO_ToggleOutput(&dhDO_SPI_MASTER);
}

void ISR_SpiSlaveRx(){
	DIGITAL_IO_ToggleOutput(&dhDO_SPI_SLAVE);
    if(SlaveEcho == true){
		memcpy(SlaveDataTx, SlaveDataRx, FrameByte);
	}
    SPI_SLAVE_Receive(&dhSPI_SLAVE, SlaveDataRx, FrameByte);
    SPI_SLAVE_Transmit(&dhSPI_SLAVE, SlaveDataTx, FrameByte);
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

  SPI_SLAVE_Receive(&dhSPI_SLAVE, SlaveDataRx, FrameByte);
  SPI_SLAVE_Transmit(&dhSPI_SLAVE, SlaveDataTx, FrameByte);

  while(1U)
  {
	  if(MasterTxEnable == true){
		  while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
		  SPI_MASTER_Transmit(&dhSPI_MASTER, MasterDataTx, FrameByte);
		  MasterTxEnable = false;
	  }

	  if(MasterRxEnable == true){
		  while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
		  SPI_MASTER_Receive(&dhSPI_MASTER, MasterDataRx, FrameByte);
		  MasterRxEnable = false;
	  }

	  if(MasterTransEnable == true){
		  while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
		  SPI_MASTER_Transfer(&dhSPI_MASTER, MasterDataTx, MasterDataRx, FrameByte);
		  MasterTransEnable = false;
	  }
  }
}
