/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 15 August 2020      */
/*  Descrption : 7 seg          */ 
/*   version : 01 V             */
/*********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

void LED_voidON( u8 copy_PORTID , u8 copy_PINID)
{
	MGPIO_VidSetPinDirection (copy_PORTID , copy_PINID , OUTPUT_2MHZ_PP );
	MGPIO_VidSetPinValue     (copy_PORTID  , copy_PINID , HIGH);
}

void LED_voidOFF( u8 copy_PORTID , u8 copy_PINID)
{
	MGPIO_VidSetPinDirection (copy_PORTID , copy_PINID , OUTPUT_2MHZ_PP );
	MGPIO_VidSetPinValue     (copy_PORTID ,copy_PINID , LOW);
}