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
