/*********************************************************************
 * \file   Dados.h
 * \brief  Dados dos utilizadores
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>



#pragma region Clientes
#define N 70

/**
 * .
 */
typedef struct Clientes {
	char nome[N];
	double saldo;
	char nif[10];
	char morada[70];
	//outros campos a adicionar
	
}Clientes;


 typedef struct ClientesLista {
	 Clientes cliente;
	 struct ClientesLista* next;
 }ClientesLista, ClientesListaPtr;

#pragma endregion


#pragma region Gestores

struct Gestores
{
	char nome[70];
	char nif[10];

};

#pragma endregion


#pragma region Transportes

struct Transportes
{
	char categoria[50];
	char codR[10]; // codigo de registo
	int cd;  //carga da bateria
	double custo;
	//outros campos a adicionar 

};

#pragma endregion
