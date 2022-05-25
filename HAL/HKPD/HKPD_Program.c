/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HKPD Driver                                                                     */
#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\MCAL\MDIO\MDIO_Interface.h"

#include"HKPD_Private.h"
#include"HKPD_Config.h"
#include"HKPD_Interface.h"
#define F_CPU 8000000UL
#include<util/delay.h>"

const u8 KPD_u8SwitchVal[4][4]=
{
		{
				'7',
				'4',
				'1',
				'O'
		},
		{
				'8',
				'5',
				'2',
				'0'
		},
		{
				'9',
				'6',
				'3',
				'='
		},
		{
				'/',
				'*',
				'-',
				'+'
		},
};
/*KPD INIT*/

void HKPD_VidInit(void)
{
	/* Set Row Pins as an Input */
	MDIO_Error_State_SetPinDirection(ROW_PIN0,ROW_PORT,PIN_INPUT);
	MDIO_Error_State_SetPinDirection(ROW_PIN1,ROW_PORT,PIN_INPUT);
	MDIO_Error_State_SetPinDirection(ROW_PIN2,ROW_PORT,PIN_INPUT);
	MDIO_Error_State_SetPinDirection(ROW_PIN3,ROW_PORT,PIN_INPUT);
	/* Set Column Pins as an Output */
	MDIO_Error_State_SetPinDirection(COL_PIN0,COL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(COL_PIN1,COL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(COL_PIN2,COL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(COL_PIN3,COL_PORT,PIN_OUTPUT);
	/* Active Pull Up Resistor For Row Pins */
	MDIO_Error_State_SetPinValue(ROW_PIN0,ROW_PORT,PIN_HIGH);
	MDIO_Error_State_SetPinValue(ROW_PIN1,ROW_PORT,PIN_HIGH);
	MDIO_Error_State_SetPinValue(ROW_PIN2,ROW_PORT,PIN_HIGH);
	MDIO_Error_State_SetPinValue(ROW_PIN3,ROW_PORT,PIN_HIGH);
	/* Initialize 4 Column Pins By Ones */
	MDIO_Error_State_SetPinValue(COL_PIN0,COL_PORT,PIN_HIGH);
	MDIO_Error_State_SetPinValue(COL_PIN1,COL_PORT,PIN_HIGH);
	MDIO_Error_State_SetPinValue(COL_PIN2,COL_PORT,PIN_HIGH);
	MDIO_Error_State_SetPinValue(COL_PIN3,COL_PORT,PIN_HIGH);

}
/*KPD Get Pressed*/
u8 HKPD_U8GetKeyPressed(void)
{
	u8 LOC_U8RowCount;
	u8 LOC_U8ColCount;
	/*Initialize the switch status to NOT PRESSED*/
	u8 LOC_U8ReturnValue=NOT_PRESSED;
	u8 LOC_U8PinState;

		/*Looping on columns of the keypad*/
		for(LOC_U8ColCount=COL_INIT;LOC_U8ColCount<COL_END;LOC_U8ColCount++)
		{
			/*Active the Column */
			MDIO_Error_State_SetPinValue(LOC_U8ColCount,COL_PORT,PIN_LOW);
			/*Loop to read the all row pins*/
			for(LOC_U8RowCount=ROW_INIT;LOC_U8RowCount<ROW_END;LOC_U8RowCount++)
			{
				/*check the status of the switch*/
				MDIO_Error_State_GetPinValue(LOC_U8RowCount,ROW_PORT,&LOC_U8PinState);
				if(LOC_U8PinState==0)
				{
					/*Get the Value of the current pressed switch*/
					LOC_U8ReturnValue=KPD_u8SwitchVal[LOC_U8ColCount-COL_INIT][LOC_U8RowCount-ROW_INIT];
					/*wait until the switch is released(Single Pressd)*/
					while(LOC_U8PinState==0)
					{
						MDIO_Error_State_GetPinValue(LOC_U8RowCount,ROW_PORT,&LOC_U8PinState);
					}
					/*Delay To avoid Bouncing*/
					_delay_ms(20);
				}
				else
				{
					/*Do Nothing*/
				}
			}
			/*Deactivate the Column*/
			MDIO_Error_State_SetPinValue(LOC_U8ColCount,COL_PORT,PIN_HIGH);
		}
	if(LOC_U8ReturnValue!=255)
		return LOC_U8ReturnValue;




}
