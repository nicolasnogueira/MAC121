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
// Esta e a interface do modulo ordenacao, que possui diversas
// funcoes contendo diferentes implementacoes de algoritmos de 
// ordenacao de um vetor de inteiros.
//
////////////////////////////////////////////////////////////// */

#ifndef _ORDENACAO_H
#define _ORDENACAO_H

/* A função mergesort rearranja o vetor v[0..n-1]
// em ordem crescente. 
// O consumo de tempo e proporcional a n*log n*/

void mergesort (int *v, int n);

/* A função insercao rearranja o vetor v[0..n-1]
// em ordem crescente. 
// O consumo de tempo e proporcional a n^2 */

void insercao (int *v, int n);

/* A função quicksort rearranja o vetor v[0..n-1]
// em ordem crescente. 
// O consumo do tempo em media e n*log n */

void quicksort (int *v, int n);

/* A função heapsort rearranja o vetor v[0..n-1]
// em ordem crescente. 
// O consumo de tempo e proporcional a n*log n */

void heapsort (int *v, int n);

#endif