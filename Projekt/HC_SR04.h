#ifndef HC_SR04_H
#define HC_SR04_H

#include "frdm_bsp.h"

void TPM0_Init_InputCapture(void);

void TPM1_Init_OutputCompare(void);

void TRIG_GPIO_Init(void);

void TRIG_inpulse(void);

void delay_ms( int n);

uint32_t TPM0_GetVal(void);

void TPM0_IRQHandler(void);

#endif // HC_SR04
