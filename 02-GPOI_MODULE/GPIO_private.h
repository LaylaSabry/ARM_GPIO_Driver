/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 13 August 2020      */ 
/*   version : 02 V             */
/********************************/  


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/**************************************************************************************/

#define GPIOA_Base_Address        0x40010800            // define the boundary address of GPIO port A
#define GPIOB_Base_Address        0x40010C00            // define the boundary address of GPIO port B
#define GPIOC_Base_Address        0x40011000            // define the boundary address of GPIO port C

/*-------------------------- REGISTERS DEFINITION FOR GPIOA --------------------------*/

#define GPIOA_CRL      *((volatile u32*)(GPIOA_Base_Address + 0x00))
#define GPIOA_CRH      *((volatile u32*)(GPIOA_Base_Address + 0x04))
#define GPIOA_IDR      *((volatile u32*)(GPIOA_Base_Address + 0x08))
#define GPIOA_ODR      *((volatile u32*)(GPIOA_Base_Address + 0x0c))
#define GPIOA_BSRR      *((volatile u32*)(GPIOA_Base_Address + 0x10))
#define GPIOA_BRR      *((volatile u32*)(GPIOA_Base_Address + 0x14))
#define GPIOA_LCK      *((volatile u32*)(GPIOA_Base_Address + 0x18))

/**************************************************************************************/

/*-------------------------- REGISTERS DEFINITION FOR GPIOB --------------------------*/
#define GPIOB_CRL      *((volatile u32*)(GPIOB_Base_Address + 0x00))
#define GPIOB_CRH      *((volatile u32*)(GPIOB_Base_Address + 0x04))
#define GPIOB_IDR      *((volatile u32*)(GPIOB_Base_Address + 0x08))
#define GPIOB_ODR      *((volatile u32*)(GPIOB_Base_Address + 0x0c))
#define GPIOB_BSRR      *((volatile u32*)(GPIOB_Base_Address + 0x10))
#define GPIOB_BRR      *((volatile u32*)(GPIOB_Base_Address + 0x14))
#define GPIOB_LCK      *((volatile u32*)(GPIOB_Base_Address + 0x18))

/**************************************************************************************/

/*-------------------------- REGISTERS DEFINITION FOR GPIOA --------------------------*/

#define GPIOC_CRL      *((volatile u32*)(GPIOC_Base_Address + 0x00))
#define GPIOC_CRH      *((volatile u32*)(GPIOC_Base_Address + 0x04))
#define GPIOC_IDR      *((volatile u32*)(GPIOC_Base_Address + 0x08))
#define GPIOC_ODR      *((volatile u32*)(GPIOC_Base_Address + 0x0c))
#define GPIOC_BSRR      *((volatile u32*)(GPIOC_Base_Address + 0x10))
#define GPIOC_BRR      *((volatile u32*)(GPIOC_Base_Address + 0x14))
#define GPIOC_LCK      *((volatile u32*)(GPIOC_Base_Address + 0x18))

/**************************************************************************************/


#endif /* GPIO_PRIVATE_H_ */