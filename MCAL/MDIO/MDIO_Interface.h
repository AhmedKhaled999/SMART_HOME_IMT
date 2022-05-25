/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MDIO Driver                                                                     */
#ifndef MCAL_MDIO_MDIO_INTERFACE_H_
#define MCAL_MDIO_MDIO_INTERFACE_H_

#include"../../LIB/LSTD_TYPES.h"

/*Define ATMEGA32 Ports*/

#define MDIO_PORTA   0
#define MDIO_PORTB   1
#define MDIO_PORTC   2
#define MDIO_PORTD   3

/*Pin Direction Mode*/
#define PIN_OUTPUT   1
#define PIN_INPUT    0

/*Port Direction Mode*/
#define PORT_OUTPUT  255
#define PORT_INPUT   0

/*Pin Value State*/
#define PIN_HIGH     1
#define PIN_LOW      0


/*Port's Pins */
typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Pin_t;

/*Set Pin Direction Function */
Error_State  MDIO_Error_State_SetPinDirection(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8 Copy_u8PinDirection);
/*Set Port Direction Function */
Error_State  MDIO_Error_State_SetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8PortDirection);

/*Set Pin Value Function */
Error_State  MDIO_Error_State_SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8 Copy_u8PinValue);

/*Set Port Value Function */
Error_State  MDIO_Error_State_SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue);

/*Get Pin Value Function */
Error_State  MDIO_Error_State_GetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8*  P_u8PinValue);

/*Toggle Pin Value Function */

/*Active Pull Up Resistor Function */
void  MDIO_VidActivePullUP(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber);

/*Set Nipple Direction Function */

/*Set Nipple Values Function */
Error_State MDIO_Error_State_SetNippleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value);

#endif /* MCAL_MDIO_MDIO_INTERFACE_H_ */


