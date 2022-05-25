/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MTMR Driver                                                                     */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_


#define  MTIMER1_ICU_FALLING_EDGE             0
#define  MTIMER1_ICU_RISING_EDGE              1


/*Timer0 Initialization*/
void MTIMER0_VidInit(void);
/*Set Preload Function*/
void MTIMER0_VidSetPreload(u8 Copy_u8Preload);
/*Set CTC Value Function*/
void MTIMER0_VidSetCTCValue(u8 Copy_u8CTCValue);
void MTIMER0_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));
void MTIMER0_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void));

/***************************************************TIMER1************************************************************/
/*Timer1 Initialization*/
void MTIMER1_VidInit(void);
/*Set Preload Function*/
void MTIMER1_VidSetPreload(u16 Copy_u16Preload);
/*Get Counter Value In Timer1*/
u16 MTIMER1_u16GetTCNT1Value(void);
/*Get Counter Value In ICR1  */
u16 MTIMER1_u16GetICR1Value(void);
/*Set Sense Control*/
void MTIMER1_VidSenseControl(u8 Copy_u8SenseControl);

void MTIMER1_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));
void MTIMER1_VidICF_SetCallBack(void(*Copy_VidCallBack)(void));

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
