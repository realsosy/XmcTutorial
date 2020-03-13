/***************************************************************************//*!
*
* @file     UsrLibTest.c
*
* @author
*
* @version
*
* @date
*
* @brief
*
******************************************************************************/
#include "unity.h"
#include "UserLib.h"
#include "Dave.h"

static UserLib_Ramp_t  MyRamp = USERLIB_RAMP_DEFAULT;
static UserLib_Hyst_t	MyHyst = USERLIB_HYST_DEFAULT;

#define HYST_OFF -1.0
#define HYST_ON   1.0
#define OUT_OFF  -5.0
#define OUT_ON   5.0

void setUp(void){
	MyHyst.fltHystOff = HYST_OFF;
	MyHyst.fltHystOn = HYST_ON;
	MyHyst.fltOutOff = OUT_OFF;
	MyHyst.fltOutOn = OUT_ON;
	MyHyst.fltOutState = MyHyst.fltOutOff;

	MyRamp.fltState = 0.0;
	MyRamp.fltDecrement = -1.0;
	MyRamp.fltIncrement = 1.0;
}

void tearDown(void){

}

void test_UserLib_Hysteresis_Initial2High(void)
{
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(0.0, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(0.5, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(1.0, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(1.5, &MyHyst));
}

void test_UserLib_Hysteresis_High2Low(void)
{
	MyHyst.fltOutState = OUT_ON;
	TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(1.0, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(0.5, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(-0.5, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(-1.0, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(-1.5, &MyHyst));
}

void test_UserLib_Hysteresis_Low2High(void)
{
	MyHyst.fltOutState = OUT_OFF;
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(-1.0, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(-0.5, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_OFF, UserLib_Hyst(0.5, &MyHyst));
	TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(1.0, &MyHyst));
    TEST_ASSERT_EQUAL_FLOAT( OUT_ON, UserLib_Hyst(1.5, &MyHyst));
}

void test_UserLib_Ramp_Increment(void)
{
    TEST_ASSERT_EQUAL_FLOAT(1.0 , UserLib_Ramp(5.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(2.0 , UserLib_Ramp(5.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(3.0 , UserLib_Ramp(5.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(4.0 , UserLib_Ramp(5.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(5.0 , UserLib_Ramp(5.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(5.0 , UserLib_Ramp(5.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(5.0 , UserLib_Ramp(5.0, &MyRamp));
}

void test_UserLib_Ramp_Decrement(void)
{
	MyRamp.fltState = 2.0;
	TEST_ASSERT_EQUAL_FLOAT(1.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(0.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-1.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-2.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-2.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-3.0 , UserLib_Ramp(-4.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-4.0 , UserLib_Ramp(-4.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-4.0 , UserLib_Ramp(-4.0, &MyRamp));
}

void test_UserLib_Ramp_Swing(void)
{
	MyRamp.fltState = 0.0;
	TEST_ASSERT_EQUAL_FLOAT(-1.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-2.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-2.0 , UserLib_Ramp(-2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT(-1.0 , UserLib_Ramp(+2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 0.0 , UserLib_Ramp(+2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 1.0 , UserLib_Ramp(+2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 2.0 , UserLib_Ramp(+2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 2.0 , UserLib_Ramp(+2.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 1.0 , UserLib_Ramp(0.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 0.0 , UserLib_Ramp(0.0, &MyRamp));
    TEST_ASSERT_EQUAL_FLOAT( 0.0 , UserLib_Ramp(0.0, &MyRamp));
}

int main(void) {
//	while(1){;};

	UNITY_BEGIN();

    RUN_TEST(test_UserLib_Hysteresis_Initial2High);
    RUN_TEST(test_UserLib_Hysteresis_High2Low);
    RUN_TEST(test_UserLib_Hysteresis_Low2High);

    RUN_TEST(test_UserLib_Ramp_Increment);
    RUN_TEST(test_UserLib_Ramp_Decrement);
    RUN_TEST(test_UserLib_Ramp_Swing);

    return(UNITY_END());
}

/* End of file */

