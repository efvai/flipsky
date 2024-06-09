/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "CO_app_STM32.h"
#include "tim.h"
#include "can.h"
#include "OD.h"
#include "CO_domain_STM32.h"
#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern CAN_HandleTypeDef hcan1;
extern TIM_HandleTypeDef htim6;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for ledTask */
osThreadId_t ledTaskHandle;
uint32_t ledTaskBuffer[ 128 ];
osStaticThreadDef_t ledTaskControlBlock;
const osThreadAttr_t ledTask_attributes = {
  .name = "ledTask",
  .cb_mem = &ledTaskControlBlock,
  .cb_size = sizeof(ledTaskControlBlock),
  .stack_mem = &ledTaskBuffer[0],
  .stack_size = sizeof(ledTaskBuffer),
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void startLedTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of ledTask */
  ledTaskHandle = osThreadNew(startLedTask, NULL, &ledTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  CANopenNodeSTM32 canOpenNodeSTM32;
  canOpenNodeSTM32.CANHandle = &hcan1;
  canOpenNodeSTM32.HWInitFunction = MX_CAN1_Init;
  canOpenNodeSTM32.timerHandle = &htim6;
  canOpenNodeSTM32.desiredNodeID = 1;
  canOpenNodeSTM32.baudrate = 125;
  canopen_app_init(&canOpenNodeSTM32);
  // ((()))
  OD_extension_t OD_domain_extension;
  OD_domain_extension.object = NULL;
  OD_domain_extension.read = NULL;
  OD_domain_extension.write = OD_writeDomain;
  OD_extension_init(OD_ENTRY_H3002, &OD_domain_extension);
  for(;;)
  {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, !canOpenNodeSTM32.outStatusLEDRed);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, !canOpenNodeSTM32.outStatusLEDGreen);
    canopen_app_process();
	vTaskDelay(pdMS_TO_TICKS(1));
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_startLedTask */
/**
* @brief Function implementing the ledTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startLedTask */
void startLedTask(void *argument)
{
  /* USER CODE BEGIN startLedTask */
  float freq = 1.0;
  float time = 0.0;
  float sine = 0.0;
  const float pi = 3.14159265;
  /* Infinite loop */
  for(;;)
  {
    freq = 1.0;
    sine = sin(2 * pi * freq * time);
    OD_TEST.x3001_testSignals.sin1Hz = sine;

    freq = 5.0;
    sine = sin(2 * pi * freq * time);
    OD_TEST.x3001_testSignals.sin5Hz = sine;

    freq = 10.0;
    sine = sin(2 * pi * freq * time);
    OD_TEST.x3001_testSignals.sin10Hz = sine;

    freq = 50.0;
    sine = sin(2 * pi * freq * time);
    OD_TEST.x3001_testSignals.sin50Hz = sine;

    freq = 100.0;
    sine = sin(2 * pi * freq * time);
    OD_TEST.x3001_testSignals.sin100Hz = sine;

    time += 1.0 / 1000.0;
    osDelay(1);
  }
  /* USER CODE END startLedTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

