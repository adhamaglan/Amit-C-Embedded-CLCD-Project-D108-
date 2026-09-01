/*
 * CLCD_ani_prog.c
 *
 * Created: 9/1/2026 6:53:11 AM
 *  Author: adham
 */ 

#define F_CPU 16000000ul

#include "../../../service/std_types.h"
#include "../../../service/bit_math.h"
#include "../../../MCAL/DIO/dio.h"
#include "../CLCD_priv.h"
#include "../CLCD_config.h"
#include "../CLCD_int.h"
#include "CLCD_bitmaps_config.h"
#include "CLCD_ani_int.h"
#include <util/delay.h>



void Animation_voidWave(u8 Copy_u8Waves,u8 Copy_u8x,u8 Copy_u8y)
{
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	u8 Local_u8Count;
	for(Local_u8Count=0;Local_u8Count<Copy_u8Waves;Local_u8Count++)
	{
		CLCD_voidSendSpecialChar(0,stickmanWaveFrame0,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(1,stickmanWaveFrame1,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(0,stickmanWaveFrame0,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(2,stickmanWaveFrame2,Copy_u8x,Copy_u8y);
		_delay_ms(7);
	}
	// Clear current frame
	CLCD_voidSendData(' ');
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
}



void Animation_voidWalkAcross(u8 Copy_u8x,u8 Copy_u8y,u8 Copy_u8To_x)
{
	u8 Local_u8Xi=Copy_u8x;
	u8 Local_u8Xf=Copy_u8To_x;
	if(Local_u8Xi<Local_u8Xf)
	{
		for (;Local_u8Xi<=Local_u8Xf;Local_u8Xi++)
		{
			// Alternate between frame 0 and frame 1 on odd/even columns
			if (Local_u8Xi%2==0)
			{
				// Over-writing index '0' in CLCD_voidSendSpecialChar to save CGRAM
				CLCD_voidSendSpecialChar(0,stickmanWalkFrame0,Local_u8Xi,Copy_u8y);
			}
			else
			{
				// Over-writing index '1' in CLCD_voidSendSpecialChar to save CGRAM
				CLCD_voidSendSpecialChar(1,stickmanWalkFrame1,Local_u8Xi,Copy_u8y);
			}
			_delay_ms(200);
			// Clear current frame before shifting to next position
			CLCD_voidSetCursorPos(Local_u8Xi,Copy_u8y);
			CLCD_voidSendData(' ');
			// reset cursor position
			CLCD_voidSetCursorPos(0,0);
		}
	}else if(Local_u8Xi>Local_u8Xf)
	{
		for (;Local_u8Xi>=Local_u8Xf;Local_u8Xi--)
		{
			// Alternate between frame 0 and frame 1 on odd/even columns
			if (Local_u8Xi%2==0)
			{
				// Over-writing index '0' in CLCD_voidSendSpecialChar to save CGRAM
				CLCD_voidSendSpecialChar(0,stickmanWalkFrame0,Local_u8Xi,Copy_u8y);
			}
			else
			{
				// Over-writing index '1' in CLCD_voidSendSpecialChar to save CGRAM
				CLCD_voidSendSpecialChar(1,stickmanWalkFrame1,Local_u8Xi,Copy_u8y);
			}
			_delay_ms(200);
			// Clear current frame before shifting to next position
			CLCD_voidSetCursorPos(Local_u8Xi,Copy_u8y);
			CLCD_voidSendData(' ');
			// reset cursor position
			CLCD_voidSetCursorPos(0,0);
		}
	}else
	{
		// error
	}
}



void Animation_voidPresent(const u8 *Copy_u8Str)
{
	CLCD_voidSendSpecialChar(1,stickmanPresenting,15,1);
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
	CLCD_voidSendString((u8*)Copy_u8Str);
}



void Animation_voidDance1(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y)
{
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendSpecialChar(0,stickmanDance1Frame0,Copy_u8x,Copy_u8y);
	_delay_ms(7);
	CLCD_voidSendSpecialChar(1,stickmanDance1Frame1,Copy_u8x,Copy_u8y);
	_delay_ms(7);
	u8 Local_u8Count;
	for(Local_u8Count=0;Local_u8Count<Copy_u8Dances;Local_u8Count++)
	{
		CLCD_voidSendSpecialChar(2,stickmanDance1Frame2,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(3,stickmanDance1Frame3,Copy_u8x,Copy_u8y);
		_delay_ms(7);
	}
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
}



void Animation_voidDance2(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y)
{
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	u8 Local_u8Count;
	for(Local_u8Count=0;Local_u8Count<Copy_u8Dances;Local_u8Count++)
	{
		CLCD_voidSendSpecialChar(0,stickmanDance2Frame0,Copy_u8x,Copy_u8y);
		_delay_ms(5);
		CLCD_voidSendSpecialChar(1,stickmanDance2Frame1,Copy_u8x,Copy_u8y);
		_delay_ms(5);
		CLCD_voidSendSpecialChar(2,stickmanDance2Frame2,Copy_u8x,Copy_u8y);
		_delay_ms(5);
		CLCD_voidSendSpecialChar(3,stickmanDance2Frame3,Copy_u8x,Copy_u8y);
		_delay_ms(5);
		CLCD_voidSendSpecialChar(2,stickmanDance2Frame2,Copy_u8x,Copy_u8y);
		_delay_ms(5);
		CLCD_voidSendSpecialChar(1,stickmanDance2Frame1,Copy_u8x,Copy_u8y);
		_delay_ms(5);
		
	}
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
}



void Animation_voidDance3(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y)
{
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	u8 Local_u8Count;
	for(Local_u8Count=0;Local_u8Count<Copy_u8Dances;Local_u8Count++)
	{
		CLCD_voidSendSpecialChar(0,stickmanDance3Frame0,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(1,stickmanDance3Frame1,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(2,stickmanDance3Frame2,Copy_u8x,Copy_u8y);
		_delay_ms(7);
		CLCD_voidSendSpecialChar(0,stickmanDance3Frame0,Copy_u8x,Copy_u8y);
		_delay_ms(7);
	}
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
}



void Animation_voidPlayFootBall(u8 Copy_u8x,u8 Copy_u8y)
{
	CLCD_voidSendSpecialChar(0,goalpost,Copy_u8x-3,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(1,stickmanPlayFootballFrame0,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(1,stickmanPlayFootballFrame1,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	Copy_u8x--;
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendSpecialChar(2,ballMovingUpFrame0,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(1,stickmanPlayFootballFrame2,Copy_u8x+1,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingUpFrame1,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingUpFrame2,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingUpFrame3,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingUpFrame4,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	// Clear current frame before shifting to next position
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendData(' ');
	Copy_u8x--;
	CLCD_voidSendSpecialChar(2,ballMovingDownFrame0,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingDownFrame1,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingDownFrame2,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingDownFrame3,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,ballMovingDownFrame4,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	// Clear current frame before shifting to next position
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendData(' ');
	Copy_u8x--;
	CLCD_voidSendSpecialChar(0,goalFrame0,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(0,goalFrame1,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(0,goalFrame2,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(0,goalFrame3,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
}



void Animation_voidShootGun(u8 Copy_u8x,u8 Copy_u8y)
{
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendSpecialChar(0,ShootGunFrame0,Copy_u8x,Copy_u8y);
	CLCD_voidSendSpecialChar(1,Target,Copy_u8x+2,Copy_u8y);
	_delay_ms(5);
	Copy_u8x++;
	CLCD_voidSendSpecialChar(2,Flash,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(0,ShootGunFrame1,Copy_u8x-1,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,BulletMovingFrame0,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,BulletMovingFrame1,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(2,BulletMovingFrame2,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	// Clear current frame before shifting to next position
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendData(' ');
	Copy_u8x++;
	CLCD_voidSendSpecialChar(1,BulletHittingTargetFrame0,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(1,BulletHittingTargetFrame1,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(1,BulletHittingTargetFrame2,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSendSpecialChar(1,BulletHittingTargetFrame3,Copy_u8x,Copy_u8y);
	_delay_ms(5);
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	// Clear target frame before shifting to next position
	CLCD_voidSetCursorPos(Copy_u8x,Copy_u8y);
	CLCD_voidSendData(' ');
	// reset cursor position
	CLCD_voidSetCursorPos(0,0);
}