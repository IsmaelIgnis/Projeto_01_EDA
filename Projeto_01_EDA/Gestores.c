/*****************************************************************//**
 * \file   Gestores.c
 * \brief  Tudo sobre os gestores.
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdbool.h>
#include"Dados.h"

/** Abre os ficheiros "GESTORE.txt" e "GESTORES.bin" */
bool gestoresFileOpen() {
    FILE* fp;
    FILE* fps;

    fp = fopen("GESTORE.txt", "w");

    if (fp == NULL)
    {
        return false;
    }
    fclose(fp);

    fps = fopen("GESTORES.bin", "wb");
    if (fps == NULL)
    {
        return false;
    }
    fclose(fps);


    return true;
}

/** Lê os ficheiros "GESTORE.txt" e "GESTORES.bin" */
bool gestoresFileRead() {
    FILE* fp;
    FILE* fps;

    fp = fopen("GESTORE.txt", "r");

    if (fp == NULL)
    {
        return false;
    }
    fclose(fp);

    fps = fopen("GESTORES.bin", "rb");
    if (fps == NULL)
    {
        return false;
    }
    fclose(fps);


    return true;
}
