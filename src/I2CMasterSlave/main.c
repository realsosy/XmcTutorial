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

#define BUFFER_SIZE 4

uint8_t I2C_TxDataSize = 4;
uint8_t I2C_RxDataSize = 4;

/*Data for the Master*/
uint8_t I2C_MasterDataTx[BUFFER_SIZE] = {11,12,13,14};
uint8_t I2C_MasterDataRx[BUFFER_SIZE] = {21,22,23,24};
bool I2C_MasterTxEnable = false;
bool I2C_MasterRxEnable = false;
bool I2C_MasterTransEnable = false;
uint8_t I2C_SlaveAddress = 10;

/*Data for the Slave*/
uint8_t I2C_SlaveDataTx[BUFFER_SIZE] = {31,32,33,34};
uint8_t I2C_SlaveDataRx[BUFFER_SIZE] = {41,42,43,44};

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

	//Start Master data transmission
	while(1){

		if(I2C_MasterTxEnable != false)
		{
			while( I2C_MASTER_IsTxBusy(&dhI2C_MASTER) == true) { };
			I2C_SLAVE_Receive(&dhI2C_SLAVE, I2C_SlaveDataRx, I2C_TxDataSize);
			I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, I2C_TxDataSize, true);
			I2C_MasterTxEnable = false;
		}

		if(I2C_MasterRxEnable != false)
		{
			while( I2C_MASTER_IsRxBusy(&dhI2C_MASTER) == true) { };
			I2C_SLAVE_Transmit(&dhI2C_SLAVE, I2C_SlaveDataTx, I2C_RxDataSize);
			I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, I2C_RxDataSize, true, true);
			I2C_MasterRxEnable = false;
		}

		if(I2C_MasterTransEnable != false){
			while( I2C_MASTER_IsTxBusy(&dhI2C_MASTER) == true) { };
			I2C_SLAVE_Receive(&dhI2C_SLAVE, I2C_SlaveDataRx, I2C_TxDataSize);
			I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, I2C_TxDataSize, false);
			while( I2C_MASTER_IsTxBusy(&dhI2C_MASTER) == true) { };
			I2C_SLAVE_Transmit(&dhI2C_SLAVE, I2C_SlaveDataTx, I2C_RxDataSize);
			I2C_MASTER_Receive(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataRx, I2C_RxDataSize, true, true);
			while( I2C_MASTER_IsRxBusy(&dhI2C_MASTER) == true) { };
			I2C_MasterTransEnable = false;
		}
	}
}


//Callback after Read request received from Master
void CB_I2C_SlaveReadRequest()
{
	DIGITAL_IO_ToggleOutput(&dhDO_1);
//	I2C_SLAVE_Transmit(&dhI2C_SLAVE, I2C_SlaveDataTx, I2C_RxDataSize);
}

//Callback after end of Slave reception
void CB_I2C_SlaveReceive()
{
	DIGITAL_IO_ToggleOutput(&dhDO_0);
//	I2C_SLAVE_Receive(&dhI2C_SLAVE, I2C_SlaveDataRx, I2C_TxDataSize);
}

