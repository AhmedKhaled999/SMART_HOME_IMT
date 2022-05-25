/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HLCD Driver                                                                     */

#ifndef HAL_HCLCD_HCLCD_CONFIG_H_
#define HAL_HCLCD_HCLCD_CONFIG_H_


/*Configure RS,RW,E pin --> (PIN0 TO PIN7)*/
#define RS PIN0
#define RW PIN1
#define E  PIN2

/*Configure CONTROL_PORT --> (MDIO_PORTA,MDIO_PORTB,DIO_PORTC,MDIO_PORTD)*/

#define CONTROL_PORT  MDIO_PORTC


/*Configure DATA_PORT --> (MDIO_PORTA,MDIO_PORTB,DIO_PORTC,MDIO_PORTD)*/

#define DATA_PORT     MDIO_PORTC

#define HCLCD_PINSTART  PIN4
#define HCLCD_PINEND    PIN7

/*Configure Function set options:
 * 1- FUNCTION_SET_8BITS_2LINES
 * 2- FUNCTION_SET_8BITS_1LINES
 * 3- FUNCTION_SET_4BITS_2LINES
 * 4- FUNCTION_SET_4BITS_1LINES
 * */
#define HCLCD_FUNCTION_SET  FUNCTION_SET_4BITS_2LINES

/*Configure DISPLAY_ON_OFF options:
 * 1- DISPLAY_ON_CURSOR_ON_BLINKING_ON
 * 2- DISPLAY_ON_CURSOR_ON_BLINKING_OFF
 * 3- DISPLAY_ON_CURSOR_OFF
 * 4- DISPLAY_OFF
 * */
#define HCLCD_DISPLAY_ON_OFF  DISPLAY_ON_CURSOR_OFF

/*Configure ENTRY_MODE_SET options:
 * 1- ENTRY_MODE_SET_INCEREASE_WITH_SHIFT
 * 2- ENTRY_MODE_SET_INCEREASE
 * 3- ENTRY_MODE_SET_DECEREASE_WITH_SHIFT
 * 4- ENTRY_MODE_SET_DECEREASE
 * */

#define HCLCD_ENTRY_MODE_SET  ENTRY_MODE_SET_INCEREASE

#endif /* HAL_HCLCD_HCLCD_CONFIG_H_ */
