# ATmega32 Character LCD (CLCD) & Stick-Man Animation Driver

**Built using my already built drivers **[Amit-C-Embedded-D108-](https://github.com/adhamaglan/Amit-C-Embedded-D108-.git)** added new folder `CLCD Animation`** that contains various animation the user can manipulate

## Project Description
A C-based embedded application for AVR microcontrollers (ATmega32) that renders custom 5x8 pixel bitmapped animations on a 16x2 Character LCD configured in **4-bit mode**

## 🛠️ How to Build and Run

### Using Microchip Studio / Atmel Studio 7.0
1. **Clone this repository to your local computer:**
```bash
git clone https://github.com/adhamaglan/Amit-C-Embedded-D108-.git
```

2. **Launch Microchip Studio (Atmel Studio 7.0).**

3. **Select File > Open > Project/Solution... and open the project solution file (`.atsln`).**

4. **Build solution and burn the `.hex` file on your `ATmega32` chip**

## 📌 API Reference

### LCD Animation (`CLCD_ani_int.h`)
```c
void Animation_voidWave(u8 Copy_u8Waves,u8 Copy_u8x,u8 Copy_u8y);
// allows user to animate the stick-man waving at position (x,y) and control number of waves

void Animation_voidWalkAcross(u8 Copy_u8x,u8 Copy_u8y,u8 Copy_u8To_x);
// allows user to animate the stick-man walking horizontally from (x₁,y) to x₂ (can work if x₁ > x₂ for backward direction)

void Animation_voidPresent(const u8 *Copy_u8Str);
// allows user to display a stick-man presenting a custom string message

void Animation_voidDance1(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y);
// allows user to play dance 1 at position (x,y) and control number of dances

void Animation_voidDance2(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y);
// allows user to play dance 2 at position (x,y) and control number of dances

void Animation_voidDance3(u8 Copy_u8Dances,u8 Copy_u8x,u8 Copy_u8y);
// allows user to play dance 3 at position (x,y) and control number of dances

void Animation_voidPlayFootBall(u8 Copy_u8x,u8 Copy_u8y);
// allows user to play a football kicking animation (requires 4 custom characters)

void Animation_voidShootGun(u8 Copy_u8x,u8 Copy_u8y);
// allows user to play a gun shooting animation (requires 3 custom characters)

void CLCD_voidDefultAnimation(void);
// allows user to run the default animation showcase sequence
```
