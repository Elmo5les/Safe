#include "LCD.h"
#include "../../MCAL/GPIO/GPIO_CONFIG.h"
#include <util/delay.h>  // so i can use _dealy_ms() function


static void LCD_WriteCommand(UINT8 Command)
{
	GPIO_WRITE_PIN_VALUE(RS_PORT, RS_PIN, LOW);  // so i can write command
	GPIO_WRITE_PIN_VALUE(RW_PORT, RW_PIN, LOW); //  to tell the lcd that i am going to write data
	GPIO_WRITE_PORT_VALUE(LCD_PORT, Command); // passing the command through the lcd_port
	GPIO_WRITE_PIN_VALUE(EN_PORT, EN_PIN, HIGH); // activating the enable
	_delay_ms(2);
	GPIO_WRITE_PIN_VALUE(EN_PORT, EN_PIN, LOW); // disabling the enable
	_delay_ms(2);
}

void LCD_Init(void)
{
	GPIO_INIT_PIN_DIRECTION(RS_PORT ,RS_PIN, OUTPUT);
	GPIO_INIT_PIN_DIRECTION(RS_PORT ,RW_PIN, OUTPUT);
	GPIO_INIT_PIN_DIRECTION(RS_PORT ,EN_PIN, OUTPUT);
	GPIO_INIT_PORT_DIRECTION(LCD_PORT,OUTPUT);
	
	
	LCD_WriteCommand(LCD_8BIT_2_LINE_5_x_7);
	_delay_ms(2);
	LCD_WriteCommand(LCD_DISPLAY_ON_CURSOR_ON);
	_delay_ms(2);
	LCD_WriteCommand(LCD_CLEAR_ALSO_DDRAM);
	_delay_ms(2);
	LCD_WriteCommand(FORCE_CURSOR_TO_BEGINNING_1ST_LINE);
	_delay_ms(2);
	LCD_WriteCommand(LCD_ENTRY_MODE);
}

void LCD_WriteData(UINT8 Data)
{
	GPIO_WRITE_PIN_VALUE(RS_PORT,RS_PIN,HIGH );
	GPIO_WRITE_PIN_VALUE(RW_PORT,RW_PIN,LOW);

	GPIO_WRITE_PORT_VALUE(LCD_PORT , Data) ;
	GPIO_WRITE_PIN_VALUE(EN_PORT,EN_PIN,HIGH);
	_delay_ms(2);
	GPIO_WRITE_PIN_VALUE(EN_PORT,EN_PIN,LOW);
	_delay_ms(2);
}




void LCD_WriteSentence(UINT8 *PtrSentance)
	
{
    UINT8 i=0;
	
	while( PtrSentance[i] != '\0' )
	{
	  LCD_WriteData( PtrSentance[i] ) ;
          i++ ;
        }	

}

void LCD_Clear(void)
{

	

}