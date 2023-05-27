/*****************************************************************//**
 * \file   Transportes.c
 * \brief  Tudo sobre os transportes.
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#include"Dados.h"
#include"Transportes.h"
#include"Grafos.h"


Transportes* NovoVei(int i) {
    Transportes* n = (Transportes*)calloc(1, sizeof(Transportes));
    if (n == NULL) return NULL;
    n->codR = i;
    n->next = NULL;
}

Transportes* InsereVei(Transportes* h, Transportes* novo, bool* res) {
    if (h == NULL) {
        h = novo;
        *res = true;
        return h;
    }
    else {
        Transportes* aux = h;
        Transportes* ant = aux;
        while (aux->codR < novo->codR) {
            ant = aux;
            aux = aux->next;
        }
        if (aux == h) {
            novo->next = h;
            h = novo;
        }
        else {
            novo->next = aux;
            ant->next = novo;
        }
        *res = true;
    }
    return h;
}

void MostraLista(Transportes* h) {
    if (h == NULL) return;
    Transportes* aux = h;
    while (aux) {
        printf("V: %d\n", aux->codR);
        aux = aux->next;
    }
}



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
