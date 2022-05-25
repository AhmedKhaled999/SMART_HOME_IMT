/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HKPD Driver                                                                     */


#ifndef HAL_HKPD_HKPD_INTERFACE_H_
#define HAL_HKPD_HKPD_INTERFACE_H_

#define NOT_PRESSED 255
/*KPD INIT*/
void HKPD_VidInit(void);
/*KPD Get Pressed*/
u8 HKPD_U8GetKeyPressed(void);

#endif /* HAL_HKPD_HKPD_INTERFACE_H_ */
