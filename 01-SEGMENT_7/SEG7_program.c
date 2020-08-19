/********************************/
/* Author : Layla sabry mohamed */ 
/*   DATE : 15 August 2020      */
/*  Descrption : 7 seg          */ 
/*   version : 01 V             */
/********************************/  

#include " STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#define COMM_ANODE 0
#define COMM_CATH  1



u32 Arr_DecToSeg[10] = {0x0000003F,        /*0b00111111,    0 */
                        0x00000006,        /*0b00000110,    1 */
                        0x0000005B,        /*0b01011011,    2 */
                        0x0000004F,        /*0b01001111,    3 */
                        0x00000066,        /*0b01100110,    4 */
                        0x0000006D,        /*0b01101101,    5 */
                        0x0000007D,        /*0b01111101,    6 */
                        0x00000007,        /*0b00000111,    7 */
                        0x0000007F,        /*0b01111111,    8 */
                        0x0000006F         /*0b01101111     9 */
					  };

void Seg7_voidInit(void)
{
	
}
					  
void Seg_7_DisplayNum(u8 copy_PORTId , u8 copy_SegType , u8 copy_NUM)
{
	switch (copy_SegType )
	{
		case COMM_ANODE :
						if (copy_NUM <= 9)
	                    {
	                    MGPIO_Set_PortValue(copy_PORTId, (0x0000 | Arr_DecToSeg[copy_NUM]);
	                    }
	                    else
	                    {
                        
	                    MGPIO_Set_PortValue(copy_PORTId , ((Arr_DecToSeg[copy_NUM/10] << 2 ) | (Arr_DecToSeg[copy_NUM % 10]) ));
	                    }
        break;	

		case COMM_CATH :
						if (copy_NUM <= 9)
	                    {
	                    MGPIO_Set_PortValue    (copy_PORTId, (~(0x0000 | Arr_DecToSeg[copy_NUM]));
	                    }
	                    else
	                    {
                        
	                    MGPIO_Set_PortValue    (copy_PORTId , (~(Arr_DecToSeg[copy_NUM/10] << 2 ) | (Arr_DecToSeg[copy_NUM % 10]) ));
	                    }
        break;		
	}

}					  
	

void Seg_7_Display(u8 copy_SegType )
{
	
}	