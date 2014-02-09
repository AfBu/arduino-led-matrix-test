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

/* Registers */
#define REG_DATA 11
#define REG_LATCH 12
#define REG_CLOCK 13
