/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MTMR Driver                                                                     */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_

/*************TIMER0*********************/
#define TCCR0     *((volatile u8*)0x53)
#define TIMSK     *((volatile u8*)0x59)
#define TCNT0     *((volatile u8*)0x52)
#define OCR0      *((volatile u8*)0x5C)

/****************TIMER1****************/
#define TCCR1A     *((volatile u8*)0x4F)
#define TCCR1B     *((volatile u8*)0x4E)
#define ICR1       *((volatile u16*)0x46)
#define OCR1A      *((volatile u16*)0x4A)


#define TCNT1      *((volatile u16*)0x4C)
//#define TIMSK      *((volatile u16*)0x59)


/*Timer0 Prescaler Options */

#define TIMER_STOPPED                                    0
#define TIMER_NO_PRESCALER                               1
#define TIMER_8_PRESCALER                                2
#define TIMER_64_PRESCALER                               3
#define TIMER_256_PRESCALER                              4
#define TIMER_1024_PRESCALER                             5
#define TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE         6
#define TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE          7


/*Timer0 Mode options*/

#define TIMER0_NORMAL_MODE                                1
#define TIMER0_CTC_MODE                                   2
#define TIMER0_PHASECORRECT_PWM_MODE                      3
#define TIMER0_FAST_PWM_MODE                              4


/*Timer0 CTC Interrupt Options*/

#define TIMER0_CTC_INTERRUPT_ENABLED                      0
#define TIMER0_CTC_INTERRUPT_DISABLED                     1

/*Timer0 CTC OC0 PIN Options*/

#define TIMER0_OC0_PIN_DISCONNECTED                       0
#define TIMER0_OC0_PIN_TOGGLE							  1
#define TIMER0_OC0_PIN_SET								  2
#define TIMER0_OC0_PIN_CLR							      3

#define TIMER0_NON_INVERTING_PWM						  1
#define TIMER0_INVERTING_PWM                              0


/********************************************************************TIMER1*********************************************************************************/
/*Timer0 Prescaler Options */

#define TIMER1_STOPPED                                    0
#define TIMER1_NO_PRESCALER                               1
#define TIMER1_8_PRESCALER                                2
#define TIMER1_64_PRESCALER                               3
#define TIMER1_256_PRESCALER                              4
#define TIMER1_1024_PRESCALER                             5
#define TIMER1_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE         6
#define TIMER1_EXTERNAL_CLOCK_SOURCE_RISING_EDGE          7


/*Timer1 Mode options*/
#define TIMER1_NORMAL_MODE                                1
#define TIMER1_ICU_MODE                                   2

/*ICU Edge Selection Options:
 * 1- TIMER1_ICU_RISING_EDGE
 * 2- TIMER1_ICU_FALING_EDGE
 *  */

#define TIMER1_ICU_RISING_EDGE                            1
#define TIMER1_ICU_FALING_EDGE                            2

#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
