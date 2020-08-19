/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 13 August 2020      */ 
/*   version : 02 V             */
/********************************/  

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* RCC Adress base */

#define RCC_ADDRESS_BASE   0x40021000

/* Registers offset */

#define RCC_CR                 *((u32*)(RCC_ADDRESS_BASE+0x00))
#define RCC_CFGR               *((u32*)(RCC_ADDRESS_BASE+0x04))
#define RCC_CIR                *((u32*)(RCC_ADDRESS_BASE+0x08))
#define RCC_APB2RSTR           *((u32*)(RCC_ADDRESS_BASE+0x0C))
#define RCC_APB1RSTR           *((u32*)(RCC_ADDRESS_BASE+0x10))
#define RCC_AHBENR             *((u32*)(RCC_ADDRESS_BASE+0x14))
#define RCC_APB2ENR            *((u32*)(RCC_ADDRESS_BASE+0x18))
#define RCC_APB1ENR            *((u32*)(RCC_ADDRESS_BASE+0x1C))
#define RCC_BDCR               *((u32*)(RCC_ADDRESS_BASE+0x20))
#define RCC_CSR                *((u32*)(RCC_ADDRESS_BASE+0x24))


/**************************** CLK Type options *************/
#define               MRCC_HSI                        0 
#define               MRCC_HSE_CRYSTAL                1
#define               MRCC_HSE_RC                     2
#define               MRCC_PLL_HSI_DIV2               3
#define               MRCC_PLL_HSE_RC_DIV2            5
#define               MRCC_PLL_HSE_CRYSTAL_DIV2       6
#define               MRCC_PLL_HSE_RC                 7
#define               MRCC_PLL_HSE_CRYSTAL            8

/************************** PLL MULTPLICATION VALUES ***********************/

#define   PLL_MUL_X2            0         
#define   PLL_MUL_X3            1        
#define   PLL_MUL_X4            2         
#define   PLL_MUL_X5            3         
#define   PLL_MUL_X6            4        
#define   PLL_MUL_X7            5       
#define   PLL_MUL_X8            6      
#define   PLL_MUL_X9            7     
#define   PLL_MUL_X10           8     
#define   PLL_MUL_X11           9    
#define   PLL_MUL_X12           10   
#define   PLL_MUL_X1            11
#define   PLL_MUL_X14           12
#define   PLL_MUL_X15           13
#define   PLL_MUL_X16           14
           




#endif