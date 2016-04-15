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
// Esta e a interface do modulo random, que possui a funcao para
// construir um vetor de strings de numeros aleatorios.
//
////////////////////////////////////////////////////////////// */

#ifndef _RANDOM_H
#define _RANDOM_H

/* A funcao construirVetorAleatorio constroi um vetor v[0..n-1]
// de strings de numeros pseudoaleatorios retornando o ponteiro
// deste vetor */

char **constroiVetorSAleatorio (int n);

#endif