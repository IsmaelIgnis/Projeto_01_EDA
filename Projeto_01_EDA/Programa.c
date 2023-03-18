/*****************************************************************//**
 * \file   Programa.c
 * \brief  
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdbool.h>
#include"Dados.h"

void main() {

	clientesFileOpen();
	clientesFileRead();
	gestoresFileOpen();
	gestoresFileRead();
	transportesFileOpen();
	transportesFileRead();

	//inserirClientes();
	//inserirGestores();
	//inserirTansportes();

	//removerClientes();
	//removerGestores();
	//removerTransportes();
}
