/*****************************************************************//**
 * \file   Clientes.c
 * \brief  Tudo sobre os clientes.
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#include"Dados.h"

/** Cria a lista */
ClientesLista* criarCliente(Clientes *c, char nome[], double saldo, char nif[], char morada[]) {
    ClientesLista* novoCliente = (ClientesLista*)malloc(sizeof(ClientesLista));
    
    strcpy(novoCliente->cliente.nome, "Tenda");
    novoCliente->cliente.nif, 4356789;
    novoCliente->cliente.saldo = 40;
    strcpy(novoCliente->cliente.morada, "Sao Joao");

    novoCliente->cliente = *c;
    novoCliente->next = NULL;
    return novoCliente;
}




/** Abre os ficheiros "CLIENTE.txt" e "CLIENTES.bin" */
bool clientesFileOpen() {
    FILE* fp;
    FILE* fps;

#pragma region FICHEIRO_TXT

    fp = fopen("CLIENTE.txt", "w");
    

    
    fclose(fp);

#pragma endregion

#pragma region FICHEIRO_BIN

    fps = fopen("CLIENTES.bin", "wb");
    if (fps == NULL)
    {
        return false;
    }
    fclose(fps);

#pragma endregion

    return true;
}

/** Lê os ficheiros "CLIENTE.txt" e "CLIENTES.bin" */
bool clientesFileRead() {
    FILE* fp;
    FILE* fps;

#pragma region FICHEIRO_TXT

    fp = fopen("CLIENTE.txt", "r");
    if (fp == NULL)
    {
        return false;
    }
    fclose(fp);

#pragma endregion

#pragma region FICHEIRO_BIN

    fps = fopen("CLIENTES.bin", "rb");
    if (fps == NULL)
    {
        return false;
    }
    fclose(fps);

#pragma endregion

    return true;
}
