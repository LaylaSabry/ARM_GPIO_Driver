/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 13 August 2020      */ 
/*   version : 02 V             */
/********************************/  


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPinDirection
 * @brief : this function sets the direction of a PIN ( input/output ) and their modes
 * @param : Copy_u8Port
 * @param : Copy_u8Pin
 * @param : u8Copy_u8Mode
 */
void MGPIO_VidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode  )
{
	switch(Copy_u8Port){
		case PORTA:

			if(Copy_u8Pin <= 7 ){//low

				GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
				GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

			}else if(Copy_u8Pin <=15 ){//high

				Copy_u8Pin = Copy_u8Pin - 8;
				GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
			}

			break;

		case PORTB:

			if(Copy_u8Pin <= 7 ){//low

				GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
				GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

			}else if(Copy_u8Pin <=15 ){//high

				Copy_u8Pin = Copy_u8Pin - 8;
				GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
			}

			break;
		case PORTC:

			if(Copy_u8Pin <= 7 ){//low

				GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
				GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

			}else if(Copy_u8Pin <=15 ){//high

				Copy_u8Pin = Copy_u8Pin - 8;
				GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
				GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
			}

			break;
		default :break;
		}

}

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPinValue
 * @brief : this function sets the value of a PIN ( 0/1 )
 * @param : Copy_u8Port
 * @param : Copy_u8Pin
 * @param : u8Copy_u8Value
 */
void MGPIO_VidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value )
{
	switch(Copy_u8Port){
		case PORTA:

			if( u8Copy_u8Value == HIGH ){

				SET_BIT( GPIOA_ODR , Copy_u8Pin );

			}else if( u8Copy_u8Value == LOW ){
				CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
			}

			break;
		case PORTB:

			if( u8Copy_u8Value == HIGH ){

				SET_BIT( GPIOB_ODR  , Copy_u8Pin );

			}else if( u8Copy_u8Value == LOW ){
				CLR_BIT( GPIOB_ODR  , Copy_u8Pin );
			}

			break;
		case PORTC:

			if( u8Copy_u8Value == HIGH ){

				SET_BIT( GPIOC_ODR , Copy_u8Pin );

			}else if( u8Copy_u8Value == LOW ){
				CLR_BIT( GPIOC_ODR , Copy_u8Pin );
			}

			break;

		}

}

/***********************************************************************************************/
/**
 * @fun    : GPIO_u8GetPinValue
 * @brief  : this function gets the value of the input pin
 * @param  : Copy_u8Port
 * @param  : Copy_u8Pin
 * @return : pin value 0 or 1
 */
u8   MGPIO_u8GetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	u8 LOC_u8PinValue = 0 ;

		switch(Copy_u8Port){
		case PORTA:
			LOC_u8PinValue = GET_BIT( GPIOA_IDR , Copy_u8Pin );

			break;
		case PORTB:

			LOC_u8PinValue = GET_BIT( GPIOB_IDR , Copy_u8Pin );

			break;
		case PORTC:

			LOC_u8PinValue = GET_BIT( GPIOC_IDR , Copy_u8Pin );

			break;

		}

		return LOC_u8PinValue;


}

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPortDirection
 * @brief : this functios sets the direction of the entire port
 * @param : Copy_u8Port
 * @param : u8Copy_u8Mode
 * @note  : use this function if aand if only all pins of this port have the same mode
 */
void MGPIO_VidSetPortDirection  ( u8 Copy_u8Port , u32 u32Copy_u32PortMode  )
{
	switch(Copy_u8Port){
	case PORTA:
		GPIOA_CRL = u32Copy_u32PortMode ;
		GPIOA_CRH = u32Copy_u32PortMode ;
		break;

	case PORTB:
		GPIOB_CRL = u32Copy_u32PortMode ;
		GPIOB_CRH = u32Copy_u32PortMode ;
		break;
	case PORTC:
		GPIOC_CRL = u32Copy_u32PortMode ;
		GPIOC_CRH = u32Copy_u32PortMode ;
		break;


	default :break;
	}


}

/***********************************************************************************************/
/**
 * @fun   : GPIO_VidSetPortValue
 * @brief : this function sets an output port value (u32)
 * @param : Copy_u8Port
 * @param : u8Copy_u8Value
 */
void MGPIO_VidSetPortValue      ( u8 Copy_u8Port , u32 u32Copy_u8Value )
{
	switch (Copy_u8Port)
	{
		case PORTA : GPIOA_ODR =  u32Copy_u8Value ; break ;
		case PORTB : GPIOB_ODR =  u32Copy_u8Value ; break ;
		case PORTC : GPIOC_ODR =  u32Copy_u8Value ; break ;

	}

}

/***********************************************************************************************/
/**
 * @fun    : GPIO_u32GetPortValue
 * @brief  : this function gets the value of an entire input port
 * @param  : Copy_u8Port
 * @return : entire input port value (u32)
 */
u32  MGPIO_u32GetPortValue      ( u8 Copy_u8Port )
{
	u32 LOC_u32PortValue = 0 ;

	switch (Copy_u8Port)
	{
		case PORTA : LOC_u32PortValue = GPIOA_IDR ; break ;
		case PORTB : LOC_u32PortValue = GPIOB_IDR ; break ;
		case PORTC : LOC_u32PortValue = GPIOC_IDR ; break ;
		default    : break ;

	}

	return LOC_u32PortValue ;
}

/***********************************************************************************************/




