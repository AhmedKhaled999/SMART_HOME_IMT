/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HLCD Driver                                                                     */

#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\MCAL\MDIO\MDIO_Interface.h"

#include"HCLCD_Private.h"
#include"HCLCD_Config.h"
#include"HCLCD_Interface.h"

#include"util/delay.h"


/*Send Command 8 Bits*/

void HCLCD_Vid8Bits_SendCommand(u8 Copy_u8Command)
{
	/*Select command register-->Write zero on RS Pin*/
	MDIO_Error_State_SetPinValue(RS,CONTROL_PORT,PIN_LOW);
	/**select Write mode--> Write zero on RW Pin*/
	MDIO_Error_State_SetPinValue(RW,CONTROL_PORT,PIN_LOW);
	/*Send Command ON port Data*/
	MDIO_Error_State_SetPortValue(DATA_PORT,Copy_u8Command);
	/*Send Enable*/
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_LOW);
	_delay_ms(2);
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
}

/*LCD 8 Bits Initialization*/
void HCLCD_Vid8Bits_Init(void)
{
	/*LCD Data and Control Port Initialization*/
	MDIO_Error_State_SetPortDirection(DATA_PORT,PORT_OUTPUT);
	MDIO_Error_State_SetPinDirection(RS,CONTROL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(RW,CONTROL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(E,CONTROL_PORT,PIN_OUTPUT);
	/*wait to 30 ms*/
	_delay_ms(30);
	/*Send function Send Command*/
	HCLCD_Vid8Bits_SendCommand(HCLCD_FUNCTION_SET);
	/*wait to 30 ms*/
	_delay_ms(1);
	/*Send  Display on/off Command*/
	HCLCD_Vid8Bits_SendCommand(HCLCD_DISPLAY_ON_OFF);
	_delay_ms(1);
	/*Send Display Clear Command*/
	HCLCD_Vid8Bits_SendCommand(HCLCD_DISPLAY_CLEAR);
	_delay_ms(2);
	/*Send Entry Mode Set Command*/
	HCLCD_Vid8Bits_SendCommand(HCLCD_ENTRY_MODE_SET);
}

/*Display Character 8 Bits*/

void HCLCD_Vid8Bits_DispalyCharacter(u8 Copy_u8Data)
{
	/*Select Data register-->Write one on RS PIN*/
	MDIO_Error_State_SetPinValue(RS,CONTROL_PORT,PIN_HIGH);
	/**select Write mode--> Write zero on RW Pin*/
	MDIO_Error_State_SetPinValue(RW,CONTROL_PORT,PIN_LOW);
	/*Send Command ON port Data*/
	MDIO_Error_State_SetPortValue(DATA_PORT,Copy_u8Data);
	/*Send Enable*/
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_LOW);
	_delay_ms(2);
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
}

/*Display String 8 Bits*/

void HCLCD_Vid8Bits_DisplayString(u8* PCopy_u8String)
{
	u8 Loc_u8Count=0;
	while(PCopy_u8String[Loc_u8Count]!=NULL)
	{
		HCLCD_Vid8Bits_DispalyCharacter(PCopy_u8String[Loc_u8Count]);
		Loc_u8Count++;
	}
}

void HCLCD_Vid8Bits_DisplayNumber(u32 Copy_u8Number)
{
	u8 ARR_Digits[10];
	u8 LOC_Count=0;
	if(Copy_u8Number>0)
	{
		while(Copy_u8Number!=0)
		{
			ARR_Digits[LOC_Count]=Copy_u8Number%10;
			Copy_u8Number/=10;
			LOC_Count++;
		}
		for(s8 i=LOC_Count-1;i>=0;i--)
		{
			HCLCD_Vid8Bits_DispalyCharacter(ARR_Digits[i]+'0');  //ASCII of '0'--->48
		}
	}
	else
	{
		HCLCD_Vid8Bits_DispalyCharacter('0');
	}
}

void HCLCD_Vid8Bits_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{

	if((Copy_u8LineNumber==HCLCD_LINE1)&&((Copy_u8PositionNumber>=0)&&(Copy_u8PositionNumber<16)))
	{
		HCLCD_Vid8Bits_SendCommand((LINE1_OFFSET_ADDRESS+Copy_u8PositionNumber));
	}
	else if((Copy_u8LineNumber==HCLCD_LINE2)&&((Copy_u8PositionNumber>=0)&&(Copy_u8PositionNumber<16)))
	{
		HCLCD_Vid8Bits_SendCommand((LINE2_OFFSET_ADDRESS+Copy_u8PositionNumber));
	}
	else
	{

	}

}
/*LCD Create SpecialCharacter 8 Bits*/
void HCLCD_Vid8Bits_CustomAlphChar(u8 Copy_u8PatternNumber, u8* PCopy_u8Pattern)
{
	       /*you have only 8 patterns to be customized */
	      u8 i;
	      if(Copy_u8PatternNumber<PATTERN_MAX_NUMBER)
	      {
	    	  /*Address counter point on CGRAM*/
	    	  HCLCD_Vid8Bits_SendCommand(CGRAM_OFFSET+(Copy_u8PatternNumber*PATTERN_SIZE));
	    	  /*Write your pattern in CGRAM*/
	          for(i=0;i<8;i++)
	          {
	        	  HCLCD_Vid8Bits_DispalyCharacter(PCopy_u8Pattern[ i ]);
	          }
	      }
}
/**/
void HCLCD_Vid8Bits_ClearScreen(void)
{
  HCLCD_Vid8Bits_SendCommand(DISPLAY_CLEAR);
  _delay_ms(2);
}
/**/
 void HCLCD_Vid8Bits_DisplayShiftLeft(u8 Copy_ShiftNumber)
{
	u8 i ;
 for(i=0 ; i<Copy_ShiftNumber ;i++)
 {
	 HCLCD_Vid8Bits_SendCommand(DISPLAY_SHIFT_LEFT);
  _delay_ms(300);
 }
}
/**/
 void HCLCD_Vid8Bits_DisplayShiftRight(u8 Copy_ShiftNumber)
{
	for(u8 i=0;i <Copy_ShiftNumber;i++)
	{
		HCLCD_Vid8Bits_SendCommand(DISPLAY_SHIFT_RIGHT);
      _delay_ms(300);
	}
}
 /**/
 void HCLCD_Vid8Bits_CursorShiftLeft(u8 Copy_ShiftNumber)
{
	u8 i ;
 for(i=0 ; i<Copy_ShiftNumber ;i++)
 {
	 HCLCD_Vid8Bits_SendCommand(CURSOR_SHIFT_LEFT);
  _delay_ms(300);
 }
}
/**/
 void HCLCD_Vid8Bits_CursorShiftRight(u8 Copy_ShiftNumber)
{
	for(u8 i=0;i <Copy_ShiftNumber;i++)
	{
		HCLCD_Vid8Bits_SendCommand(CURSOR_SHIFT_RIGHT);
      _delay_ms(300);
	}
}
/****************************************************************************************************************************************/

/*Send Command 4 Bits*/
void HCLCD_Vid4Bits_SendCommand(u8 Copy_u8Command )
{
	//u8 LOC_u8CopyCommand;
	/*select Command register--> Write zero on Rs pin*/
	MDIO_Error_State_SetPinValue(RS,CONTROL_PORT,PIN_LOW);
	/*select Write mode--> Write zero on RW pin*/
	MDIO_Error_State_SetPinValue(RW,CONTROL_PORT,PIN_LOW);
	/*Send  Command*/
	//LOC_u8CopyCommand=(Copy_u8Command&0x0F)<<HCLCD_PINSTART;
	MDIO_Error_State_SetNippleValue(HCLCD_PINSTART,DATA_PORT,Copy_u8Command);
	/*Send Enable*/
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_LOW);
}


