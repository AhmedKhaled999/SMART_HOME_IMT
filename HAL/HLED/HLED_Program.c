/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HLED Driver                                                                     */

#include"../../LIB/LSTD_TYPES.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include "HLED_Interface.h"





void HLED_VidInit(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber)
{
	MDIO_Error_State_SetPinDirection(Copy_u8LedPinNumber,Copy_u8LedPortNumber,PIN_OUTPUT);
}

void HLED_VidInit_On(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber)
{
	MDIO_Error_State_SetPinValue(Copy_u8LedPinNumber,Copy_u8LedPortNumber,PIN_HIGH);
}

void HLED_VidInit_Off(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber)
{
	MDIO_Error_State_SetPinValue(Copy_u8LedPinNumber,Copy_u8LedPortNumber,PIN_LOW);
}
void HLED_VidInit_Toggle(u8 Copy_u8LedPinNumber,u8 Copy_u8LedPortNumber)
{
       //  Fill This Function*"/"
}

//  ///by using struct
//  void HLED_VidInit(LED_t *Copy_Led)
//  {
//  	MDIO_Error_State_SetPinDirection(Copy_Led->Copy_u8_Pin,Copy_Led->Copy_u8Port,PIN_OUTPUT);
//  }
//
//  void HLED_VidLed_On(LED_t *Copy_Led)
//  {
//  	MDIO_Error_State_SetPinValue(Copy_Led->Copy_u8_Pin,Copy_Led->Copy_u8Port,PIN_HIGH);
//  }
//
//  void HLED_VidLed_Off(LED_t *Copy_Led)
//  {
//  	MDIO_Error_State_SetPinValue(Copy_Led->Copy_u8_Pin,Copy_Led->Copy_u8Port,PIN_LOW);
//  }
//  void HLED_VidLed_Toggle(LED_t *Copy_Led)
//  {
//  	          /*Fill This Function*/
//  	/*Toggle Function*/
//  	static u8 Flag=0;
//  	if(Flag==0)
//  	{
//  		MDIO_Error_State_SetPinValue(Copy_Led->Copy_u8_Pin,Copy_Led->Copy_u8Port,PIN_HIGH);
//  		Flag=1;
//  	}
//  	else
//  	{
//  		MDIO_Error_State_SetPinValue(Copy_Led->Copy_u8_Pin,Copy_Led->Copy_u8Port,PIN_LOW);
//  		Flag=0;
//  	}
//  }
//
//
