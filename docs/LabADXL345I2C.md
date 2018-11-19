---
title: ADXL345 Revisited Lab  
author: Wootaik Lee(wootaik@changwon.ac.kr)  
date: 2017-09-01  
---

# ADXL345 Revisited Lab  

## References

*   ADXL345.pdf
*   GY-291-schematic.jpg
*   MyI2CMasterSlave


## Programming Library for ADXL345

*   ADXL345를 사용하는 함수들을 설계하고 구현한다.  

*   이것들을 모아서 Library를 만든다.

*   Data

    ```
    int16_t AccelX;   /* -2g ~ +2g : -512 ~ 511
    int16_t AccelY;
    int16_t AccelZ;
    ```

*   Methods

    ```C
    void ADXL345_WriteRegister(uint8_t reg, uint8_t value);
    uint8_t ADXL345_ReadRegister(uint8_t reg);
    bool ADXL345_Begin(void);
    void ADXL345_GetXYZ_Polling(void);
    ```

## Basic: ReadRegister() WriteRegister()

*   `ADXL345_WriteRegister( )`는 다음과 같이 만들 수 있다.

    ```c
    void ADXL345_WriteRegister(uint8_t reg, uint8_t value){
    	I2C_MasterDataTx[0] =  reg;
    	I2C_MasterDataTx[1] =  value;
    	while( I2C_MASTER_IsRxBusy(&dhI2C_MASTER) == true) { };
    	I2C_MASTER_Transmit(&dhI2C_MASTER, true, I2C_SlaveAddress, I2C_MasterDataTx, 2, true);
    }
    ```

    *   `I2C_MASTER_Trasmit` method를 사용하여 2byte의 MasterDataTx를 전송한다.
    *   전송이 완료되기 전에 다시 이 함수가 호출되어 Over-run 이 발생되는 상황을 방지하기 위하여 `SPI_MASTER_IsTxBusy( )`Method를 사용하여 **Busy-wait** 한다.

**[Activity]** `ADXL345_ReadRegister( )` 함수를 완성하여 보아라

*   Read Cycle을 수행하려면 `I2C_MASTER_Transmit()` 을 수행하여 해당 레지스터를 써준다.(주의 이때 STOP bit를 False 로 하여 전송 Cycle이 종료되는 것을 방지해 줘야 한다.)

*   `I2C_MASTER_Receive()`를 수행하여 해당 레지스터의 값을 읽어들여야 한다.

*   각 명령이 실행되는 중에 Over-run이 발생되는 것을 방지하기 위하여 **Busy-wait** 한다.

    ```
    uint8_t ADXL345_ReadRegister(uint8_t reg){
    ```





    	return(I2C_MasterDataRx[0]);
    }
    ​```



## Set-Up: Begin()

*   ReadRegister(), WriteRegister() 함수를 사용하여 기본정보를 확인하고, 설정할 수 있다.

    *   DEVID: Device ID를 읽어서 그 값이 0xE5 인지 확인한다.
    *   BW_RATE: 현재 100KHz 의 전송속도를 고려하여 100Hz로 Conversion Rate를 설정한다.
    *   POWER_CTL: Measurement bit를 Set 하여 Conversion을 시작한다.

    ```
    bool ADXL345_Begin(void){
    	uint8_t device_id;
    	/* Get & Check DEVID */
    	device_id = ADXL345_ReadRegister(ADXL345_DEVID);
    	if(device_id != 0xE5){
    		return false;
    	}

    	ADXL345_WriteRegister(ADXL345_BW_RATE, 0x0A); /* Set Conversion Rate 100Hz */
    	ADXL345_WriteRegister(ADXL345_POWER_CTL, 0x08); /* Enable measurements */
    	return(true);
    }
    ```




## Read Acceleration X, Y, Z

*   DATAX0 와 DATAX1 레지스터를 읽어들여서 가속도 정보의 Lower byte와 Upper byte를 얻는다.

**[Activity]** Lower byte와 Upper byte 정보를 조합하여 AccelX 정보를 만들어 낸다.

```
void ADXL345_GetXYZ_Polling(void){
    uint16_t upper, lower;
    lower = ADXL345_ReadRegister(ADXL345_DATAX0);
    upper = ADXL345_ReadRegister(ADXL345_DATAX1);
    // Calculate AccelX using lower & upper
    AccelX = 

    /* 이하 생략 */
}
```


## Test

*   `TestAdxl345()` 함수는 100msec 마다 실행하도록 설정되어 있다.
*   이 함수 내부에서 AccelX의 값에 따라서 LED1, LED2 의 밝기가 변화하도록 프로그래밍 되어 있다.
*   프로그램을 실행하고 ADXL345 센서를 X축 방향으로 기울여 가면서 LED1과 LED2의 변화를 관찰한다.
*   정확한 값의 변화를 확인하기 위하여 Debugger, 혹은 uC/Probe를 사용하여 AccelY와 AccelZ의 값을 살펴본다.



## Optimization 

*   현재 프로그램은 X, Y, Z 축의 Data를 읽어들이기 위하여 총 6회의 Single-Byte Read 싸이클을 수행해야 한다.  Single-Byte Read 싸이클은 전송되는 데이터만 4byte (즉 32bit) 이상이 필요하게 된다.  그러므로 6축의 자료를 모두 읽어들이기 위해서는 24byte(약 200bit) 이상의 통신 시간이 필요하게 된다.  이를 100KHz를 기준으로 계산하면 2msec 라는 긴 시간이 필요하게 된다. 
*   현재와 같이 단순한 작업을 진행하는 상황이라면 크게 문제되지 않지만, 해야하는 테스크가 늘어나거나, 신호처리의 주기가 짧아지는 상황이라면 최적화를 해야할 필요가 있다.

### Multiple-Byte Read 싸이클 이용

*   ADXL345의 DATAX0 ~ DATAZ1 Address는 0x32번 부터 6byte가 모두 붙어 있다.  그러므로 Multiple-Byte Read 싸이클을 이용한다면 통신 오버헤드를 줄일 수 있다.  오버헤드 3byte, 데이타 6byte 이므로  9byte(약 80 bit)의 정보를 연속적으로 읽어들일 수 있다.  이 방법을 사용하면 각각을 읽어들이는데 필요한 시간을 절반 이하로 줄일 수 있다.  그러나 이 방법도 100KHz 전송속도를 기준으로 약 1msec의 시간에 해당하므로 바람직한 방법은 아니다.

**[Activity]** 

* Multiple-Byte Read 방법을 사용하는 함수를 만들어 보자.

  * ADXL345_ReadRegister 참고

  ```
  void ADXL345_GetXYZ_Multiple(void){
	/* To Do */
	
  }
  ```


### Interrupt를 이용

*   Interrupt를 사용하는 전송방식으로 프로그램을 개선한다면 이 대기 시간을 대폭적으로 줄일 수 있게 된다.

**[Activity]** 

*   Interrupt를 사용하여 `ADXL345_GetXYZ(void)` Method를 새롭게 만들고, Data의 수신이 완료되면 `CB_MasterReceiveComplete( )`에서 AccelX, AccelY, AccelZ 값을 Update 하도록 개선해 보아라.

  ```
    void CB_MasterReceiveComplete(){




    }
  ```


    