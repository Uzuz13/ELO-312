/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "usart.h"
#include "gpio.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  /* Familiarizarse con los tipos de datos de C */
	  	  int vi = 0;
	  	  unsigned int uvi = 0;

	  	  int max_vi = ~vi;
	  	  int max_uvi = ~uvi;

	  	  char vc = 0;
	  	  unsigned char uvc = 0;

	  	  int max_vc = ~vc;
	  	  int max_uvc = ~uvc;

	  	  float vf = 0;

	  	  /* Averiguar uso de memoria */
	  	  unsigned int num_of_bytes = 0;
	  	  num_of_bytes = sizeof(int);
	  	  num_of_bytes = sizeof(char);
	  	  num_of_bytes = sizeof(float);

	  	  vc = max_vi;

	  	  /* Operaciones con distintos tipos de datos */
	  	  vc = max_vc + 1;
	  	  uvi = uvi - 1;

	  	  vi = 3/4;
	  	  vi = (float) 3/4;

	  	  vf = 3/4;
	  	  vf = (float) 3/4;
	  	  vf = 0;
	  	  vf = 3.0/4;

	  	  /* Uso de bucles */
	  	  vc = 'A';
	  	  vc = vc + 1;
	  	  vc += 1;
	  	  vc++;

	  	  int count = 0;
	  	  vc = 65;
	  	  char vc2 = 0;
	  	  for (count = 0; count < 10; count++){
	  		  vc2 = vc++;
	  	  }

	  	  for (count = 0; count < 10; count++){
	  		  vc2 = ++vc;
	  	  }

	  	  count = 1;
	  	  vi = 10;
	  	  uvc = 0;
	  	  while (count <= 10){
	  		  uvc = vi % count;
	  		  count += 1;
	  	  }
	  	  int count_2=0;
		  #define Retardo 2
	  	  while (count_2 <= Retardo){
	  		  //delay?????
	  		  	 count_2 += 1;
	  		  	  }


	  	  int variable_1;
	  	  variable_1=2;
	  	  count_2=0;
	  	  while (count_2 <= Retardo){
	  		  	 //delay?????
	  		  	variable_1=6;
	  		  	 count_2 += 1;
	  		    }

	  	  for (count_2 = 0; count_2 < 2; count_2++){
	  		  	  	 int variable_1=5;
	  		         variable_1++;
	  		  	  }
	  	 count_2=0;
	  	  /* Experimentar con bucles for (),  while(), y do ... while()
	  	   * - Escriban un bucle cuyo proposito es generar un retardo configurable
	  	   *
	  	   * - Dada una variable ya existente en su programa, dentro de un buscle
	  	   * de cualquie tipo, definan otra variable que tenga el mismo nombre. Luego,
	  	   * cambien el valor de esta variable en el interior del bucle. Una vez fuera
	  	   * del bucle, revisen el valor de la variable original que tiene el mismo nombre.
	  	   * ¿Qué valor tiene y por qué?
	  	   * ¿Cuál variable modificaron al interior del bucle?
	  	   * */

	  	  /* Experimentar con condicionales if ... else */
	  	   int valor_comp;
	  	   int referencia;
	  	   int resultado;

	  	 valor_comp=4;
		 referencia=5;


	  	   if (valor_comp>referencia){
	  		 resultado=1;
	  	   }else{
	  		 resultado=0;
	  	   };
	  	 referencia=0;
	  	  /* Precedencia de operadores: practicar con cálculos con y sin paréntesis
	  	   * combinando distintos operadores (+, -, *, /, %, ++)
	  	   * */
	  	 int A=5;
	  	 int B=4;
	  	 int C;


	  	 C=A*B+B*B;
	  	 C=(A*B);
	  	 C= 30/A%B;
	  	 C= B%15/A;
	  	 C=3*4/5;
	  	 C=8/4*3;

	  	referencia=0;

	  	  /* Practicar con operadores a BIT (Bitwise operators)
	  	   * Cambiar el estado de bit en posiciones especificas de una variable
	  	   * Consultar el estado del bit en posiciones específicas de una variable
	  	   * Hacer toggle (complementar) el valor del bit en posiciónes específicas
	  	   * */


	  	int valor;
	  	int valor_final;
	  	int valor_pos_5;
	  	valor =100;
	  	valor_final=valor&223;
	  	/*68*/
	  	valor_pos_5=valor_final&32;


	  	referencia=0;



	  	  /* Escribir un código que opera sobre una variable de tipo char y hace lo
	  	   * siguiente:
	  	   * - Si la variable almacena una letra minuscula, cambiar su valor a mayuscula
	  	   * - Si la variable almacena una letra minúscula, cambiar su valor a mayuscula
	  	   * - No debería hacer nada en cualquier otro caso
	  	   * */
	  	char letra_in;
	  	char letra_out;
        letra_in='h';

	  	if (65<=letra_in<=90){//es mayusc
	  		letra_out=letra_in+32;
	  	}
	  	else if(97<=letra_in<=122){
	  		letra_out=letra_in-32;
	  	}
	  	else{
	  		letra_out=0;
	  	}

	  	referencia=0;

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
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
