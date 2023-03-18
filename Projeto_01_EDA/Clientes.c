/*****************************************************************//**
 * \file   Clientes.c
 * \brief  Tudo sobre os clientes.
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdbool.h>
#include"Dados.h"

//int inserirClientes() {
//
//}


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

/** L� os ficheiros "CLIENTE.txt" e "CLIENTES.bin" */
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
