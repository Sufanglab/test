/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId Chassis_ctrlHandle;
osThreadId Delta_ctrlHandle;
osThreadId Click_ctrlHandle;
osThreadId Remote_ctrlHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void Startchassis_ctrl(void const * argument);
void StartDelta_ctrl(void const * argument);
void StartTask04(void const * argument);
void StartRemote_ctrl(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of Chassis_ctrl */
  osThreadDef(Chassis_ctrl, Startchassis_ctrl, osPriorityRealtime, 0, 128);
  Chassis_ctrlHandle = osThreadCreate(osThread(Chassis_ctrl), NULL);

  /* definition and creation of Delta_ctrl */
  osThreadDef(Delta_ctrl, StartDelta_ctrl, osPriorityRealtime, 0, 128);
  Delta_ctrlHandle = osThreadCreate(osThread(Delta_ctrl), NULL);

  /* definition and creation of Click_ctrl */
  osThreadDef(Click_ctrl, StartTask04, osPriorityRealtime, 0, 128);
  Click_ctrlHandle = osThreadCreate(osThread(Click_ctrl), NULL);

  /* definition and creation of Remote_ctrl */
  osThreadDef(Remote_ctrl, StartRemote_ctrl, osPriorityHigh, 0, 128);
  Remote_ctrlHandle = osThreadCreate(osThread(Remote_ctrl), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Startchassis_ctrl */
/**
* @brief Function implementing the Chassis_ctrl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Startchassis_ctrl */
void Startchassis_ctrl(void const * argument)
{
  /* USER CODE BEGIN Startchassis_ctrl */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Startchassis_ctrl */
}

/* USER CODE BEGIN Header_StartDelta_ctrl */
/**
* @brief Function implementing the Delta_ctrl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDelta_ctrl */
void StartDelta_ctrl(void const * argument)
{
  /* USER CODE BEGIN StartDelta_ctrl */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDelta_ctrl */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the Click_ctrl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void const * argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartRemote_ctrl */
/**
* @brief Function implementing the Remote_ctrl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRemote_ctrl */
void StartRemote_ctrl(void const * argument)
{
  /* USER CODE BEGIN StartRemote_ctrl */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartRemote_ctrl */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
