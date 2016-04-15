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

/*///// Modulo bb ///////////////////////////////////////////////
//
//   O modulo bb concentra funcoes relacionadas a busca binaria
//   utilizadas no programa tanto na construcao do dicionario
//   quanto na busca de palavras pelo usuario.
//  
///////////////////////////////////////////////////////////////*/

/*///////////////////////////////////////////////////////////////
//
//   Prototipo de funcoes
//
///////////////////////////////////////////////////////////////*/

#include <string.h> /* strcmp */
#include <stdlib.h> /* free */
#include <stdio.h>  /* printf */
#include "bb.h"

int buscaBinaria (char *pal, Dicionario d);
void imprimirResposta (char *palUsuario, Dicionario d);

/*///////////////////////////////////////////////////////////////
//
//   Funcoes
//
///////////////////////////////////////////////////////////////*/

int buscaBinaria (char *pal, Dicionario d) {
	int e, m, dir;
	e = 0; dir = d->n - 1;
	while (e <= dir) {
		m = (e + dir)/2;
		if (strcmp (pal, d->dic[m]) == 0) return m;
		if (strcmp (pal, d->dic[m]) > 0) e = m + 1;
		else dir = m - 1;
	}
	if (e > dir) return e;
	else return dir;
}

void imprimirResposta (char *palUsuario, Dicionario d) {
	int i;
	i = buscaBinaria (palUsuario, d);
	if (i == 0 && strcmp (palUsuario, d->dic[i]) != 0)
		/* a palavra e menor que todas do dicionario */
		printf ("() (%d, %s)\n", i, d->dic[i]);
	else if (i >= d->n - 1 && strcmp (palUsuario, d->dic[d->n - 1]) >= 0)
		/* a palavra e maior que todas do dicionario */
		printf ("(%d, %s) ()\n", d->n - 1, d->dic[d->n - 1]);
	else if (strcmp (palUsuario, d->dic[i]) == 0)
		/* a palavra existe no dicionario */
		printf ("(%d, %s) (%d, %s)\n",
			i, d->dic[i], i + 1, d->dic[i + 1]);
	else
		/* a palavra se encontra entre duas palavras do
		dicionario, mas nao existe nele */
		printf ("(%d, %s) (%d, %s)\n",
			i - 1, d->dic[i - 1], i, d->dic[i]);
	free (palUsuario);
}