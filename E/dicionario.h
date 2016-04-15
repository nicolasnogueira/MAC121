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

#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <stdio.h> /* FILE */

/*///////////////////////////////////////////////////////////////
// O dicionario e representado por uma struct com tres campos:
// o numero n de palavras, um vetor de strings dic[0..n-1],
// e a capacidade total N do vetor dic.
///////////////////////////////////////////////////////////////*/

typedef struct {
    char **dic;
    int    n, N;
} *Dicionario;

/*///// criaDicionarioVazio /////////////////////////////////////
//
//   Cria um dicionario vazio.                                    
//
///////////////////////////////////////////////////////////////*/

Dicionario criaDicionarioVazio (void);

/*///// constroiDicionario //////////////////////////////////////
//
//   Popula o dicionario d com as palavras do arquivo entrada.                           
//
///////////////////////////////////////////////////////////////*/

void constroiDicionario (Dicionario d, FILE *entrada);

/*///// proximaPalavra //////////////////////////////////////////
//
//   Devolve a proxima palavra do arquivo entrada. Se o
//   arquivo estiver esgotado, devolve NULL.                          
//
///////////////////////////////////////////////////////////////*/

char *proximaPalavra (FILE *entrada);

/*///// inserePalavra ///////////////////////////////////////////
//
//   Tenta inserir a string pal no dicionario d. Se pal ja 
//   estiver no dicionario, desiste da insercao. O dicionario  
//   permanece em ordem lexicografica (se estiver em ordem  
//   lexicografica antes da insercao).                         
//
///////////////////////////////////////////////////////////////*/

void inserePalavra (char *pal, Dicionario d);

/*///// gravaDicionario /////////////////////////////////////////
//
//   Grava as palavras do dicionario d no arquivo saida e o tempo 
//   de execucao da construcao do dicionario no final do arquivo.         
//
///////////////////////////////////////////////////////////////*/

void gravaDicionario (Dicionario d, FILE *saida, double tempo);

/*///// expandeDicionario ///////////////////////////////////////
//
//   Expande o dicionario d de modo que o vetor de strings d->dic
//   fique com o dobro da capacidade.                       
//
///////////////////////////////////////////////////////////////*/

void expandeDicionario (Dicionario d);

/*///// desalocaDicionario //////////////////////////////////////
//
//   Libera o espaco ocupado pelo dicionario d.              
//
///////////////////////////////////////////////////////////////*/

void desalocaDicionario (Dicionario d);

#endif