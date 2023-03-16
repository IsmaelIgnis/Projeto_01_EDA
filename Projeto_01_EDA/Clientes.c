/*****************************************************************//**
 * \file   Clientes.c
 * \brief  Tudo sobre os clientes
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<stdbool.h>
#include"Dados.h"

void inserirClientes(Clientes** inicio, char nome[], char nif[], double saldo, char morada[]) {
    Clientes* novoClientes = (Clientes*)malloc(sizeof(Clientes)); // alocando memória para o novo nó da lista
    strcpy(novoClientes->nome, nome);
    strcpy(novoClientes->nif, nif);
    novoClientes->saldo = saldo;
    strcpy(novoClientes->morada, morada);
    novoClientes->prox = NULL;

    if (*inicio == NULL) { // caso a lista esteja vazia
        *inicio = novoClientes;
    }
    else { // caso contrário, insere o novo nó no final da lista
        Clientes* atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoClientes;
    }
}

bool clientesFile(Clientes** inicio, char nome[], char nif[], double saldo, char morada[]) {
    FILE* util;

    util = fopen("Clinetes.txt", "w");

    if (util != NULL) {
        fprintf(util, "AA\n");

        if (*inicio == NULL) { // caso a lista esteja vazia
            return false;
        }
        else { // caso contrário, insere o novo nó no final da lista
            Clientes* atual = *inicio;
            fprintf(util, "%s %s %lf %s\n", nome[50], nif[10], saldo, morada[100]);
            while (atual->prox != NULL) {
                atual = atual->prox;
            }
            
        }


        fclose(util);
    }
    else {
        printf("Erro ao abrir o ficheiro.\n");
    }

}
