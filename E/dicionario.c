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

/*///// Modulo dicionario  //////////////////////////////////////
//
//   O modulo dicionario e baseado no gabarito da tarefa D
//   retirado no sitio disponibilizado pelo professor. O modulo
//   concentra funcoes que sao utilizadas na construcao e
//   manipulacao do dicionario e extracao de palavras de arquivo
//   de texto. 
//  
///////////////////////////////////////////////////////////////*/

/*///////////////////////////////////////////////////////////////
//
//   Constantes, tipos de dados, e prototipos de funcoes
//
///////////////////////////////////////////////////////////////*/

#include <ctype.h>  /* isalnum, isalpha, tolower */
#include <stdio.h>  /* EOF, FILE, fprintf, getc */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcmp, strcpy, strlen */
#include "dicionario.h"
#include "bb.h"

Dicionario criaDicionarioVazio (void);
void constroiDicionario (Dicionario d, FILE *entrada);
char *proximaPalavra (FILE *entrada);
void inserePalavra (char *pal, Dicionario d) ;
void gravaDicionario (Dicionario d, FILE *saida, double tempo);
void expandeDicionario (Dicionario d);
void desalocaDicionario (Dicionario d);

/*///////////////////////////////////////////////////////////////
//                                                             
//   Variaveis
//
///////////////////////////////////////////////////////////////*/

/*///////////////////////////////////////////////////////////////
// Numero total de palavras lidas (contando as repeticoes). 
///////////////////////////////////////////////////////////////*/

int total; 

/*///////////////////////////////////////////////////////////////
//
//   Funcoes
//
///////////////////////////////////////////////////////////////*/

Dicionario criaDicionarioVazio (void) {
	Dicionario d;
	d = malloc (sizeof *d);
	d->N = 16;
	d->dic = malloc (d->N * sizeof (char *));
	d->n = 0; 
	return d;
}

void constroiDicionario (Dicionario d, FILE *entrada) {
	char *pal;
	total = 0;
	while ((pal = proximaPalavra (entrada)) != NULL) {
		int i;
		total++;
		for (i = 0; pal[i] != '\0'; i++) 
			pal[i] = tolower (pal[i]);
		inserePalavra (pal, d);
	}
}

char *proximaPalavra (FILE *entrada) {
	int i, c;
	char *pal;
	int B;
	char *buffer;
   /* pula caracteres que nao sao letras*/
	do {
		c = getc (entrada);
		if (c == EOF) return NULL;
	} while (!isalpha (c));
   /* le uma palavra */
	B = 4;
	buffer = malloc (B);
	i = 0;
	do {
		buffer[i++] = c;
		if (i >= B) {
         /* dobra a capacidade do buffer */
			int i;
			char *novobuffer = malloc (2 * B);
			for (i = 0; i < B; i++)
				novobuffer[i] = buffer[i];
			free (buffer);
			B *= 2;
			buffer = novobuffer;
		}
		c = getc (entrada);
	} while (c != EOF && isalnum (c));
	buffer[i] = '\0';
	pal = malloc (strlen (buffer) + 1);
	strcpy (pal, buffer);
	free (buffer);
	return pal;
}

void inserePalavra (char *pal, Dicionario d) {
	int i, j;
	i = buscaBinaria (pal, d);
    /* d->dic[i] > i lexicograficamente caso i<d->n */
	if (i >= d->n || strcmp (d->dic[i], pal) > 0) {
		if (d->n == d->N) 
			expandeDicionario (d);
		for (j = d->n - 1; j >= i; j--) 
			d->dic[j + 1] = d->dic[j];
		d->dic[i] = pal;
		d->n += 1;
	} else free (pal);
}

void expandeDicionario (Dicionario d) {
	char **novodic;
	int i;
	novodic = malloc (2 * d->N * sizeof (char *));
	for (i = 0; i < d->N; i++) 
		novodic[i] = d->dic[i];
	free (d->dic);
	d->dic = novodic;
	d->N *= 2;
}

void gravaDicionario (Dicionario d, FILE *saida, double tempo) {
	int i;
	for (i = 0; i < d->n; i++) 
		fprintf (saida, "%s\n", d->dic[i]);
	fprintf (saida, "\n");
	fprintf (saida, "Tempo gasto na execucao "
        "da fase 1: %.20f\n", tempo);
}

void desalocaDicionario (Dicionario d) {
	int i;
	for (i = 0; i < d->n; i++) free (d->dic[i]);
	free (d->dic);
	free (d);
}
