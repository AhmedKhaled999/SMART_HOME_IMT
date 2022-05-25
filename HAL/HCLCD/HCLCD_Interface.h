/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : HLCD Driver                                                                     */

#ifndef HAL_HCLCD_HCLCD_INTERFACE_H_
#define HAL_HCLCD_HCLCD_INTERFACE_H_
/*
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"HCLCD_Config.h"
#include"HCLCD_Private.h"
*/
#include"HCLCD_Private.h"

#define HCLCD_DISPLAY_CLEAR   DISPLAY_CLEAR

#define HCLCD_LINE1 1
#define HCLCD_LINE2 2

/*LCD Initialization*/
void HCLCD_Vid8Bits_Init(void);
void HCLCD_Vid4Bits_Init(void);

/*Send Command*/
void HCLCD_Vid8Bits_SendCommand (u8 Copy_u8Command);
/*Display Character*/
void HCLCD_Vid8Bits_DispalyCharacter(u8 Copy_u8Data);
/*Display String*/
void HCLCD_Vid8Bits_DisplayString(u8* PCopy_u8String);
/*Display Number*/
void HCLCD_Vid8Bits_DisplayNumber(u32 Copy_u8Number);
/*Set Position*/
void HCLCD_Vid8Bits_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
/*LCD Create SpecialCharacter*/
void HCLCD_Vid8Bits_CustomAlphChar(u8 Copy_u8PatternNumber, u8* PCopy_u8Pattern);
/*LCD Clear the Screen*/
void HCLCD_Vid8Bits_ClearScreen(void);
/*Shift Left The entire Display on Screen*/
void HCLCD_Vid8Bits_DisplayShiftLeft(u8 Copy_ShiftNumber);
/*Shift Right The entire Display on Screen*/
void HCLCD_Vid8Bits_DisplayShiftRight(u8 Copy_ShiftNumber);
/*Shift Left The Cursor on Screen*/
void HCLCD_Vid8Bits_CursorShiftLeft(u8 Copy_ShiftNumber);
/*Shift Right The Cursor on Screen*/
void HCLCD_Vid8Bits_CursorShiftRight(u8 Copy_ShiftNumber);

/******************************************************************************************************************************************/

void HCLCD_Vid4Bits_SendCommand (u8 Copy_u8Command);
/*Helper Function*/
void HCLCD_VidWriteChar_4Bits(u8 Copy_u8Data);
void HCLCD_Vid4Bits_DisplayCharacter(u8 Copy_u8Data);
void HCLCD_Vid4Bits_DisplayString(u8* PCopy_u8String);
void HCLCD_Vid4Bits_DisplayNumber(u32 Copy_u8Number);
void HCLCD_Vid4Bits_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
void HCLCD_Vid4Bits_CustomAlphChar(u8 Copy_u8PatternNumber, u8* PCopy_u8Pattern);
/*LCD Clear the Screen*/
void HCLCD_Vid4Bits_ClearScreen(void);
/*Shift Left The entire Display on Screen*/
void HCLCD_Vid4Bits_DisplayShiftLeft(u8 Copy_ShiftNumber);
/*Shift Right The entire Display on Screen*/
void HCLCD_Vid4Bits_DisplayShiftRight(u8 Copy_ShiftNumber);
/*Shift Left The Cursor on Screen*/
void HCLCD_Vid4Bits_CursorShiftLeft(u8 Copy_ShiftNumber);
/*Shift Right The Cursor on Screen*/
void HCLCD_Vid4Bits_CursorShiftRight(u8 Copy_ShiftNumber);
//LCD_VidGoToRowCol(u8 row ,u8 col);

#endif /* HAL_HCLCD_HCLCD_INTERFACE_H_ */
