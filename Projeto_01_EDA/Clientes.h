/*********************************************************************
 * \file   Clientes.h
 * \brief  
 * 
 * \author Ismael Morais a25964
 * \date   April 2023
 *********************************************************************/
#pragma once

#define A 100
#define B 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Clientes {
	char nome[A];
	double saldo;
	char nif[B];
	char morada[A];
	//outros campos a adicionar

}Clientes;


typedef struct ClientesLista {
	Clientes cliente;
	struct ClientesLista* next;
}ClientesLista, ClientesListaPtr;
