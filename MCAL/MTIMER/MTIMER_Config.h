/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MTMR Driver                                                                     */

#ifndef MCAL_MTIMER_MTIMER_CONFIG_H_
#define MCAL_MTIMER_MTIMER_CONFIG_H_

/*Timer0 Prescaler Options
 * 0- TIMER_STOPPED
 * 1- TIMER_NO_PRESCALER
 * 2- TIMER_8_PRESCALER
 * 3- TIMER_64_PRESCALER
 * 4- TIMER_256_PRESCALER
 * 5- TIMER_1024_PRESCALER
 * 6- TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 7- TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
 * */

#define TIMER_SET_PRESCALER    			TIMER_64_PRESCALER


/*Timer0 Mode Options
 * 1- TIMER0_NORMAL_MODE
 * 2- TIMER0_CTC_MODE
 * 3- TIMER0_PHASECORRECT_PWM_MODE
 * 4- TIMER0_FAST_PWM_MODE
 * */
#define  TIMER0_SET_MODE       			TIMER0_PHASECORRECT_PWM_MODE

/*Timer0 CTC Interrupt Options:
 * 1- TIMER0_CTC_INTERRUPT_ENABLED
 * 2- TIMER0_CTC_INTERRUPT_DISABLED*/
#define  TIMER0_SET_CTC_INTERRUPT 		TIMER0_CTC_INTERRUPT_DISABLED

/*Timer0 CTC OC0 PIN Options:
 * 1- TIMER0_OC0_PIN_DISCONNECTED
 * 2- TIMER0_OC0_PIN_TOGGLE
 * 3- TIMER0_OC0_PIN_SET
 * 4- TIMER0_OC0_PIN_CLR*/

#define TIMER0_SET_OC0_PIN_MODE  		TIMER0_OC0_PIN_DISCONNECTED


/*Timer0 PWM Mode Options
 * 1- TIMER0_NON_INVERTING_PWM
 * 2- TIMER0_INVERTING_PWM
 * */

#define   TIMER0_SET_PWM_MODE            TIMER0_NON_INVERTING_PWM

/***********************************************************************TIMER1*********************************************************************/
/*Timer1 Prescaler Options
 * 0- TIMER1_STOPPED
 * 1- TIMER1_NO_PRESCALER
 * 2- TIMER1_8_PRESCALER
 * 3- TIMER1_64_PRESCALER
 * 4- TIMER1_256_PRESCALER
 * 5- TIMER1_1024_PRESCALER
 * 6- TIMER1_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 7- TIMER1_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
 * */
#define TIMER1_SET_PRESCALER    			TIMER1_NO_PRESCALER

/*Timer1 Mode Options
 * 1- TIMER1_NORMAL_MODE
 * 2- TIMER1_ICU_MODE
 * */

#define TIMER1_SET_MODE  TIMER1_ICU_MODE

/*ICU Edge Selection Options:
 * 1- TIMER1_ICU_RISING_EDGE
 * 2- TIMER1_ICU_FALING_EDGE
 *  */

#define TIMER1_ICU_EDGE_SELECT  TIMER1_ICU_RISING_EDGE

#endif /* MCAL_MTIMER_MTIMER_CONFIG_H_ */
