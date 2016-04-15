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
// Este modulo implementa a interface sortfunctions.h
//
// As funcoes utilizadas aqui foram baseadas nas funcoes do site
// disponibilizado pelo professor para a execucao da tarefa.
// 
////////////////////////////////////////////////////////////// */

#include <stdlib.h>
#include <string.h>

void ordenacaoDigital (char *v[], int n, int w) {
    int d, i, r;
    int R = 10;
    int *fp;
    char **aux;
    fp = malloc ((R + 1) * sizeof (int));
    aux = malloc (n * sizeof (char *));
    for (d = w - 1; d >= 0; d--) {
        for (r = 0; r <= R; r++) 
            fp[r] = 0;
        for (i = 0; i < n; i++) 
            fp[v[i][d] + 1 - '0'] += 1; 
        for (r = 1; r <= R; r++) 
            fp[r] += fp[r-1]; 
        for (i = 0; i < n; i++) {
            aux[fp[v[i][d] - '0']] = v[i]; 
            fp[v[i][d] - '0']++; 
        }
        for (i = 0; i < n; i++) 
            v[i] = aux[i];
    }

    free (fp);
    free (aux);
}

/* Recebe p em 1..m e rearranja o vetor v[1..m] de 
// modo que o "subvetor" cuja raiz é p seja um heap.
// Supõe que os "subvetores" cujas raízes são filhos
// de p já são heaps. */

static void peneira (int p, int m, char *v[]) { 
    int f = 2*p;
    char *x = v[p];
    while (f <= m) {
        if (f < m && strcmp (v[f], v[f + 1]) < 0)  ++f;
        if (strcmp (x, v[f]) >= 0) break;
        v[p] = v[f];
        p = f, f = 2*p;
    }
    v[p] = x;
}

/* Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente.*/

static void heapsortS (int n, char *v[]) {
    int p, m;
    char *x;
    for (p = n/2; p >= 1; --p)
        peneira (p, n, v);
    /* agora v[1..n] é um heap */
    for (m = n; m >= 2; --m) {
        x = v[1], v[1] = v[m], v[m] = x;
        peneira (1, m - 1, v);
    }
}

void heapsort (char **v, int n) {
    heapsortS (n, v - 1);
}
