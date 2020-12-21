#include "frdm_bsp.h" 
#include "lcd1602.h" 
#include "pit.h"
#include "HC_SR04.h" 
#include "MKL05Z4.h" /*Device header*/

void lcd_static(void);
void lcd_update(void);



int main (void) { 
	

	LCD1602_Init (); 							// initialize LCD  
	lcd_static(); 								// display default on LCD 
	
	//SysTick_Config(1000000); 			// initialize system timer 
	PIT_Init_Generator (); 				// PIT initialization

  TPM0_Init_InputCapture();	    // TPM0 initialization							
	TRIG_GPIO_Init();							// set TRIG PIN as GPIO


  while(1) {

	TRIG_inpulse(); //get 1ms inpulse on TRIG to initialize sound wave on HC-SR04
	lcd_update();		//show ECHO 
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
	LCD1602_SetCursor(9, 1);  
	LCD1602_PrintNum((int)TPM0_GetVal()/19);   //divide by 19 to get result in cm ( it depend on prescaler value, speed of sound....)
}
