---
title: DigitalIos main() Analysis
author: 이우택 (wootaik@gmail.com)  
date: Sep 01 2016  
---

# DigitalIos main() Analysis 

## 목적
* Dave Project Template 의 main 함수와 Dave library 함수의 호출 관계를 이해한다.

## 참고자료

* DigitalIos 

## Source Codes

**[main.c]**

```c
#include <DAVE.h>  //Declarations from DAVE Code Generation (includes SFR declaration)

/**
 * @brief main() - Application entry point
 */

int main(void){

  DAVE_STATUS_t status;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  if(status != DAVE_STATUS_SUCCESS)
  {
    /* 중간 생략 */
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
  	if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_0) == 0U)
  		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_0);
  	else
  		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_0);

  	if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_1) == 0U)
  	    DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_1);
  	else
  		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_1);
  }
}

```

1. ```DAVE_STATUS_t``` 

   in [Dave/Generated/DAVE.h]

   ~~~c
   typedef enum DAVE_STATUS
   {
     DAVE_STATUS_SUCCESS = 0,
     DAVE_STATUS_FAILURE
   } DAVE_STATUS_t;
   ~~~

   .

   .

   .

2. ```DAVE_Init()```  

   in [Dave/Generated/DAVE.c]

   ~~~c
   DAVE_STATUS_t DAVE_Init(void)
   {
     DAVE_STATUS_t init_status;
     
     init_status = DAVE_STATUS_SUCCESS;
     if (init_status == DAVE_STATUS_SUCCESS)
     {
   	 /**  Initialization of DIGITAL_IO APP instance dhDIGITAL_IN_0 */
   	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&dhDIGITAL_IN_0); 
      } 
     if (init_status == DAVE_STATUS_SUCCESS)
     {
   	 /**  Initialization of DIGITAL_IO APP instance dhDIGITAL_IN_1 */
   	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&dhDIGITAL_IN_1); 
      } 
     if (init_status == DAVE_STATUS_SUCCESS)
     {
   	 /**  Initialization of DIGITAL_IO APP instance dhDIGITAL_OUT_0 */
   	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&dhDIGITAL_OUT_0); 
      } 
     if (init_status == DAVE_STATUS_SUCCESS)
     {
   	 /**  Initialization of DIGITAL_IO APP instance dhDIGITAL_OUT_1 */
   	 init_status = (DAVE_STATUS_t)DIGITAL_IO_Init(&dhDIGITAL_OUT_1); 
      }  
     return init_status;
   } /**  End of function DAVE_Init */
   ~~~

   .

   .

   .

   .

3. ```DIGITAL_IO_GetInput()```

   in [Dave/Generated/DIGITAL_IO/digital_io.h]

   ~~~C
   __STATIC_INLINE uint32_t DIGITAL_IO_GetInput(const DIGITAL_IO_t *const handler)
   {
     XMC_ASSERT("DIGITAL_IO_GetInput: handler null pointer", handler != NULL);
     return XMC_GPIO_GetInput(handler->gpio_port, handler->gpio_pin);
   }
   ~~~

   .

   .

   .

   .

   .

4. ```dhDIGITAL_IN_0``` 

   in [Dave/Generated/DIGITAL_IO/digital_io_conf.c]

   ~~~C
   const DIGITAL_IO_t dhDIGITAL_IN_1 =
   {
     .gpio_port = XMC_GPIO_PORT1,
     .gpio_pin = 15U,
     .gpio_config = {
       .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

     },
     .hwctrl = XMC_GPIO_HWCTRL_DISABLED
   };
   ~~~

   .

   .

   .

   .

   .

   ​