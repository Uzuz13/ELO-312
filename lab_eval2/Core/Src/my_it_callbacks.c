/*
 * my_it_callbacks.c
 *
 *  Created on: Oct 2, 2023
 *      Author: sebar
 */

#include "my_it_callbacks.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h"
#include "adc.h"
#include "stdio.h"
#include "string.h"
#include "misFunciones.h"


char valor[15];
int Valor_adc;
double arreglo_adc[3];
int contador=0;
int contador_blink=0;
int indice=0;
char Mensaje[23];
extern uint8_t bit_r;
int indice_valor=0;
enum estado Estado_maquina=2;
enum estado Estado_maquina_prev=0;

uint8_t work[6]="work\r\n";
double suma;
double prom;
double voltaje_prom;
int flag=0;
int corta;
int Leds[5];



void HAL_UART_RxCpltCallback (UART_HandleTypeDef *huart)
{
		if(huart->Instance==USART2)
		{
			valor[indice_valor] = bit_r;
			indice_valor += 1;
			//HAL_UART_Transmit(&huart2, &work, 6,100);
			if(bit_r == '\n')
			{
				if(!strcmp("MSB\n", valor)){

						if(Estado_maquina==0){
							strcpy(Mensaje,"MODE ALREADY ACTIVE\r\n");
							HAL_UART_Transmit(&huart2, (uint8_t*)Mensaje, strlen(Mensaje),100);

						}else{
						Estado_maquina=0;}
					};
					if(!strcmp("MLA\n",valor)){ // Regresa Valor prommedio de conversion
						if(Estado_maquina==1){
							strcpy(Mensaje,"MODE ALREADY ACTIVE\r\n");
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));

						}else{
						Estado_maquina=1;

						}
					};
					if(!strcmp("MLD\n",valor)){ // regresaa valor leds

						if(Estado_maquina==2){
							strcpy(Mensaje,"MODE ALREADY ACTIVE\r\n");
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						}
						Estado_maquina=2;


					};

					if(!strcmp("MQR\n",valor)){ // Regresa Estado

						if(Estado_maquina==0){
							strcpy(Mensaje,"MSB\n");
							  HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						};
						if(Estado_maquina==1){
							strcpy(Mensaje,"MLA\n");
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						};
						if(Estado_maquina==2){
							strcpy(Mensaje,"MLD\n");
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						};

					};
					if(!strcmp("VQR\n",valor)){
						if(Estado_maquina==0){
							strcpy(Mensaje,"Value NaN\n");
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						};
						if(Estado_maquina==1){
							suma = arreglo_adc[0] + arreglo_adc[1] + arreglo_adc[2];
							prom = suma / 3;
							voltaje_prom = prom*(3.3/4095.0);
							sprintf(Mensaje,"ADC: %f V\r\n",(float)voltaje_prom);
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						};
						if(Estado_maquina==2){
							Leds[0]=HAL_GPIO_ReadPin(Led_1_GPIO_Port,Led_1_Pin );
							Leds[1]=HAL_GPIO_ReadPin(Led_2_GPIO_Port,Led_2_Pin );
							Leds[2]=HAL_GPIO_ReadPin(Led_3_GPIO_Port,Led_3_Pin );
							Leds[3]=HAL_GPIO_ReadPin(Led_4_GPIO_Port,Led_4_Pin );
							Leds[4]=HAL_GPIO_ReadPin(Led_5_GPIO_Port,Led_5_Pin );
							sprintf(Mensaje," %d %d %d %d %d \n",Leds[0],Leds[1],Leds[2],Leds[3],Leds[4]);
							HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));
						};
							}
					if(!strcmp("BLINK\n",valor)){
						Estado_maquina_prev=Estado_maquina;
						  HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(Led_2_GPIO_Port, Led_2_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(Led_3_GPIO_Port, Led_3_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(Led_4_GPIO_Port, Led_4_Pin, GPIO_PIN_RESET);
						  HAL_GPIO_WritePin(Led_5_GPIO_Port, Led_5_Pin, GPIO_PIN_RESET);
						Estado_maquina=3;

								};
					if(!((!strcmp("BLINK\n",valor))|(!strcmp("VQR\n",valor))|(!strcmp("MQR\n",valor))|(!strcmp("MSB\n",valor))|(!strcmp("MLA\n",valor))|(!strcmp("MLD\n",valor))  ) ){
						strcpy(Mensaje,"COMMAND ERROR \r\n");
						HAL_UART_Transmit_IT(&huart2, (uint8_t*)Mensaje, strlen(Mensaje));

					}

					memset(valor, 0, 10);
					indice_valor = 0;
			}
			if(indice_valor >= 10)
			{
				  HAL_UART_Transmit(&huart2, (uint8_t *) "LENGTH ERROR \r \n", 16, 10); //SI NO ENCUENTRA N, LENGTH ERROR + DATA
				  HAL_UART_Transmit(&huart2, (uint8_t *) valor, strlen(valor), 10); 			//TRANSMITE LO RECIBIDO EN RX
				  HAL_UART_Transmit(&huart2, (uint8_t *) "\r\n", 2, 1); 			//SALTO DE LINEA
				  indice_valor = 0;
				  memset(valor, 0, 10);
			}
	}
	HAL_UART_Receive_IT(&huart2,&bit_r, 1);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM3){
		if (Estado_maquina==1){
			HAL_ADC_Start_IT(&hadc2);
		}}

		if (htim->Instance == TIM2){
				if(Estado_maquina==3){
				contador_blink = contador_blink +1;
				HAL_GPIO_TogglePin(Led_1_GPIO_Port, Led_1_Pin);
				HAL_GPIO_TogglePin(Led_2_GPIO_Port, Led_2_Pin);
				HAL_GPIO_TogglePin(Led_3_GPIO_Port, Led_3_Pin);
				HAL_GPIO_TogglePin(Led_4_GPIO_Port, Led_4_Pin);
				HAL_GPIO_TogglePin(Led_5_GPIO_Port, Led_5_Pin);
				if (contador_blink ==16){
					contador_blink=0;
					Estado_maquina=Estado_maquina_prev;
					if(Estado_maquina_prev==2){
						coco(flag);
					}
					}
				}
				if(Estado_maquina==0){
					HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
				}
			}

}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	if(hadc->Instance == ADC2){
		  Valor_adc=HAL_ADC_GetValue(&hadc2);
		  indice=contador%3;
		  arreglo_adc[indice]=Valor_adc;
		  contador=contador+1;
		  coco((int)Valor_adc);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
			if (GPIO_Pin==B1_Pin){
				if(Estado_maquina==2){
					flag=flag+400;
					if (flag>4000){
						flag=0;
					}
					coco(flag);
					}
				}
}
