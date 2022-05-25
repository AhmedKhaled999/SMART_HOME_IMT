/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : main.c --> IMT_SMART_HOME                                                       */
/* Project Features  :                                                                                 */
/*      1- Calculate Temperature and Light intensity                                                                */
/*		2- Display Temperature and Light intensity On LCD                                              */
/*      3- Login System                                                                        */
/*      4-                                                                                     */
/* Future Updates:                                                                                     */
/*      1-                                                                       */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include"../MCAL/MDIO/MDIO_Interface.h"         //for DIO
#include"../MCAL/MGIE/MGIE_Interface.h"         //for Global Interrupt
#include"../MCAL/MTIMER/MTIMER_Interface.h"     //for timer
#include"../MCAL/MADC/MADC_Interface.h"         //for ADC

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      HAL Components                                                 */
/*******************************************************************************************************/

#include"../HAL/HCLCD/HCLCD_Interface.h"         //for LCD
#include"../HAL/HKPD/HKPD_Interface.h"           //for KPD
#include"../HAL/HLED/HLED_Interface.h"           //for LED


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                   Service Layer  Components                                         */
/*******************************************************************************************************/

#define F_CPU  8000000UL
#include<util\delay.h>

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Global Variables(Flag)                                         */
/*******************************************************************************************************/
u8 Global_Flag_1 = 0;
u8 Temerature , Temerature_dec;
u16 percent;

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                     Application Function Prototype                                  */
/*******************************************************************************************************/
void Ask_For_Login(void);
void Get_Temperature(void);
void Display_Temperature(void);
void Light_Intensity(void);
void Get_Light_Intensity(void);


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                    Beginning of the System                                          */
/*******************************************************************************************************/


int main(void)
{
/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                          System variables                                           */
/*******************************************************************************************************/
u8 Local_Key;


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      System Initialization                                          */
/*******************************************************************************************************/

    MADC_VidInit();                                            /*         Initialize ADC           */
	/*******************************************************************************************************/
	/*                    F_cpu = 8MHz, prescaler = 64 -->F_timer = 125000HZ ,                             */
	/*                    T_tick = 8 micro second ,One_OVF = 256*8 = 2048  micro second ,                  */
	/*	                  F_out = Fcpu/N*510                                                               */
	/*******************************************************************************************************/
	HCLCD_Vid4Bits_Init();                                     /*        LCD Initialization        */
    HKPD_VidInit();
    HLED_VidInit(RED_LED_PIN,RED_LED_PORT);




    while(1)
    {


    	if(Global_Flag_1 == 0)
    	{
        	/* Calls a Functions that Displays The Current Temperature  */
        	Display_Temperature();
        	/* Calls a Functions that Displays The Light Intensity  */
        	Light_Intensity();
    	}
    	else
    	{
    		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE1,0);
    		HCLCD_Vid4Bits_DisplayString(" Press Any Key ");
    		HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,1);
    		HCLCD_Vid4Bits_DisplayString(" To Try Again ");

    	}


    	for(u16 i =0 ; i<1000 ;i++)
    	{
    		Local_Key = HKPD_U8GetKeyPressed();
    		if(Local_Key != NOT_PRESSED)
    		{
    			/* Calls a Functions that asks the user to enter Password */
    			Ask_For_Login();
    		}
    	}







    }


	return 0;
}


/* Functions Implementation  */

void Get_Temperature(void)
{
	/*******************************************************************************************************/
	/*                                         Calculate Temperature                                       */
	/*******************************************************************************************************/
	u16 Digital_Value, Analog_value;

	Digital_Value = MADC_u16ADC_StartConversion(CHANNEL_4);         /*        Get ADC Reading           */
	Analog_value = (u16)((Digital_Value*5000UL)/1024);              /*        Read Analog Voltage       */
	Temerature_dec = (Analog_value % 10);
	Temerature = (Analog_value/10);                                 /*        Calculate Temperature     */
}
void Display_Temperature(void)
{
	/*******************************************************************************************************/
	/*                                          Display Temperature                                            */
	/*******************************************************************************************************/

	Get_Temperature();                                   /* Function That Calculates Temperature */
	HCLCD_Vid4Bits_ClearScreen();
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE1,1);          /*  Position of Temperature on LCD first row */
	HCLCD_Vid4Bits_DisplayString("Temp = ");
	HCLCD_Vid4Bits_DisplayNumber(Temerature);
	HCLCD_Vid4Bits_DisplayString(".");
	HCLCD_Vid4Bits_DisplayNumber(Temerature_dec);
	HCLCD_Vid4Bits_DisplayString(" C");

}

void Get_Light_Intensity(void)
{
	/*******************************************************************************************************/
	/*                                         Calculate Light Intensity                                   */
	/*******************************************************************************************************/
	u16 Digital_Value1;


	Digital_Value1 = MADC_u16ADC_StartConversion(CHANNEL_1);                 /* Getting ADC Reading from the LDR */
	 /* Calculating the Light Intensity Percent  */
	percent = (u16)((Digital_Value1*100UL)/1024);                    /*    Converting The Reading into Percentage    */
}
/*******************************************************************************************************/
/*                                         Display Light Intensity                                     */
/*******************************************************************************************************/
void Light_Intensity(void)
{
	Get_Light_Intensity();                              /* Function That Calculates Light Intensity */
	HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,1);
	HCLCD_Vid4Bits_DisplayString("LT INT = ");         /* Displays the Light Intensity Reading of the LDR */
	HCLCD_Vid4Bits_DisplayNumber(percent);
	HCLCD_Vid4Bits_DisplayString(" %");

}




