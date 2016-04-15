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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "simploria.h"
#include "sofisticada.h"

#define TRUE 1
#define DEBUG 1

int verifica (FILE *arquivo, int totalnum) {
    int cont, k, num;
    cont = 0;
    while (TRUE) {
        k = fscanf (arquivo, "%d", &num);
        if (k != 1) break;
        cont++;
    }
    if (totalnum == cont)  
        return 1;
    else
        return 0;
}

int main (int numargs, char *arg[]) {
    int *simpl, *arqval, k, f, totalnum;
    FILE *saida;
    FILE **arquivos;
    celula *c;
    k = numargs - 3;
    f = 0;
    totalnum = 0;
    saida = fopen (arg[numargs - 1], "w");

    arquivos = malloc ((k + 1) * sizeof (FILE *));
    arqval = malloc ((k + 1) * sizeof (int));

    if (strcmp (arg[1], "-h") == 0) {
        printf("oi");
        c = malloc ((k + 1) * sizeof (celula));
        constroiVetorH (arquivos, c, arg, k, arqval, &f);
        constroiHeap (k, c);
        ordenarH (arquivos, c, k, arqval, &f, &totalnum, saida);
    } else {
        simpl = malloc ((k + 1) * sizeof (int));
        constroiVetorS (arquivos, simpl, arg, k, arqval, &f);
        ordenar (arquivos, arqval, simpl, saida, k, &f, &totalnum);
    }

    fclose (saida);
    saida = fopen (arg[numargs - 1], "r");
    if (DEBUG) {
        if (verifica (saida, totalnum))
            printf ("SAÍDA OK\n");
        else
            printf ("SAÍDA COM PROBLEMA!\n");
    }
    fclose (saida);

    return EXIT_SUCCESS;

}

