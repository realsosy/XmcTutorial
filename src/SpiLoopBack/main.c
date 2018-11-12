/*
 * main.c
 *
 *  Created on: 2017 Jul 30 13:06:45
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

/* Data and buffers used */
#define BUFFER_SIZE                  10

/*Data to be sent by the Master*/
uint8_t master_send_data[] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa};

/*Master and slave arrays for receiving*/
uint8_t master_rec_data[BUFFER_SIZE];
uint8_t slave_rec_data[BUFFER_SIZE];

/* Slave: all data received callback */
void Slave_received_data()
{
  /*Transmit data */
  SPI_SLAVE_Transmit(&dhSPI_SLAVE_0, slave_rec_data,10);

  /* Master receive data */
  SPI_MASTER_Receive(&dhSPI_MASTER_0, master_rec_data,10);
}

/* Master: all data received callback */
void Master_received_data()
{
  int error;

  /* For loop to check the  */
  for(uint8_t arr_index = 0; arr_index < BUFFER_SIZE; arr_index++)
  {
    error=master_send_data[arr_index]- master_rec_data[arr_index];
    if (error!=0)
    {
      /*Switch ON the P1_1 LED in the Relax Kit to show that the data received in the Master is not matching with the Slave data*/
      DIGITAL_IO_SetOutputHigh(&dhDIO_0);
	  while(1);
    }
  }
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

  /* Slave receive Data*/
  SPI_SLAVE_Receive(&dhSPI_SLAVE_0, slave_rec_data,10);

  /* Master Transmit Data */
  /* SS_1 로 자료를 보냄 --> 아무런 반응을 보이지 않음 */
  while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER_0))  {  }
  SPI_MASTER_DisableSlaveSelectSignal(&dhSPI_MASTER_0);
  SPI_MASTER_EnableSlaveSelectSignal(&dhSPI_MASTER_0, SPI_MASTER_SS_SIGNAL_1);
  SPI_MASTER_Transmit(&dhSPI_MASTER_0, master_send_data,10);

  /* SS_0 로 자료를 보냄 --> Slave 에서 수신 후 Echoing */
  while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER_0))  {  }
  SPI_MASTER_DisableSlaveSelectSignal(&dhSPI_MASTER_0);
  SPI_MASTER_EnableSlaveSelectSignal(&dhSPI_MASTER_0, SPI_MASTER_SS_SIGNAL_0);
  SPI_MASTER_Transmit(&dhSPI_MASTER_0, master_send_data,10);



  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
