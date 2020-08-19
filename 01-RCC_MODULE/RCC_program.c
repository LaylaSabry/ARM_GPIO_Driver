/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 13 August 2020      */ 
/*   version : 02 V             */
/********************************/  

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h" 
#include "RCC_config.h"

void MRCC_voidInitSysClock (void)
{
	#if MRCC_CLOCK_TYPE == MRCC_HSI
		RCC_CR   = 0x00000081 ; // trimming = 0b1000
	    RCC_CFGR = 0x00000000;
	#elif MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL
	
	    // ByPass OFF
	    RCC_CR   = 0x00010000 ;
	    RCC_CFGR = 0x00000001;
	#elif MRCC_CLOCK_TYPE == MRCC_HSE_RC
	
	    // ByPass ON
	    RCC_CR   = 0x00050000 ;
	    RCC_CFGR = 0x00000001;
/************************ PLL *****************/

	#elif MRCC_CLOCK_TYPE == MRCC_PLL_HSI_DIV2
	/*First we must select the multiplication value
	then enable PLL from RCC_CR Register
	 MCO -> System clock (SYSCLK) selected 
	 any prescaller 0 till now*/
	 
	 
	    RCC_CFGR  = 0x04000002;
	    RCC_CFGR |= (PLL_MUL_VALUE << 18);
	
	    RCC_CR   = 0x01000001 ;
/***********************************************************/

	#elif MRCC_CLOCK_TYPE == MRCC_PLL_HSE_RC_DIV2
	    RCC_CFGR  = 0x04030002;
	    RCC_CFGR |= (PLL_MUL_VALUE << 18);	
	
	    RCC_CR   = 0x01050000 ;
/************************************************************/		
	#elif MRCC_CLOCK_TYPE == MRCC_PLL_HSE_CRYSTAL_DIV2	
	    RCC_CFGR  = 0x04030004;
	    RCC_CFGR |= (PLL_MUL_VALUE << 18);	
	    RCC_CR   = 0x01010000 ;
/***************************************************************/

	#elif MRCC_CLOCK_TYPE == MRCC_PLL_HSE_RC
	    RCC_CFGR  = 0x04010002;
	    RCC_CFGR |= (PLL_MUL_VALUE << 18);	
	    RCC_CR   = 0x01050000 ;
/********************************************************************/
		
	#elif MRCC_CLOCK_TYPE == MRCC_PLL_HSE_CRYSTAL
	    RCC_CFGR  = 0x04010002;
	    RCC_CFGR |= (PLL_MUL_VALUE << 18);	
	    RCC_CR   = 0x01010000 ;
/*********************************************************************/
	#else 
			#error("You Chose wrong clock type")
	#endif
	
	
}
void MRCC_voidEnableClock(u8 copy_BusId , u8 copy_u8PerId)
{
	if(copy_u8PerId <=31)
	{
		switch (copy_BusId)
		{
			case MRCC_AHB   : SET_BIT(RCC_AHBENR  , copy_u8PerId) ; break ;
			case MRCC_APB1  : SET_BIT(RCC_APB1ENR , copy_u8PerId) ; break ;
			case MRCC_APB2  : SET_BIT(RCC_APB2ENR , copy_u8PerId) ; break ;
		}
	}
	else 
	{
		// error massege 
	}
	
}
void MRCC_voidDisableClock(u8 copy_BusId , u8 copy_u8PerId)
{
	if(copy_u8PerId <=31)
	{
		switch (copy_BusId)
		{
			case MRCC_AHB   : CLR_BIT(RCC_AHBENR  , copy_u8PerId) ; break ;
			case MRCC_APB1  : CLR_BIT(RCC_APB1ENR , copy_u8PerId) ; break ;
			case MRCC_APB2  : CLR_BIT(RCC_APB2ENR , copy_u8PerId) ; break ;
		}
	}
	else 
	{
		// error massege 
	}	
}