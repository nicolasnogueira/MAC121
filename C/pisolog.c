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
// Data: 2015-08-18
// 
// Este arquivo faz parte da tarefa C
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* //// Programa pisolog ////////////////////////////////////////
//
//   O programa recebe dois parametros do tipo int pela linha de 
//   comando: B e K, e para dados valores exibe uma tabela do 
//   piso de log N sendo N todas as potencias de B ate o expoente
//   K enquanto nao ocorrer overflow aritmetico.
//
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* //// Função pisolog //////////////////////////////////////////
//
//   A função logN recebe um inteiro N estritamente positivo, ou
//   seja, N > 0 e devolve o piso de log N na base 2.
//
////////////////////////////////////////////////////////////// */

int pisolog (int N) {
    int lg = 0;
    while (N > 1) {
        N = N / 2;
        lg++;
    }
    return lg;
}

int main (int numargs, char *arg[]) {
    int B, K, i, N;
    B = atoi (arg[1]);
    K = atoi (arg[2]);
    N = 1;
    for (i = 1; i <= K && INT_MAX / B >= N; i++) {
        /* N inicialmente e o elemento para o qual foi calculado 
        // o pisolog na iteracao anterior (inicialmente vale 1)*/
        N = B * N;
        printf ("%10d %5d \n", N, pisolog (N));
    }
    return EXIT_SUCCESS; 
}


TRÊS TIPOS DE SAÍDA
a () (0, balde) tem q devolver -1
balde (0, balde) (1, seila)valores de 0 a n-2 CERTO
z (80, z) () n-1

