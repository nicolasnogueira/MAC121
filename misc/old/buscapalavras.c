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

/*///// Lista de palavras distintas  ////////////////////////////
//
//   O le um arquivo de texto e grava seu dicionario em outro 
//   arquivo de texto e tambem possui o tempo de execucao do
//   programa durante a construcao do dicionario. O dicionario 
//   e gravado em ordem lexicografica e contem apenas palavras em 
//   caixa baixa. O programa supoe que o arquivo nao contem 
//   caracteres fora do alfabeto ASCII e nao contem o caractere 
//   nulo (\0). O arquivo de texto de entrada e o de saida sao 
//   informados nesta ordem atraves de argumentos na linha de 
//   comando na execucao do programa.
//
//   Apos a construcao do dicionario o programa recebe palavras
//   do fluxo de entrada stdin, realiza a consulta no dicionario 
//   e imprime os indices e as palavras correspondentes que sejam
//   as mais proximas no dicionario.
//
//   Terminologia
//
//    palavra:    qualquer sequencia maximal nao vazia de 
//                caracteres alfanumericos com o primeiro
//                caractere sendo uma letra
//
//    dicionario: lista de palavras distintas de um texto (cada
//                palavra aparece uma so vez na lista)
// 
//   Implementacao e estruturas de dados
//
//    1. O dicionario e implementado como uma struct que contem o
//       numero de palavras, um vetor de strings que contem o
//       dicionario propriamente dito, e o tamanho do vetor. A
//       insercao de palavras no dicionario e realizada com a
//       utilizacao de busca binaria.
//
//    2. O arquivo de entrada e lido caractere-a-caractere (nao
//       linha-a-linha). Cada vez que uma palavra e identificada,
//       ela e inserida no dicionario.
//    
//    3. Quando o usuario insere uma palavra a busca, assim como
//       na construcao do dicionario e realizada em forma de
//       busca binaria.
//
///////////////////////////////////////////////////////////////*/

#include <stdio.h>  /* fclose, fopen, fprintf, printf */
#include <stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS, malloc, free */
#include <time.h>   /* clock, CLOCKS_PER_SEC */
#include "bb.h"
#include "dicionario.h"

int main (int argc, char **argv) {
	char *pal;
	Dicionario d;
	FILE *entrada, *saida;
	double inicio, fim, passado;

	inicio = (double) clock () / CLOCKS_PER_SEC;
	if (argc != 3) {
		fprintf (stderr, "USAGE: %s <input> <output>\n", argv[0]);
		return EXIT_FAILURE;
	}
	entrada = fopen (argv[1], "r");
	saida = fopen (argv[2], "w");
	d = criaDicionarioVazio ();
	constroiDicionario (d, entrada);
	fim = (double) clock () / CLOCKS_PER_SEC;
	passado = fim - inicio;
	gravaDicionario (d, saida, passado);
	printf (">");
	pal = proximaPalavra (stdin);
	while (pal[0] != '\0') {
		imprimirResposta (pal, d);
		printf (">");
		pal = proximaPalavra (stdin);
	}
	fclose (saida);
	fclose (entrada);
	free (pal);
	desalocaDicionario (d);
	return EXIT_SUCCESS;
}