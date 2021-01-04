#include "frdm_bsp.h" 
#include "lcd1602.h" 
#include "pit.h"
#include "HC_SR04.h" 
#include "MKL05Z4.h" /*Device header*/
#include "Nokia5110.h"

#define RST 3  //resetowanie rejestrow wyswitlacza na poczatku trzeba wygenerowac 0 przez 100ns w trakcie pracy stan 1
#define CE 4   //Chip enable (CS)
#define DC 2	 //co przesylamy - dane(1), komendy(0)
#define DIN 7	 //data in(MOSI)
#define CLK 0	 //zegar (SCLK)



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
