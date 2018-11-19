---
title: Lab ADXL345  
author: Wootaik Lee(wootaik@changwon.ac.kr)  
date: 2017-09-01  
---

# ADXL345 Digital Accelerometer Lab  

## References

*   ADXL345.pdf
*   GY-291-schematic.jpg
*   MySpiMasterSlave


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
    	MasterDataTx[0] = 0x00 | reg;
    	MasterDataTx[1] = value;
    	while(SPI_MASTER_IsTxBusy(&dhSPI_MASTER))  {  }
    	SPI_MASTER_Transfer(&dhSPI_MASTER, MasterDataTx, MasterDataRx, FrameByte);
    }
    ```

    *   Full Duplex mode로 동작해야 하므로 `SPI_MASTER_Trasnfer` method를 사용하여 2byte의 MasterDataTx를 전송하고 MasterDataRx의 자료를 받는다.
    *   전송이 완료되기 전에 다시 이 함수가 호출되어 Over-run 이 발생되는 상황을 방지하기 위하여 `SPI_MASTER_IsTxBusy( )`Method를 사용하여 **Busy-wait** 한다.

**[Activity]** `ADXL345_ReadRegister( )` 함수를 완성하여 보아라

*   Read Cycle을 수행하기 위해서는 MasterDataTx[0] 에 어떤 값을 넣어 주어야 하는가?

*   유효한 데이터는 어디에 존재하는가?

*   `SPI_MASTER_Trasnfer( )` Method 동작이 모두 완료되어야 MasterDataRx에 Data 가 들어오게 된다.  어떻게 그때까지 **Busy-wait** 시킬 수 있나?

    ```
    uint8_t ADXL345_ReadRegister(uint8_t reg){
    ```




    	return(         );
    }
    ​```



## Set-Up: Begin()

*   ReadRegister(), WriteRegister() 함수를 사용하여 기본정보를 확인하고, 설정할 수 있다.

    *   DEVID: Device ID를 읽어서 그 값이 0xE5 인지 확인한다.
    *   BW_RATE: 현재 1000KHz 의 전송속도를 고려하여 800Hz로 Conversion Rate를 설정한다.
    *   POWER_CTL: Measurement bit를 Set 하여 Conversion을 시작한다.

    ```
    bool ADXL345_Begin(void){
    	uint8_t device_id;
    	/* Get & Check DEVID */
    	device_id = ADXL345_ReadRegister(ADXL345_DEVID);
    	if(device_id != 0xE5){
    		return false;
    	}

    	ADXL345_WriteRegister(ADXL345_POWER_CTL, 0x08); /* Enable measurements */
    	ADXL345_WriteRegister(ADXL345_BW_RATE, 0x0D); /* Set Conversion Rate 800Hz */
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

*   `TestAdxl345()` 함수는 10msec 마다 실행하도록 설정되어 있다.
*   이 함수 내부에서 AccelX의 값에 따라서 LED1, LED2 의 밝기가 변화하도록 프로그래밍 되어 있다.
*   프로그램을 실행하고 ADXL345 센서를 X축 방향으로 기울여 가면서 LED1과 LED2의 변화를 관찰한다.
*   정확한 값의 변화를 확인하기 위하여 Debugger, 혹은 uC/Probe를 사용하여 AccelY와 AccelZ의 값을 살펴본다.



## Optimization 

*   현재 프로그램은 X, Y, Z 축의 Data를 읽어들이기 위하여 총 96bit (8bit X 12)의 시간동안 Polling 방식으로 통신을 하고 있다.  1000KHz의 통신 속도로 전송하므로 1usec X 96 의 시간동안 통신을 위한 대기 상태를 유지하게 된다.  약 0.1 msec의 시간을 낭비하게 되는 것이다.  
*   현재와 같이 단순한 작업을 진행하는 상황이라면 크게 문제되지 않지만, 해야하는 테스크가 늘어나거나, 신호처리의 주기가 짧아지는 상황이라면 최적화를 해야할 필요가 있다.
*   Interrupt를 사용하는 전송방식으로 프로그램을 개선한다면 이 대기 시간을 대폭적으로 줄일 수 있게 된다.

**[Activity]** Interrupt를 사용하여 `ADXL345_GetXYZ(void)` Method를 새롭게 만들고, Data의 수신이 완료되면 `ISR_SpiMasterRx( )`에서 AccelX, AccelY, AccelZ 값을 Update 하도록 개선해 보아라.