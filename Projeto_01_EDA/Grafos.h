/*****************************************************************//**
 * \file   Grafos.h
 * \brief  O codigo deste ficheiro foi adaptado do codigo disponibilizado pelo professor
 * 
 * \author Ismael Morais a25964
 * \date   May 2023
 *********************************************************************/
#pragma once

#define A 100
#define B 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



 /**
  * Estrutura de uma Adjacência.
  */
typedef struct Adj {
	int cod;		/*!< Código da Adjacência */
	float dist;		/*!< Peso */
	struct Adj* next;
}Adj;

/**
 * Descrição de um Vértice do grafo.
 */
typedef struct Vertice {
	int cod;					/*!< Código do Vértice */
	char cidade[B];				/*!< Nome da Cidade */
	struct Vertice* next;		/*!< Lista de Vértices */
	struct Adj* adjacentes;		/*!< Lista de Adjacências */
} Vertice;

#pragma region GRAFO

Vertice* CriaGrafo();
Vertice* InsereVertice(Vertice* g, Vertice* novo, bool* res);
Vertice* CriaVertice(char* cidade, int tot);
void MostraGrafo(Vertice* g);
int ProcuraCodVertice(Vertice* g, char* cidade);
Vertice* ProcuraVertice(Vertice* g, char* cidade);

#pragma endregion

#pragma region ADJACENCIAS

Vertice* InsereAdjacenteVertice(Vertice* g, char* origem, char* dest, float peso, bool* res);

#pragma region LISTA_ADJACENCIAS

Adj* CriaAdj(int cod, float peso);
Adj* InsereAdj(Adj* h, Adj* novo, bool* res);
bool ProcuraAdj(Adj* h, int cod);
void MostraAdjacencias(Adj* h);

#pragma endregion
#pragma endregion
