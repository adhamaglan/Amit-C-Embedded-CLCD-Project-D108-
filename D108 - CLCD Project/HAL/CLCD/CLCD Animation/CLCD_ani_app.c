/*
 * CLCD_ani_app.c
 *
 * Created: 9/1/2026 6:53:28 AM
 *  Author: adham
 */ 

#define F_CPU 16000000ul

#include "../../../service/std_types.h"
#include "../../../service/bit_math.h"
#include "../../../MCAL/DIO/dio.h"
#include "../CLCD_int.h"
#include "CLCD_ani_int.h"
#include <util/delay.h>

void CLCD_voidDefultAnimation(void)
{
	Animation_voidWave(4,0,0);
	Animation_voidWalkAcross(0,0,15);
	Animation_voidWalkAcross(0,1,15);
	Animation_voidPresent("Hello, This is\nme : Stick-man");
	_delay_ms(1000);
	Animation_voidPresent("I can dance   \n              ");
	Animation_voidDance1(3,15,1);
	Animation_voidDance2(3,15,1);
	Animation_voidDance3(3,15,1);
	Animation_voidPresent("I can Play    \nFootball      ");
	Animation_voidPlayFootBall(15,1);
	Animation_voidPresent("I can Shoot   \na gun         ");
	Animation_voidWalkAcross(15,1,7);
	Animation_voidShootGun(7,1);
	Animation_voidWalkAcross(7,1,15);
	Animation_voidPresent("That's all    \n              ");
	_delay_ms(500);
	Animation_voidPresent("Thanks for    \nyour time     ");
	_delay_ms(500);
	CLCD_voidClearScreen();
	CLCD_voidSendString  ("Animation by, \nAdham Younis  ");
}