/*****************************************************************//**
 * \file   Transportes.h
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


typedef struct Transportes
{
	char categoria[A];
	int codR; // codigo de registo
	int cb;  //carga da bateria
	double custo;
	//outros campos a adicionar 

	struct Transportes* next;
}Transportes;


#pragma region Viagem

Transportes* NovoVei(int i);

Transportes* InsereVei(Transportes* h, Transportes* novo, bool* res);
void MostraLista(Transportes* h);


#pragma endregion
