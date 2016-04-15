#ifndef SOFISTICADA_H
#define SOFISTICADA_H

#include <stdio.h>

typedef struct cel{
    int i, num;
} celula;

void constroiVetorH (FILE *arqs[], celula *c, char *arg[], int k, 
    int *arqval, int *f);

void constroiHeap (int n, celula v[]);

void inserirElemento (celula v[], int j, int num, int *k);

void ordenarH (FILE *arqs[], celula *c, int tam, int *arqval, 
    int *f, int *totalnum, FILE *saida);

int removerMenor (celula v[], int *k, int *menorj);

void peneira (int p, int m, celula v[]);

void proxNum (FILE *arqs[], int j, int *arqval, int *f, int *n);

#endif