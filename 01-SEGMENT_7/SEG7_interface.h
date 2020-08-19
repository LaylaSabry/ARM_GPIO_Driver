/********************************/
/*Author : Layla sabry mohamed */
/*   DATE : 15 August 2020      */
/*  Descrption : 7 seg          */
/*   version : 01 V             */
/********************************/


#ifndef SEG7_INTERFACE_H
#define SEG7_INTERFACE_H

#define COMM_ANODE 0
#define COMM_CATH  1


#define SEG7_PORTA_RCC  2
#define SEG7_PORTB_RCC  3
#define SEG7_PORTC_RCC  4

#define PORTA  0
#define PORTB  1
#define PORTC  2









void Seg7_voidInit(void);
void Seg7_DisplayNum( u8 copy_NUM);


#endif
