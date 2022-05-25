/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HLCD Driver                                                                     */

#ifndef HAL_HCLCD_HCLCD_PRIVATE_H_
#define HAL_HCLCD_HCLCD_PRIVATE_H_

/*Function Set Modes*/
#define  FUNCTION_SET_8BITS_2LINES           0b00111000
#define  FUNCTION_SET_8BITS_1LINES           0b00110100
#define  FUNCTION_SET_4BITS_2LINES           0b00101000
#define  FUNCTION_SET_4BITS_1LINES           0b00100100


/*Display Modes*/

#define DISPLAY_ON_CURSOR_ON_BLINKING_ON     0b00001111
#define DISPLAY_ON_CURSOR_ON_BLINKING_OFF    0b00001110
#define DISPLAY_ON_CURSOR_OFF                0b00001100
#define DISPLAY_OFF                          0b00001000

/* Display Clear*/
#define DISPLAY_CLEAR     0b00000001


/*Entry Mode*/
#define ENTRY_MODE_SET_INCEREASE_WITH_SHIFT     0b00000111
#define ENTRY_MODE_SET_INCEREASE				0b00000110
#define ENTRY_MODE_SET_DECEREASE_WITH_SHIFT		0b00000101
#define ENTRY_MODE_SET_DECEREASE				0b00000100

/**/
#define DISPLAY_SHIFT_LEFT      0x18
#define DISPLAY_SHIFT_RIGHT     0x1C
#define CURSOR_SHIFT_LEFT       0b00010000
#define CURSOR_SHIFT_RIGHT      0b00010100
/**/

#define LINE1_OFFSET_ADDRESS    128
#define LINE2_OFFSET_ADDRESS    192

#define CGRAM_OFFSET            64
#define PATTERN_MAX_NUMBER       8
#define PATTERN_SIZE             8
#endif /* HAL_HCLCD_HCLCD_PRIVATE_H_ */
