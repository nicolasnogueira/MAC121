/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Nicolas Nogueira Lopes da Silva
// Numero USP: 9277541
// Sigla: NICOLASN
// Data: 2015-10-13
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
//
// Este programa consiste em uma biblioteca de algoritmos de 
// ordenacao de vetores de numeros inteiros e tambem possui este 
// modulo principal de teste que ordena um vetor com 40000 numeros
// pseudoaleatorios e entao e verificado se este vetor se encontra
// em ordem crescente para cada algoritmo de ordenacao da 
// biblioteca.
//
////////////////////////////////////////////////////////////// */

#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

/* A funcao testaOrdem verifica se o vetor v[0..n-1] se encontra
// organizado em ordem crescente retornando 1 caso esteja e 0 caso
// contrario */

int testaOrdem (int *v, int n) {
    int i;
    for (i = 0; i + 1 < n; i++) {
        if (v[i + 1] < v[i])
            return 0;
    }
    return 1;
}

/* A funcao construirVetorAleatorio constroi um vetor v[0..n-1]
// de valores inteiros pseudoaleatorios retornando o ponteiro
// deste vetor */

int *construirVetorAleatorio (int n) {
    int *v, i;
    v = malloc (n * sizeof (int));
    for (i = 0; i < n; i++)
        v[i] = rand ();
    return v;
}

int main (void) {
    int n, *v, verf;
    n = 40000;
    verf = 1;

    v = construirVetorAleatorio (n);
    mergesort (v, n);
    verf *= testaOrdem (v, n);
    free (v);

    v = construirVetorAleatorio (n);
    insercao (v, n);
    verf *= testaOrdem (v, n);
    free (v);

    v = construirVetorAleatorio (n);
    quicksort (v, n);
    verf *= testaOrdem (v, n);
    free (v);

    v = construirVetorAleatorio (n);
    heapsort (v, n);
    verf *= testaOrdem (v, n);
    free (v);

    if (verf) return EXIT_SUCCESS;
    else {
        fprintf (stderr, "Erro de ordenacao.\n");
        return EXIT_FAILURE;       
    } 
}