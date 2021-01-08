
#ifndef PIT_H
#define PIT_H

#include "frdm_bsp.h"


/**
 * @brief PIT initialization. Channel 0.
 */
void PIT_Init_Generator(void);
/**
 * @brief Change value in timer[0] load value register.
 *
 * @param Timer start value.
 */
void PIT_SetTSV(uint32_t period);

#endif /* PIT_H */
