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
// Data: 2015-11-02
// 
// Este arquivo faz parte da tarefa H
// da disciplina MAC0121.
//
// Este modulo implementa a interface random.h
// 
////////////////////////////////////////////////////////////// */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN 100000000
#define MAX 999999999

/* A função numeroAleatorio devolve um inteiro 
// aleatório entre low e high inclusive,
// ou seja, no intervalo fechado low..high.
// Vamos supor que 0 <= low <= high < RAND_MAX.
// (O código foi copiado da biblioteca random de
// Eric Roberts.) */

static int numeroAleatorio (int low, int high) {
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

char **constroiVetorSAleatorio (int n) {
    char **v;
    int i;
    v = (char **) malloc (n * sizeof (char *));
    for (i = 0; i < n; i++) 
        v[i] = (char *) malloc (9 * sizeof (char));
    srand (time (NULL));
    for (i = 0; i < n; i++)
        sprintf (v[i], "%d", numeroAleatorio (MIN, MAX));
    return v;
}
