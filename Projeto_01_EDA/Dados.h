/*****************************************************************//**
 * \file   Dados.h
 * \brief  Dados dos utilizadores
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/
#pragma once

 typedef struct Clientes {
	char nome[70];
	double saldo;
	char nif[10];
	char morada[70];
	//outros campos a adicionar
	
};

struct Gestores
{
	char nome[70];
	char nif[10];

};

struct Transportes
{
	char categoria[50];
	char codR[10]; // codigo de registo
	int cd;  //carga da bateria
	double custo;
	//outros campos a adicionar 

};
