/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HLED Driver                                                                     */

#ifndef HAL_HLED_HLED_INTERFACE_H_
#define HAL_HLED_HLED_INTERFACE_H_

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define HLED_PORTA   0
#define HLED_PORTB   1
#define HLED_PORTC   2
#define HLED_PORTD   3

/* RED LED */
#define RED_LED_PIN    PIN2
#define RED_LED_PORT   HLED_PORTA

/* GREEN LED */
#define GREEN_LED_PIN    PIN3
#define GREEN_LED_PORT   HLED_PORTA



// typedef struct{
//
// 	u8 Copy_u8Port;
// 	u8 Copy_u8_Pin;
// }LED_t;
//
//
// void HLED_VidInit(LED_t *Copy_Led);
// void HLED_VidLed_On(LED_t *Copy_Led);
// void HLED_VidLed_Off(LED_t *Copy_Led);
// void HLED_VidLed_Toggle(LED_t *Copy_Led);


void HLED_VidInit(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber);
void HLED_VidLed_On(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber);
void HLED_VidLed_Off(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber);
void HLED_VidLed_Toggle(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber);

#endif /* HAL_HLED_HLED_INTERFACE_H_ */
