#ifndef Nokia5110_H
#define Nokia5110_H

#include "frdm_bsp.h"





void InitSPI(void);

void lcd_reset(void);


uint8_t spi_send(uint8_t byte);


void lcd_cmd(uint8_t cmd);

	
void lcd_data(const uint8_t* data, int size);



#endif // Nokia5110
