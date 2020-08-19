/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 13 August 2020      */ 
/*   version : 02 V             */
/********************************/  

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define  MRCC_AHB   0
#define  MRCC_APB1  1
#define  MRCC_APB2  2

#define MRCC_PORTA  2
#define MRCC_PORTB  3
#define MRCC_PORTC  4






void MRCC_voidInitSysClock (void);
void MRCC_voidEnableClock(u8 , u8);
void MRCC_voidDisableClock(u8 , u8);


#endif   