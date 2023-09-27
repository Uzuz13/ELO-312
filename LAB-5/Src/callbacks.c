/*
 * callbacks.c
 *
 *  Created on: Sep 13, 2023
 *      Author: vicente
 */

#include "callbacks.h"
#include "tim.h"
#include "adc.h"
#include "usart.h"
#include "gpio.h"
#include "string.h"
#include "stdio.h"
enum Estado Estado_timer=0;
//buffer que se llenara para la transmision de uart
int raw; //ACA SE GUARDARA NUESTRA LECTURA
char msg[17];

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM3){
			 HAL_GPIO_WritePin(GPIOA, Salida_GPIO_Port, GPIO_PIN_SET);
			  // Obtener valor adc
			 if(raw<1300){
					  HAL_GPIO_WritePin(Led_0_GPIO_Port, Led_0_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_SET);

				  }else{
					  if(raw<2600){
					  		  HAL_GPIO_WritePin(Led_0_GPIO_Port, Led_0_Pin, GPIO_PIN_SET);
					  		  HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_RESET);

					  	  }else{
					  		if(raw<3900){
					  				  HAL_GPIO_WritePin(Led_0_GPIO_Port, Led_0_Pin, GPIO_PIN_RESET);
					  				  HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_RESET);

					  			  }
					  	  }


				  }
			  HAL_ADC_Start_IT(&hadc1);
			  // Le dice al procesador que espere mientras que se termina la conversion


			  //
	}

}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	if(hadc->Instance == ADC1){
		  raw=HAL_ADC_GetValue(&hadc1);
		  // PARAMOS
		  HAL_GPIO_WritePin(GPIOA, Salida_GPIO_Port, GPIO_PIN_RESET);
		  // Convertimos los datos a string y los pasamos al puerto uart
		  sprintf(msg,"Valor Leido:%d\r\n",raw);
		  HAL_UART_Transmit_IT(&huart2, (uint8_t*)msg, strlen(msg));
		  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg),HAL_MAX_DELAY);
	}

}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART2){

	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{if (GPIO_Pin==B1_Pin){
		if(Estado_timer== Corriendo){
			HAL_TIM_Base_Stop_IT(&htim3);
			Estado_timer=Detenido;
			HAL_GPIO_WritePin(Led_0_GPIO_Port, Led_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_SET);
		}else{if(Estado_timer==Detenido)
				{
					HAL_TIM_Base_Start_IT(&htim3);
					Estado_timer=Corriendo;

				}

		}
	}
}


