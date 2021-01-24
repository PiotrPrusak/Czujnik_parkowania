/*
*** speaker library header***
*/

#ifndef SPEAKER_H
#define SPEAKER_H

#include "frdm_bsp.h"

#include<stdlib.h>

void TPM0_Init_PCM(void);

void TPM0_PCM_Play(void);

void change_wave_period(uint8_t new_wave_period);


#endif
