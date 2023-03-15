/*****************************************************************//**
 * \file   Programa.c
 * \brief  
 * 
 * \author Ismael Morais a25964
 * \date   March 2023
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

void main() {
	FILE* util;
	
	util = fopen("Clinete.txt", "w");

	if (util != NULL) {
		fprintf(util, "hytgfivjh\n");
		fputs("23\n", util);

		fclose(util);
	}
	else {
		printf("Erro ao abrir o ficheiro.\n");
	}

}
