#include "frdm_bsp.h" 
#include "lcd1602.h" 
#include "pit.h"
#include "HC_SR04.h" 
#include "MKL05Z4.h" /*Device header*/
#include "Nokia5110.h"
#include "font.h"
#include "bitmap.h"
#include "delay.h"



#define RST 3  //resetowanie rejestrow wyswitlacza na poczatku trzeba wygenerowac 0 przez 100ns w trakcie pracy stan 1
#define CE 4   //Chip enable (CS)
#define DC 2	 //co przesylamy - dane(1), komendy(0)
#define DIN 7	 //data in(MOSI)
#define CLK 0	 //zegar (SCLK)

#define PCD8544_FUNCTION_SET		0x20
#define PCD8544_DISP_CONTROL		0x08
#define PCD8544_DISP_NORMAL			0x0c
#define PCD8544_SET_Y						0x40
#define PCD8544_SET_X						0x80
#define PCD8544_H_TC						0x04
#define PCD8544_H_BIAS					0x10
#define PCD8544_H_VOP						0x80

#define LCD_BUFFER_SIZE			(84 * 48 / 8)

uint8_t lcd_buffer[LCD_BUFFER_SIZE];

void InitSPI(void)
{
	SIM->SCGC4 |= SIM_SCGC4_SPI0_MASK;  //clk
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	
	PORTB->PCR[CLK] = PORT_PCR_MUX(3);  ///ptb0 - SPI0_SCK
	PORTA->PCR[DIN] = PORT_PCR_MUX(3);	//pta7 - SIP0_MOSI
	SPI0->C1 |= SPI_C1_SPE_MASK;				//enable system SPI
	SPI0->C1 |= SPI_C1_MSTR_MASK;				//master mode
	SPI0->BR = 0x02;										//baud rate
	
	
	PORTB->PCR[DC] = PORT_PCR_MUX(1);  	// Set Pin 2 of PORT B as GPIO 
		PTB->PDDR|=(1<<DC); 								// Set pin 2 of GPIO B as output 
		PTB->PSOR |= (1<<DC); 							// przesyl danych / na 0 przesyl komend
	
	PORTB->PCR[CE] = PORT_PCR_MUX(1);  	// Set Pin 4 of PORT B as GPIO 
		PTB->PDDR|=(1<<CE); 								// Set pin 4 of GPIO B as output 
		PTB->PSOR |= (1<<CE); 							// Turn off 
	
		
	PORTB->PCR[RST] = PORT_PCR_MUX(1);  	// Set Pin 3 of PORT B as GPIO 
		PTB->PDDR|=(1<<RST); 								// Set pin 3 of GPIO B as output 
		PTB->PSOR |= (1<<RST); 							// Turn off 
	

}
void lcd_reset(void)
{
			PTB->PCOR|=(1<<RST);     //enable LOW level on RST (active)
			delay_ms(1); 							//wait 1ms
			PTB->PSOR|=(1<<RST);			//disable LOW level on RST
}

uint8_t spi_send(uint8_t byte)
{
	// poczekaj az bufor nadawczy bedzie wolny
	while (!(SPI0->S & SPI_S_SPTEF_MASK));
	SPI0->D = byte;
	while((SPI0->S & SPI_S_SPRF_MASK)!=SPI_S_SPRF_MASK); 
	SPI0->D;
}

void lcd_cmd(uint8_t cmd)
{
	PTB->PCOR|=(1<<CE);     //CS=0	
	PTB->PCOR|=(1<<DC);     //send comend
	spi_send(cmd);
	PTB->PSOR|=(1<<CE);
}
	
void lcd_data(const uint8_t* data, int size)
{
	int i;
	PTB->PSOR|=(1<<DC);     //send data
	PTB->PCOR|=(1<<CE);     //CS=0
	for (i = 0; i < size; i++)
		spi_send(data[i]);
	PTB->PSOR|=(1<<CE);
}

void lcd_setup(void)
{
	lcd_reset();
	
	lcd_cmd(PCD8544_FUNCTION_SET | 1);
	lcd_cmd(PCD8544_H_BIAS | 4);
	lcd_cmd(PCD8544_H_VOP | 0x3f);
	lcd_cmd(PCD8544_FUNCTION_SET);
	lcd_cmd(PCD8544_DISP_NORMAL);
}

void lcd_clear(void)
{
	memset(lcd_buffer, 0, LCD_BUFFER_SIZE);
}	


void lcd_draw_bitmap(const uint8_t* data)
{
	memcpy(lcd_buffer, data, LCD_BUFFER_SIZE);
}	


void lcd_draw_text(int row, int col, const char* text)
{
		int i;
	uint8_t* pbuf = &lcd_buffer[row * 84 + col];
	while ((*text) && (pbuf < &lcd_buffer[LCD_BUFFER_SIZE - 6])) {
		int ch = *text++;
		const uint8_t* font = &font_ASCII[ch - ' '][0];
		for (i = 0; i < 5; i++) {
			*pbuf++ = *font++;
		}
		*pbuf++ = 0;
	}
}

void lcd_copy(void)
{
	int i;
	PTB->PSOR|=(1<<DC);     //send data
	PTB->PCOR|=(1<<CE);     //CS=0
	for (i = 0; i < LCD_BUFFER_SIZE; i++)
		spi_send(lcd_buffer[i]);
	PTB->PSOR|=(1<<CE);
}
