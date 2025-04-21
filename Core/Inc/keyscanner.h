/*
 * keyscanner.h
 *
 *  Created on: Apr 17, 2025
 *      Author: adamj
 */

#ifndef INC_KEYSCANNER_H_
#define INC_KEYSCANNER_H_

#include "stm32f4xx_hal.h"


void KS_Init();
void KS_PrintScanLines();
uint8_t KS_ReadScanCode(uint8_t* scanCodeBuffer, uint8_t bufferLength, uint8_t* modifiers);

#endif /* INC_KEYSCANNER_H_ */