void Ask_For_Login(void)
{
	/*******************************************************************************************************/
	/*                                         Login System Function                                       */
	/*******************************************************************************************************/
    u8 Local_u8Key;
     u16 password = 8520 ,value , Num1=0;
     u8 Operator = 0,counter=0 , counter2=0;

    HCLCD_Vid4Bits_ClearScreen();
    HCLCD_Vid4Bits_DisplayString("Enter Passcode :");       /* Asking User to Enter Password */
    HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,4);
	while(1)
	{
		Local_u8Key = HKPD_U8GetKeyPressed();             /* Checks if The Key is Pressed  */

	       if(Local_u8Key != NOT_PRESSED)                 /* if Key is Pressed */
	       {
	    	   if(counter<4)
	    	   {
	    		   counter++;

	    	   switch(Local_u8Key)
	    	   {
	    	   case '0':
	    		   value =0;
	    		   Num1 = (Num1*10) +value ;
	    		   HCLCD_Vid4Bits_DisplayCharacter('0');
	    		   break;
	    	   case '1':
	    		   value =1;
	    		   Num1 = (Num1*10) +value ;
	    		   HCLCD_Vid4Bits_DisplayCharacter('1');
	    		   break;
	    	   case '2':
	    	       value =2;
	    	       Num1 = (Num1*10) +value ;
	    	       HCLCD_Vid4Bits_DisplayCharacter('2');
	    	       break;
	    	   case '3':
	    	       value =3;
	    	       Num1 = (Num1*10) +value ;
	    	       HCLCD_Vid4Bits_DisplayCharacter('3');
	    	       break;
	    	   case '4':
	    	       value =4;
	    	       Num1 = (Num1*10) +value ;
	    	       HCLCD_Vid4Bits_DisplayCharacter('4');
	    	       break;
	    	   case '5':
	    	       value =5;
	    	       Num1 = (Num1*10) +value ;
	    	       HCLCD_Vid4Bits_DisplayCharacter('5');
	    	       break;
	    	   case '6':
	    	       value =6;
	    	       Num1 = (Num1*10) +value ;
	    	       HCLCD_Vid4Bits_DisplayCharacter('6');
	    	       break;
	    	   case '7':
	    	       value =7;
	    	       Num1 = (Num1*10) +value ;
	    	       HCLCD_Vid4Bits_DisplayCharacter('7');
	    	        break;
	       	   case '8':
	        	   value =8;
	        	   Num1 = (Num1*10) +value ;
	        	   HCLCD_Vid4Bits_DisplayCharacter('8');
	        	    break;
	           case '9':
	        	   value =9;
	        	   Num1 = (Num1*10) +value ;
	        	   HCLCD_Vid4Bits_DisplayCharacter('9');
	        	    break;
	           default:                                    /* if any Button is pressed other than Numbers */
	        	   HCLCD_Vid4Bits_ClearScreen();

	        	   HCLCD_Vid4Bits_SetPosition(HCLCD_LINE1,1);
	        	   HCLCD_Vid4Bits_DisplayString("Please Enter");

	        	   HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,1);
	        	   HCLCD_Vid4Bits_DisplayString("Numbers Only");
	        	   _delay_ms(1500);

	        	   HCLCD_Vid4Bits_ClearScreen();
	        	   HCLCD_Vid4Bits_DisplayString("   Try Again ");     /* Asks The User to Enter Password Again */
	        	   HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,4);
	        	   _delay_ms(500);
	        	   counter =0 ;

	    	   }

	    	   }
	    	   if(counter>3)                   /* if 4 Numbers Are Entered */
	    	   {
	    		   if(Num1 == password)       /* Checks if Password Match */
	    		   {
	    		   _delay_ms(1000);

	    		   HCLCD_Vid4Bits_ClearScreen();

	    		   HCLCD_Vid4Bits_DisplayString("    Welcome ");   /* Welcome Message is Displayed */
	    		   Global_Flag_1 = 0;
	    		   _delay_ms(1000);
	    		   break;
	    		   }
	    		   else
	    		   {

	    			   if(counter2 < 2)           /* if a wrong password is entered less than three times */
	    			   {
	    	    		 _delay_ms(1000);
	    	    		 HCLCD_Vid4Bits_ClearScreen();
	    	    		 HCLCD_Vid4Bits_DisplayString("  Try Again ");
	    			     counter = 0 ;
	    			     Num1=0;
	    			     counter2++;
	    			     HCLCD_Vid4Bits_SetPosition(HCLCD_LINE2,4);


	    			   }
	    			   else                      /* if Password is entered 3 times Wrong */
	    			   {
	    				   _delay_ms(1000);
	    				   HCLCD_Vid4Bits_ClearScreen();
	    				   HCLCD_Vid4Bits_DisplayString(" Out of tries !");
	    				   Global_Flag_1 = 1;
	    				   for(u8 i =0 ; i<25 ; i++)
	    				   {
	    					   HLED_VidInit_On(RED_LED_PIN,RED_LED_PORT);
	    					   _delay_ms(200);
	    					   HLED_VidInit_Off(RED_LED_PIN,RED_LED_PORT);
	    					   _delay_ms(200);
	    				   }
	    				    break;


	    			   }

	    		   }

	    	   }

	       }
	}

}

