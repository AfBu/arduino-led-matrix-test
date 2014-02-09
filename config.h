/* MATRIX */

/*
1st byte:

1 - 3V
2 - 6V
4 - 5H
8 - 8V
16 - 3H
32 - 2H
64 - 7V
128 - 5V

2nd byte:

1 - 8H
2 - 7H
4 - 2V
8 - 1H
16 - 4V
32 - 6H
64 - 4H
128 - 1V
*/

/* DISPLAY */

#define LCD_RS 9
#define LCD_ENABLE 8
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2
#define LCD_ROWS 2
#define LCD_COLS 16

/* SOUND */
#define SOUND_PIN 10
#define SOUND_ENABLED true

/* NES Controller */
#define NES_LATCH A1
#define NES_CLOCK A2
#define NES_SERIAL A0

/* Registers */
#define REG_DATA 11
#define REG_LATCH 12
#define REG_CLOCK 13
