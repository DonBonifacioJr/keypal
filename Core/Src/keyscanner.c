/*
 * keyscanner.c
 *
 *  Created on: Apr 21, 2025
 *      Author: adamj
 */


#include "main.h"
#include "keyscanner.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>

#define NUM_ROWS 4
#define NUM_COLS 3

// Private Function



//Public Functions
void SetAllCols()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
}

void ResetAllCols()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
}

void SetCol(int col)
{
	switch (col)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
		break;
	}

}

int ReadRow(int row)
{
	switch (row)
	{
	case 0:
		return (GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
	case 1:
		return (GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
	case 2:
		return (GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8));
	case 3:
		return (GPIO_PIN_SET == HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9));
	}
	return 0;
}



