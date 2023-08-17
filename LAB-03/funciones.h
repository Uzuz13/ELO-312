/*
 * funciones.h
 *
 *  Created on: Aug 16, 2023
 *      Author: vicente
 */

#ifndef INC_FUNCIONES_H_
#define INC_FUNCIONES_H_

 //esta wea no va

typedef struct sansano{
	  		  char nombre[50];
	  		  char carrera[50];
	  		  int rol;
	  	  }sansano;

typedef struct My_struct{
			  char caracter;
			  int entero;
			  float fraccion;
			  int arreglo[5];
			  char *ptrchar;

}My_struct;

struct letrita{
	char letra;
	double numerito;
};

int posicion(My_struct *ptrstruct, int a);
void invocar_retardo(unsigned int valor_retardo);
void incrOnePointer (char *caracter);
void incrOnePointer_mala (char caracter);


#endif /* INC_FUNCIONES_H_ */
