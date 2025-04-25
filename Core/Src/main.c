/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_customhid.h"
#include "keyboard.h"
#include "keyscanner.h"
#include "keymaps/keypal_L1.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void DebounceKeys();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t KeyMatrix[4][3] = {0};
uint8_t debounced_matrix[4][3] = {0};
uint8_t PreviousKeyMatrix[4][3] = {0};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USB_DEVICE_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  extern USBD_HandleTypeDef hUsbDeviceFS;
  uint8_t HID_buffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  uint8_t Current_Layer = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  // SANITY CHECK !!!
//	  HID_buffer[0] = 2;
//	  HID_buffer[2] = 9;
//	  USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HID_buffer, 8);
//
//	  HAL_Delay(200);
//
//	  HID_buffer[0] = 0;
//	  HID_buffer[2] = 0;
//	  USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HID_buffer, 8);
//
//	  HAL_Delay(2000);
//
//	  ReleaseAllKeys(hUsbDeviceFS, 0);
//	  HAL_Delay(2000);
	  ResetAllCols();
	  //USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HID_buffer, 8);

	  ScanKeys();

//	  if (KeyMatrix[0][0])
//	  {
//		  HID_buffer[0] = 0;
//		  HID_buffer[Key_Index] = KEY_MAP[Current_Layer][0][0];
//		  Key_Index++;
//	  }

	  int key_count = 2;

	  for (int row = 0; row < 4; row++)
	  {
		  for (int col = 0; col < 3; col++)
		  {
			  if(KeyMatrix[row][col])
			  {
				  uint8_t keycode = KEY_MAP[Current_Layer][row][col];

				  if (keycode >= 0xE0)
				  {
					  HID_buffer[0] |= (1 << (keycode - 0xE0));
				  }
				  else if (key_count < 8)
				  {
					  HID_buffer[key_count++] = keycode;
				  }
			  }
		  }
	  }
	  for (int i = key_count; i < 8; i++)
	  {
	          HID_buffer[i] = 0;
	  }
	  USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, HID_buffer, 8);



	  //HAL_Delay(1);
	  //ReleaseAllKeys(hUsbDeviceFS, 0);
	  //DebounceKeys();




    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void ScanKeys()
{

	ResetAllCols();
	for (int col = 0; col < NUM_COLS; col++)
	{
		//Poll 1 column at a time low to read rows
		SetCol(col);
		//HAL_Delay(5);

		for (int row = 0; row < NUM_ROWS; row++)
		{
			if (ReadRow(row) == 1)
			{
				KeyMatrix[row][col] = 1;
			} else {
				KeyMatrix[row][col] = 0;
			}
		}
		ResetAllCols();
	}
	DebounceKeys();
}

void DebounceKeys()
{
	static uint8_t previous_matrix[NUM_ROWS][NUM_COLS] = {0};
	static uint8_t debounce_counter[NUM_ROWS][NUM_COLS] = {0};

	const uint8_t debounce_threshold = 5; // number of stable reads

	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLS; col++)
		{
			if(KeyMatrix[row][col] == previous_matrix[row][col])
			{
				if(debounce_counter[row][col] < debounce_threshold)
				{
					debounce_counter[row][col]++;
				}

				if(debounce_counter[row][col] == debounce_threshold)
				{
					debounced_matrix[row][col] = KeyMatrix[row][col];
				}
			}
			else
			{
				debounce_counter[row][col] = 0;
				previous_matrix[row][col] = KeyMatrix[row][col];
			}
		}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
