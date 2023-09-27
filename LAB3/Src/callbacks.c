/*
 * callbacks.c
 *
 *  Created on: Aug 23, 2023
 *      Author: vicente
 */
#include "gpio.h"
#include "callbacks.h"
//enum estado estado_boton= Veloz; //task 3
int camino=1;
enum estado estado_boton=Play; //task 4
int switches_1;
int switches_2;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  //TASK 2
	/*
  if(GPIO_Pin == GPIO_PIN_13){
	  if(estado_boton==Apagado){
		  estado_boton= Prendido ;
	  }else{
		  estado_boton=Apagado;
	  }

  }
  */
	// TASK 3
	/*
  if(GPIO_Pin == GPIO_PIN_13){
	  switch (estado_boton){
	    	case Veloz:
	    		estado_boton = Medio;
	    		camino =1;
	    		break;
	    	case Medio:
	    		if (camino == 1)
	    		{
	    			estado_boton= Lento;
	    			break;

	    		}
	    		if (camino ==0)
	    		{
	    			estado_boton=Veloz;
	    			break;
	    		}


	    	case Lento:
	    		estado_boton = Medio;
	    		camino=0;
	    		break;
	        default:
		        estado_boton = Veloz;
		        camino =1;
		        break;
		  }
    }
*/
	//TASK 4

	if(GPIO_Pin == GPIO_PIN_13){
		  if(estado_boton==Play){
			  estado_boton= Pause ;
		  }else{
			  estado_boton=Play;
		  }

	  }

}


