/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MDIO Driver                                                                     */

#ifndef MCAL_MDIO_MDIO_PRIVATE_H_
#define MCAL_MDIO_MDIO_PRIVATE_H_

/*Local defines*/
/*Note: volatile because change it by Hardware*/

/*PORTA Registers*/

#define DDRA  *((volatile u8*) 0x3A)
#define PORTA *((volatile u8*) 0x3B)
#define PINA  *((volatile u8*) 0x39)   //because change it by Hardware

/*PORTB Registers*/
#define DDRB  *((volatile u8*) 0x37)
#define PORTB *((volatile u8*) 0x38)
#define PINB  *((volatile u8*) 0x36)

/*PORTC Registers*/
#define DDRC  *((volatile u8*) 0x34)
#define PORTC *((volatile u8*) 0x35)
#define PINC  *((volatile u8*) 0x33)

/*PORTD Registers*/
#define DDRD  *((volatile u8*) 0x31)
#define PORTD *((volatile u8*) 0x32)
#define PIND  *((volatile u8*) 0x30)

#endif /* MCAL_MDIO_MDIO_PRIVATE_H_ */
