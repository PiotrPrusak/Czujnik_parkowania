#ifndef Nokia5110_H
#define Nokia5110_H

#include "frdm_bsp.h"





void InitSPI(void);

void lcd_reset(void);

void lcd_setup(void);

void lcd_clear(void);
void lcd_draw_bitmap(const uint8_t* data);
void lcd_draw_text_small(int row, int col, const char* text);

void lcd_draw_text_medium(int row, int col, const char* text);
 
void lcd_copy(void);

void spi_send(uint8_t byte);


void lcd_cmd(uint8_t cmd);

	
void lcd_data(const uint8_t* data, int size);

void lcd_update(void);

void lcd_hello(void);

void lcd_zwolnienie(void);
#endif 

