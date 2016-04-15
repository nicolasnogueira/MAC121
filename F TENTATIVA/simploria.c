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
// Data: 2015-10-05
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* //// Leia e depois apague este bloco /////////////////////////
//
// 0. O nome deste arquivo e "gabarito.c". Mude o nome para algo
//    mais apropriado.
// 1. Escreva um comentario no inicio para dizer _o_que_ o
//    programa faz.
// 2. Antes de cada funcao, escreva um comentario para dizer
//    _o_que_ a funcao faz.
// 3. Evite ser acusado de plagio. Se copiar uma funcao ou trecho
//    de codigo de algum livro ou pagina da Internet, cite a 
//    fonte explicitamente.
// 4. Nao escreva nenhum outro comentario.
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include "simploria.h"

#define TRUE 1

void constroiVetorS (FILE *arqs[], int *simpl, char *arg[], int k,
    int *arqval, int *f) {
    int j;
    for (j = 1; j <= k; j++) {
        arqs[j] = fopen (arg[j + 1], "r");
        atualizarVetor (arqs, j, simpl, arqval, f);
    }
}

void ordenar (FILE *arqs[], int *arqval, int *simpl, FILE *saida,
    int k, int *f, int *totalnum) {
    int menor, j, menorj = 0;

    while (*f != k) {       
        j = 1;
        while (arqval[j] != 1)
            j++;
        menor = simpl[j];
        /*printf ("Menor da rodada %d", menor);*/
        while (j <= k) {
            if (simpl[j] <= menor && arqval[j] == 1) {
                menorj = j;
                menor = simpl[j];
            }
            j++;
        }
        /* menor é o menor valor do vetor simpl[0...i-1]*/
        fprintf (saida, "%d\n", simpl[menorj]);
        *totalnum = *totalnum + 1;
        /*printf("Coloquei no arquivo %d %d\n", menor, simpl[menorj]);
        printf("Atualizando vetor %d\n", menorj);
        printf("%d - ", simpl[menorj]);*/
        atualizarVetor (arqs, menorj, simpl, arqval, &*f);
        /*printf("%d\n", simpl[menorj]);*/
    }
    for (j = 1; j <= k; j++)
        fclose (arqs[j]);
}

void atualizarVetor (FILE *arqs[], int j, int *simpl, int *arqval, int *f) {
    arqval[j] = fscanf (arqs[j], "%d", &simpl[j]);
    /*printf("%d %d %d \n", j, arqval[j], simpl[j]);*/
    if (feof(arqs[j])) {
        *f = *f + 1;
        /*printf("Acabou algum arquivo!, %d", *f);  */     
    }

}
