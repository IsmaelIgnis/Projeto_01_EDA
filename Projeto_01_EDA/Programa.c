/*****************************************************************//**
 * \file   Programa.c
 * \brief  
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#include"Dados.h"
#include"Clientes.h"
#include"Gestores.h"
#include"Transportes.h"
#include"Grafos.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese");	//para escrever caracteres portugueses

	static int tot = 0;

#pragma region Lista

	Transportes* novo;
	//analisar valores insridos pela linha de comando
	if (argc > 1) {
		novo = NovoVei(atoi(argv[1]));
	}
	else {
		novo = NovoVei(2);
	}

	//gere lista de veiculos
	Transportes* head = NULL;

	bool res;
	head = InsereVei(head, novo, &res);

	novo = NovoVei(3);
	head = InsereVei(head, novo, &res);

	novo = NovoVei(1);
	head = InsereVei(head, novo, &res);

	MostraLista(head);			//não recursiva


#pragma endregion

#pragma region GRAFOS

	Vertice* graf = CriaGrafo();

	Vertice* novoVertice = CriaVertice("Braga", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Porto", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Famalicão", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	MostraGrafo(graf);		//recursivo

	//Adjacencias
	//Criar ligação "Braga" a "Porto"
	graf = InsereAdjacenteVertice(graf, "Barcelos", "Guimarães", 37, &res);
	graf = InsereAdjacenteVertice(graf, "Barcelos", "Chaves", 143, &res);
	//graf = InsereAdjacenteVertice(graf, tot, "Braga", "Porto", 35, &res);

	MostraGrafo(graf);		//recursivo


#pragma endregion

}




//void main() {
//
//	clientesFileOpen();
//	clientesFileRead();
//	gestoresFileOpen();
//	gestoresFileRead();
//	transportesFileOpen();
//	transportesFileRead();
//
//	//inserirClientes();
//	//inserirGestores();
//	//inserirTansportes();
//
//	//removerClientes();
//	//removerGestores();
//	//removerTransportes();
//}
