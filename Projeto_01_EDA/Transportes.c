/*****************************************************************//**
 * \file   Transportes.c
 * \brief  Tudo sobre os transportes.
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#include"Dados.h"
#include"Transportes.h"

/** Abre os ficheiros "TRANSPORTE.txt" e "TRANSPORTES.bin" */
bool transportesFileOpen() {
    FILE* fp;
    FILE* fps;

#pragma region FICHEIRO_TXT

    fp = fopen("TRANSPORTE.txt", "w");
    if (fp == NULL)
    {
        return false;
    }
    fclose(fp);

#pragma endregion

#pragma region FICHEIRO_BIN

    fps = fopen("TRANSPORTES.bin", "w");
    if (fps == NULL)
    {
        return false;
    }
    fclose(fps);

#pragma endregion

    return true;
}

/** Lê os ficheiros "TRANSPORTE.txt" e "TRANSPORTES.bin" */
bool transportesFileRead() {
    FILE* fp;
    FILE* fps;

#pragma region FICHEIRO_TXT

    fp = fopen("TRANSPORTE.txt", "r");
    if (fp == NULL)
    {
        return false;
    }
    fclose(fp);

#pragma endregion

#pragma region FICHEIRO_BIN

    fps = fopen("TRANSPORTES.bin", "rb");
    if (fps == NULL)
    {
        return false;
    }
    fclose(fps);

#pragma endregion

    return true;
}
