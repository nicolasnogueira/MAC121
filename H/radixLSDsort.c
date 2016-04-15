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
////////////////////////////////////////////////////////////// */

/* //////////// ordenacao digital vs heapsort  //////////////////
//
// O programa confere experimentalmente o desempenho das funcoes
// ordenacaoDigital e heapsort (que podem ser encontradas no site
// disponibilizado pelo professor). Testa o tempo de execucao dos
// dois algoritmos para vetores de strings de numeros de 40000,
// 80000, 180000 e 320000 elementos. Tambem executa um teste de
// verificacao para cada funcao a ser testada para verificar se
// os vetores estao ordenados.
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sortfunctions.h"
#include "random.h"

/* Libera o espaco alocado pelo vetor de strings v[0..n-1] */

void desalocar (char **v, int n) {
    int i;
    for (i = 0; i < n; i++)
        free (v[i]);
    free (v);
}

/* Verifica se o vetor v[0..tam-1] de strings esta ordenado 
// lexicograficamente */

int verificarOrdem (char **v, int tam) {
    int i;
    for (i = 0; i + 1 < tam; i++)
        if (strcmp (v[i], v[i + 1]) > 0) return 0;
    return 1;
}

int main () {
    char **v, ordem;
    double inicio, fim;
    int i;
    int tam[4] = {40000, 80000, 160000, 320000};

    printf ("     ALGORITMO    | ORDENACAO | QTD NUMEROS | TEMPO (s)\n");
    printf ("------------------|-----------|-------------|----------\n");

    for (i = 0; i < 4; i++) {
        v = constroiVetorSAleatorio (tam[i]);
        inicio = (double) clock () / CLOCKS_PER_SEC;
        ordenacaoDigital (v, tam[i], 9);
        fim = (double) clock () / CLOCKS_PER_SEC;
        if (verificarOrdem (v, tam[i])) ordem = 'S';
        else ordem = 'N';
        printf (" ordenacaoDigital |     %c     |   %6d    | %f\n",
            ordem, tam[i], fim - inicio);
        desalocar (v, tam[i]);

        v = constroiVetorSAleatorio (tam[i]);
        inicio = (double) clock () / CLOCKS_PER_SEC;
        heapsort (v, tam[i]);
        fim = (double) clock () / CLOCKS_PER_SEC;
        if (verificarOrdem (v, tam[i])) ordem = 'S';
        else ordem = 'N';
        printf ("     heapsort     |     %c     |   %6d    | %f\n",
            ordem, tam[i], fim - inicio);
        desalocar (v, tam[i]);
    }

    return EXIT_SUCCESS;
}