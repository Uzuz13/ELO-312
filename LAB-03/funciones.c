/*
 * funciones.c
 *
 *  Created on: Aug 16, 2023
 *      Author: vicente
 */


#include "funciones.h"

void invocar_retardo(unsigned int valor_retardo){
	static int veces_invocada = 1;
	for(int i=0;i<valor_retardo;i++){
		//nada AAAAAAAAa
		}
	veces_invocada++;

};
void incrOnePointer (char *caracter){
	*caracter=*caracter+1;
};
void incrOnePointer_mala (char caracter){
	caracter=caracter+1;
};

int posicion(My_struct *ptrstruct, int a){
	int flag=-1;
	for (int i=0;i<5;i++){
		if(ptrstruct->arreglo[i]==a){
			flag=i;
		};

	};
	return flag;
};




