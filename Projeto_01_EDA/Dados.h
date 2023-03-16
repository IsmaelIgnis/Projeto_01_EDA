/*****************************************************************//**
 * \file   Dados.h
 * \brief  Dados dos utilizadores
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/
#pragma once

typedef struct Clientes {
	char nome[50];
	double saldo;
	char nif[10];
	char morada[100];
	//outros campos a adicionar
	Clientes* prox; //apontador para o proximo nó da linha da lista
}Clientes;