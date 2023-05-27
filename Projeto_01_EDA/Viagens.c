/*****************************************************************//**
 * \file   Viagens.c
 * \brief  
 * 
 * \author Ismael Morais a25964
 * \date   May 2023
 *********************************************************************/

#include"Dados.h"
#include"Transportes.h"
#include"Grafos.h"

/**
 * Inserir Vertice no grafo.
 * 
 * \param g      Grafo
 * \param novo   Novo Vertice
 * \param res    Resultado da operação
 * \return       Grafo alterado
 * \author Ismael Tenda a25964
 */
Vertice* InsereVertice(Vertice* g, Vertice* novo, bool* res) {
	if (g == NULL) {
		g = novo;
		*res = true;
		return g;
	}
	else
	{
		Vertice* aux = g;
		Vertice* ant = aux;
		while (aux && strcmp(aux->cidade, novo->cidade) < 0) {
			ant = aux;
			aux = aux->next;
		}
		if (aux == g) {
			novo->next = g;
			g = novo;
		}
		else
		{
			novo->next = aux;
			ant->next = novo;
		}
		*res = true;
	}
	return g;
}
