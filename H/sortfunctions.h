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
// Esta e a interface do modulo sortfunctions, que possui as
// funcoes de ordenacao a serem comparadas na tarefa, a de 
// ordenacaoDigital e a funcao heapsort. As funcoes de ordenacao
// realizam a ordenacao de vetores de strings.
// 
////////////////////////////////////////////////////////////// */

#ifndef _SORTFUNCTIONS_H
#define _SORTFUNCTIONS_H

/* Rearranja em ordem lexicográfica um vetor v[0..n-1] 
// de strings de comprimento w sobre o alfabeto ASCII. */

void ordenacaoDigital (char *v[], int n, int w);

/* A função heapsort rearranja o vetor v[0..n-1]
// em ordem crescente. */

void heapsort (char **v, int n);

#endif