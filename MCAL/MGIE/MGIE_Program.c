/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MGIE Driver                                                                     */

#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\LIB\LBIT_MATH.h"

#include"MGIE_Private.h"

/*GIE Enable Function*/
void MGIE_VidEnable(void)
{
	SET_BIT(SREG,7);
}
/*GIE Disable Function*/
void MGIE_VidDisable(void)
{
	CLR_BIT(SREG,7);
}

