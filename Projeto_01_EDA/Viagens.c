/*****************************************************************//**
 * \file   Viagens.c
 * \brief  O codigo deste ficheiro foi adaptado do codigo disponibilizado pelo professor.
 * 
 * \author Ismael Morais a25964
 * \date   May 2023
 *********************************************************************/

#include"Dados.h"
#include"Transportes.h"
#include"Grafos.h"




#pragma region GRAFO


/**
 * Inicia um Grafo Pesado, N�o Orientado.
 * 
 * \return   
 * \author Ismael Tenda a25964
 */
Vertice* CriaGrafo() {
	return NULL;
}

/**
 * Cria v�rtice para o grafo.
 * 
 * \param cidade   //!< nome da Cidade do V�rtice
 * \param cod   
 * \return   
 * \author Ismael Tenda a25964
 */
Vertice* CriaVertice(char* cidade, int cod) {
	Vertice* novo = (Vertice*)calloc(1, sizeof(Vertice));
	if (novo == NULL) return NULL;
	novo->cod = cod;
	strcpy(novo->cidade, cidade);
	novo->next = NULL;
	return novo;
}

/**
 * Inserir Vertice no grafo.
 * 
 * \param  g      Grafo
 * \param  novo   Novo Vertice
 * \param  res    Resultado da opera��o
 * \return        Grafo alterado
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

/**
 * Apresenta grafo.
 * 
 * \param g   
 * \author Ismael Tenda a25964
 */
void MostraGrafo(Vertice* g) {
	if (g == NULL) return;
	printf("V: %d - %s\n", g->cod, g->cidade);
	MostraAdjacencias(g->adjacentes);
	MostraGrafo(g->next);
}

/// @brief Verifica qual o c�digo do vertice de uma determinada cidade
/// @param g 
/// @param cidade 
/// @return 
int ProcuraCodVertice(Vertice* g, char* cidade) {
	if (g == NULL) return -1;
	if (strcmp(g->cidade, cidade) == 0) return g->cod;
	return(ProcuraCodVertice(g->next, cidade));
}

/**
 * \Brief .
 * 
 * \param g   
 * \param cidade   
 * \return   
 * \author Ismael Tenda a25964
 */
Vertice* ProcuraVertice(Vertice* g, char* cidade) {
	if (g == NULL) return NULL;
	if (strcmp(g->cidade, cidade) == 0) return g;
	return(ProcuraVertice(g->next, cidade));
}

#pragma endregion

#pragma region ADJACENCIAS

/**
 * \Brief Cria novo nodo de adjec�ncia.
 * 
 * \param cod   
 * \param peso   
 * \return   
 * \author Ismael Tenda a25964
 */
Adj* CriaAdj(int cod, float peso) {
	Adj* novo = (Adj*)calloc(1, sizeof(Adj));
	if (novo == NULL) return NULL;
	novo->cod = cod;
	novo->dist = peso;
	novo->next = NULL;
	return novo;
}

/**
 * \Brief Insere nova adjec�ncia no grafo.
 * 
 * \param g       Grafo
 * \param origem  Nome de Vertice origem
 * \param dest    Nome de Vertice destino
 * \param peso    Peso
 * \param res     Resultado da opera��o
 * \return        Grafo alterado
 * \author Ismael Tenda a25964
 */
Vertice* InsereAdjacenteVertice(Vertice* g, char* origem, char* dest, float peso, bool* res)
{
	*res = false;				//por defeito � falso

	if (g == NULL) return g;	//<! se grafo est� vazio, ignora opera��o

	Vertice* aux = ProcuraVertice(g, origem); // g;			//<! procura vertice origem
	/*while (auxO && strcmp(auxO->cidade,origem)!=0) {
		auxO = auxO->next;
	}*/

	int cod = ProcuraCodVertice(g, dest);

	if (aux == NULL || cod < 0) return g;	//<! Se n�o encontrou vertice origem e destino, ignora opera��o


	if (ProcuraAdj(aux->adjacentes, cod) == true) return g; //Se j� foi registado esta adjacencia, ignorar a opera��o

	//Insere nova adjacencia no vertice "Origem"
	Adj* novoAdj = CriaAdj(cod, peso);
	aux->adjacentes = InsereAdj(aux->adjacentes, novoAdj, res);

	//Insere caminho inverso, pois � n�o orientado...recursivamente!
	return (InsereAdjacenteVertice(g, dest, origem, peso, res));


}

#pragma region LISTA_ADJACENCIAS


/**
 * \Brief Insere novo adjacente de um vertice
 *        N�o admite vertices repetido.
 * 
 * \param h   
 * \param novo   
 * \param res   
 * \return   
 * \author Ismael Tenda a25964
 */
Adj* InsereAdj(Adj* h, Adj* novo, bool* res) {

	*res = false;		//por defeito � falso

	if (novo == NULL)	//Se novo adjacente � nulo, ignora opera��o
		return h;

	if (ProcuraAdj(h, novo->cod) == true) return h; // Se novo adj existe, ignorar opera��o

	// Inserir nova adjacencia!
	*res = true;
	if (h == NULL) {	//Se lista de adjacencias � vazia, esta � a primeira adjacencia
		h = novo;
		return h;
	}
	//sen�o insere no in�cio das adjac�ncias! Podia ser de outra forma!
	novo->next = h;
	h = novo;

	return h;
}

/**
 * @brief Mostra lista de adjacentes.
 *
 * @param h
 * @author lufer
 *
 */
/**
 * \Brief Mostra lista de adjacentes.
 * 
 * \param h   
 * \author Ismael Tenda a25964
 */
void MostraAdjacencias(Adj* h) {
	if (h == NULL) return;
	printf("\tAdj: %d - (%.0f)\n", h->cod, h->dist);
	MostraAdjacencias(h->next);
}

#pragma endregion

#pragma endregion

