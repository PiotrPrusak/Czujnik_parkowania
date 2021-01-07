#include "frdm_bsp.h" 
#include "lcd1602.h" 
#include "pit.h"
#include "HC_SR04.h" 
#include "MKL05Z4.h" /*Device header*/
#include "speaker.h"
#include "sinus.h"
#include "Nokia5110.h"
#include "delay.h"
#include "bitmap.h"
#include "font.h"
void lcd_static(void);
void lcd_update(void);

	char str[12];

int main (void) { 
	

	//LCD1602_Init (); 							// initialize LCD  
	//lcd_static(); 								// display default on LCD 
	
	//SysTick_Config(1000000); 			// initialize system timer 
	PIT_Init_Generator (); 				// PIT initialization

  TPM1_Init_InputCapture();	    // TPM1 initialization							
	
	TRIG_GPIO_Init();							// set TRIG PIN as GPIO
	
	TPM0_Init_PCM();							//TPM0 init

	InitSPI();
	
	lcd_setup();
 /*
	lcd_draw_bitmap(logo);
	lcd_copy();
	delay_ms(1000);
  */
	lcd_clear();



	
	
  while(1) {

	TRIG_inpulse(); //get 1ms inpulse on TRIG to initialize sound wave on HC-SR04
	lcd_update();		//show ECHO 

	change_wave_period((int)TPM1_GetVal()/19);
	delay_ms(500);
		} 						// end_while 
}									// end_main

//function to print static data on LCD
void lcd_static(void) {		
	
	LCD1602_ClearAll();
	LCD1602_SetCursor(0, 0);
	LCD1602_Print("HC-SR04 ");
	LCD1602_SetCursor(0, 1);
	LCD1602_Print("dist[cm]= "); 
	lcd_update();							
	
}

//function to print HC-SR04 distance in cm on LCD
void lcd_update(void) {     
	itoa((int)TPM1_GetVal()/19, str, 10);
	lcd_clear();
	lcd_draw_text(0, 1 * 8,str);//sprintf(str, "%d", (int)TPM1_GetVal()/19));
	lcd_copy();
	//LCD1602_SetCursor(9, 1);  
	//LCD1602_PrintNum((int)TPM1_GetVal()/19);   //divide by 19 to get result in cm ( it depend on prescaler value, speed of sound....)
}
