#include "frdm_bsp.h" 
#include "pit.h"
#include "HC_SR04.h" 
#include "MKL05Z4.h" 
#include "speaker.h"
#include "sinus.h"
#include "Nokia5110.h"
#include "delay.h"
#include "bitmap.h"
#include "font.h"




int main (void) { 

	PIT_Init_Generator (); 				// PIT initialization

  TPM1_Init_InputCapture();	    // TPM1 initialization							
	
	TRIG_GPIO_Init();							// set TRIG PIN as GPIO
	
	TPM0_Init_PCM();							//TPM0 init

	InitSPI();										//Init SPI communication with Nokia 5110
	
	lcd_setup();                  //Send command to LCD
 
	lcd_draw_bitmap(logo);				//Show welcome image
	lcd_copy();
	delay_ms(1000);
  
	lcd_clear();



	
	
  while(1) {

	TRIG_inpulse(); //get 10us inpulse on TRIG to initialize sound wave on HC-SR04
	lcd_update();		//show distance from HC-SR04 on LCD 

	change_wave_period(TPM1_GetVal());  //change frequency of speaker tone
	delay_ms(300);
		} 						// end_while 
}									// end_main



