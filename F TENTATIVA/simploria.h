#ifndef SIMPLORIA_H
#define SIMPLORIA_H

#include <stdio.h>

void constroiVetorS (FILE *arqs[], int *simpl, char *arg[], int k,
	int *arqval, int *f);

void ordenar (FILE *arqs[], int *arqval, int *simpl, FILE *saida,
    int k, int *f, int *totalnum);

void atualizarVetor (FILE *arqs[], int j, int *simpl, int *arqval,
	int *f);

#endif