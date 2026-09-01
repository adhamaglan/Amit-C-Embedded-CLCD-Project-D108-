/*
 * CLCD_ani_int.h
 *
 * Created: 9/1/2026 6:51:48 AM
 *  Author: adham
 */ 


#ifndef CLCD_ANI_INT_H_
#define CLCD_ANI_INT_H_



void Animation_voidWave(u8 Copy_u8Waves,u8 Copy_u8x,u8 Copy_u8y);
void Animation_voidWalkAcross(u8 Copy_u8x,u8 Copy_u8y,u8 Copy_u8To_x);
void Animation_voidPresent(const u8 *Copy_u8Str);
void Animation_voidDance1(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y);
void Animation_voidDance2(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y);
void Animation_voidDance3(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y);
void Animation_voidPlayFootBall(u8 Copy_u8x,u8 Copy_u8y);	// needs 2 empty spots
void CLCD_voidDefultAnimation(void);



#endif /* CLCD_ANI_INT_H_ */