/*LCD 4 Bits Initialization*/

void HCLCD_Vid4Bits_Init(void)
{
	/*Fill This Function*/
	s8 LOC_u8PinCount;
	/*LCD Data and control port initialization*/
	for(LOC_u8PinCount=HCLCD_PINEND;LOC_u8PinCount>=HCLCD_PINSTART;LOC_u8PinCount--)
	{
		MDIO_Error_State_SetPinDirection(LOC_u8PinCount,DATA_PORT,PIN_OUTPUT);
	}
	MDIO_Error_State_SetPinDirection(RS,CONTROL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(RW,CONTROL_PORT,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(E,CONTROL_PORT,PIN_OUTPUT);
	/*wait to 30ms*/
	_delay_ms(30);
	/*send function set command*/
	HCLCD_Vid4Bits_SendCommand(HCLCD_FUNCTION_SET>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_FUNCTION_SET>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_FUNCTION_SET);
	_delay_ms(1);
	/*send Display on/off  command*/
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_ON_OFF>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_DISPLAY_ON_OFF);
	_delay_ms(1);
	/*send Display Clear  command*/
	HCLCD_Vid4Bits_SendCommand(DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
	/*send Entry Mode  set command*/
	HCLCD_Vid4Bits_SendCommand(HCLCD_ENTRY_MODE_SET>>4);
	HCLCD_Vid4Bits_SendCommand(HCLCD_ENTRY_MODE_SET);
}


/*Helper function*/
void HCLCD_VidWriteChar_4Bits(u8 Copy_u8Data)
{
	//u8 LOC_u8CopyData;
	/*select Data register--> Write One on Rs pin*/
	MDIO_Error_State_SetPinValue(RS,CONTROL_PORT,PIN_HIGH);
	/*select Write mode--> Write zero on RW pin*/
	MDIO_Error_State_SetPinValue(RW,CONTROL_PORT,PIN_LOW);
	/*Send Data*/
	//LOC_u8CopyData=(Copy_u8Data&0x0F)<<HCLCD_PINSTART;
	MDIO_Error_State_SetNippleValue(HCLCD_PINSTART,DATA_PORT,Copy_u8Data);
	/*Send Enable*/
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	MDIO_Error_State_SetPinValue(E,CONTROL_PORT,PIN_LOW);
}
/*Display Character 4 Bits*/
void HCLCD_Vid4Bits_DisplayCharacter(u8 Copy_u8Data)
{
	HCLCD_VidWriteChar_4Bits(Copy_u8Data>>4);
	HCLCD_VidWriteChar_4Bits(Copy_u8Data);
}

/*Display String 4 Bits*/

void HCLCD_Vid4Bits_DisplayString(u8* PCopy_u8String)
{
	u8 Loc_u8Count=0;
	while(PCopy_u8String[Loc_u8Count]!=NULL)
	{
		HCLCD_Vid4Bits_DisplayCharacter(PCopy_u8String[Loc_u8Count]);
		Loc_u8Count++;
	}
}

void HCLCD_Vid4Bits_DisplayNumber(u32 Copy_u8Number)
{
	u8 ARR_Digits[10];
	u8 LOC_Count=0;
	if(Copy_u8Number>0)
	{
		while(Copy_u8Number!=0)
		{
			ARR_Digits[LOC_Count] = (Copy_u8Number%10);
			Copy_u8Number/=10;
			LOC_Count++;
		}
		for(s8 i=LOC_Count-1;i>=0;i--)
		{
			HCLCD_Vid4Bits_DisplayCharacter(ARR_Digits[i]+'0');
		}
	}
	else
	{
		HCLCD_Vid4Bits_DisplayCharacter('0');
	}

}


void HCLCD_Vid4Bits_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
	if((Copy_u8LineNumber==HCLCD_LINE1)&&((Copy_u8PositionNumber>=0)&&(Copy_u8PositionNumber<16)))
	{
		HCLCD_Vid4Bits_SendCommand((LINE1_OFFSET_ADDRESS+Copy_u8PositionNumber)>>4);
		HCLCD_Vid4Bits_SendCommand((LINE1_OFFSET_ADDRESS+Copy_u8PositionNumber));
	}
	else if((Copy_u8LineNumber==HCLCD_LINE2)&&((Copy_u8PositionNumber>=0)&&(Copy_u8PositionNumber<16)))
	{
		HCLCD_Vid4Bits_SendCommand((LINE2_OFFSET_ADDRESS+Copy_u8PositionNumber)>>4);
		HCLCD_Vid4Bits_SendCommand((LINE2_OFFSET_ADDRESS+Copy_u8PositionNumber));
	}
	else
	{
	}
}
/***************************************Another way**********************************************************/
/*LCD_VidGoToRowCol(u8 row ,u8 col)
 {
   u8 adress ;
   switch(row)
   {
   case 0 :
 	  adress = col;
 	  break ;
   case 1 :
   	  adress = col + 0x40;
   	  break ;

   case 2 :
   	  adress = col + 0x10;
   	  break ;
   case 3 :
   	  adress = col + 0x50;
   	  break ;

   default :
          {
         	 //invalid numbers
          }
   }
   HCLCD_Vid4Bits_SendCommand((adress|0x80)>>4);
   HCLCD_Vid4Bits_SendCommand((adress|0x80));

 }
*/

/*LCD Create SpecialCharacter 4 Bits*/
void HCLCD_Vid4Bits_CustomAlphChar(u8 Copy_u8PatternNumber, u8* PCopy_u8Pattern)
{
	       /*you have only 8 patterns to be customized */
	      u8 i;
	      if(Copy_u8PatternNumber<PATTERN_MAX_NUMBER)
	      {
	    	  /*Address counter point on CGRAM*/
	    	  HCLCD_Vid4Bits_SendCommand((CGRAM_OFFSET+(Copy_u8PatternNumber*PATTERN_SIZE))>>4);
	    	  HCLCD_Vid4Bits_SendCommand((CGRAM_OFFSET+(Copy_u8PatternNumber*PATTERN_SIZE)));

	    	  /*Write your pattern in CGRAM*/
	          for(i=0;i<8;i++)
	          {
	        	  HCLCD_Vid4Bits_DisplayCharacter(PCopy_u8Pattern[i]);
	          }
	      }
}
/**/
void HCLCD_Vid4Bits_ClearScreen(void)
{
	HCLCD_Vid4Bits_SendCommand(DISPLAY_CLEAR>>4);
	HCLCD_Vid4Bits_SendCommand(DISPLAY_CLEAR);
  _delay_ms(2);
}
/**/
 void HCLCD_Vid4Bits_DisplayShiftLeft(u8 Copy_ShiftNumber)
{
	u8 i ;
 for(i=0 ; i<Copy_ShiftNumber ;i++)
 {
	 HCLCD_Vid4Bits_SendCommand(DISPLAY_SHIFT_LEFT>>4);
	 HCLCD_Vid4Bits_SendCommand(DISPLAY_SHIFT_LEFT);

  _delay_ms(300);
 }
}
/**/
 void HCLCD_Vid4Bits_DisplayShiftRight(u8 Copy_ShiftNumber)
{
	for(u8 i=0;i <Copy_ShiftNumber;i++)
	{
		HCLCD_Vid4Bits_SendCommand(DISPLAY_SHIFT_RIGHT>>4);
		HCLCD_Vid4Bits_SendCommand(DISPLAY_SHIFT_RIGHT);

      _delay_ms(300);
	}
}
 /**/
 void HCLCD_Vid4Bits_CursorShiftLeft(u8 Copy_ShiftNumber)
{
	u8 i ;
 for(i=0 ; i<Copy_ShiftNumber ;i++)
 {
	 HCLCD_Vid4Bits_SendCommand(CURSOR_SHIFT_LEFT>>4);
	 HCLCD_Vid4Bits_SendCommand(CURSOR_SHIFT_LEFT);

  _delay_ms(300);
 }
}
/**/
 void HCLCD_Vid4Bits_CursorShiftRight(u8 Copy_ShiftNumber)
{
	for(u8 i=0;i <Copy_ShiftNumber;i++)
	{
		HCLCD_Vid4Bits_SendCommand(CURSOR_SHIFT_RIGHT>>4);
		HCLCD_Vid4Bits_SendCommand(CURSOR_SHIFT_RIGHT);

      _delay_ms(300);
	}
}


