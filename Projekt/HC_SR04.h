#ifndef HC_SR04_H
#define HC_SR04_H

#include "frdm_bsp.h"

void TPM1_Init_InputCapture(void);



void TRIG_GPIO_Init(void);

void TRIG_inpulse(void);

void delay_ms( int n);

uint32_t TPM1_GetVal(void);

void TPM1_IRQHandler(void);

#endif // HC_SR04
