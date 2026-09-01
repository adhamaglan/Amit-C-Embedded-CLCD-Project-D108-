/*
 * D108.c
 *
 * Created: 8/15/2026 6:57:42 PM
 * Author : adham
 */ 
#define F_CPU 16000000ul


#include "service/std_types.h"
#include "service/bit_math.h"
#include "MCAL/regdef.h"
#include "MCAL/DIO/dio.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/CLCD/CLCD Animation/CLCD_ani_int.h"
#include <util/delay.h>


int main(void)
{
	CLCD_voidInit();
	CLCD_voidDefultAnimation();
    while (1) 
    {
	}
}
