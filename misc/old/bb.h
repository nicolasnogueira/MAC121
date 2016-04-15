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
// Data: 2015-09-21
// 
// Este arquivo faz parte da tarefa E
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#ifndef BB_H
#define BB_H

#include "dicionario.h"

/*///// buscaBinaria ////////////////////////////////////////////
//
//   Realiza a busca da palavra pal no dicionario d e retorna o
//   indice i tal que d->dic[i] é sempre maior ou igual que a  
//   palavra pal lexicograficamente. Caso i = d->n, entao a 
//   ultima palavra do dicionario e lexicograficamente menor que 
//   a palavra pal.
//
///////////////////////////////////////////////////////////////*/

int buscaBinaria (char *pal, Dicionario d);

/*///// imprimirResposta ////////////////////////////////////////
//
//   Imprime a saida adequada para a palavra palUsuario de acordo
//   com a busca no dicionario d.
//
///////////////////////////////////////////////////////////////*/

void imprimirResposta (char *palUsuario, Dicionario d);

#endif
