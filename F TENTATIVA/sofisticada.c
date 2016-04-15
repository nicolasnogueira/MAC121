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

#include <stdio.h>
#include "sofisticada.h"


void constroiVetorH (FILE *arqs[], celula *c, char *arg[], int k, 
    int *arqval, int *f) {
    printf("%d", k);
    int j;
    for (j = 1; j <= k; j++) {
        printf("abriu!");
        arqs[j] = fopen (arg[j + 1], "r");
        c[j].i = j;
        proxNum (arqs, j, arqval, f, &c[j].num);
    }
}

void constroiHeap (int k, celula *v) {
    int p;
    for (p = k/2; p >=1; p--)
        peneira (p, k, v);
}


void inserirElemento (celula *v, int j, int num, int *k) {
    int p;
    *k = *k + 1;
    p = *k;
    while ((p/2) && num > v[p/2].num) {
        v[p].num = v[p/2].num;
        v[p].i = v[p/2].i;
        p /= 2;
    }
    v[p].num = num;
    v[p].i = j;
}


void ordenarH (FILE *arqs[], celula *c, int tam, int *arqval, 
    int *f, int *totalnum, FILE *saida) {
    int temp, tempi, tempk = tam;
    printf("A\n");
    while (*f <= tam) {
        printf ("%d", *f);
        temp = removerMenor (c, &tempk, &tempi);

        *totalnum = *totalnum + 1;
        printf ("Gravou %d %d\n", temp, tempi);
        fprintf (saida, "%d\n", temp);
        proxNum (arqs, tempi, arqval, f, &temp);
        if (arqval[tempi] == 1)
            inserirElemento (c, tempi, temp, &tempk);
    }
    printf("%d %d", *totalnum, tempk);
}

void peneira (int p, int m, celula *v) { 
    int f = 2*p, x, xi;
    while (f <= m) {
        printf ("oi");
        if (f < m && v[f].num > v[f+1].num)  ++f;
        /* agora f é o filho "mais valioso" de p*/
        if (v[p].num <= v[f].num) break;
        x = v[p].num, v[p].num = v[f].num, v[f].num = x;
        xi = v[p].i, v[p].i = v[f].i, v[f].i = xi;
        p = f, f *= 2;
    }
}

/* k e o tamanho do heap no momento */
int removerMenor (celula *v, int *k, int *menorj) {
    printf("fdfdf");
    int y, x, xi, i;
    y = v[1].num;
    *menorj = v[1].i;
    x = v[*k].num;
    xi = v[*k].i;
    *k = *k - 1;
    i = 1;
    while ((2*i <= *k) && (x > v[2*i].num || x > v[2*i+1].num)){
        if (v[2*i].num < v[2*i + 1].num) {
            v[i].num = v[2*i].num;
            v[i].i = v[2*i].i;
            i = 2*i;
        } else {
            v[i].num = v[2*i + 1].num;
            v[i].i = v[2*i + 1].i;
        }
    }
    v[i].num = x;
    v[i].i = xi;
    printf ("Menor elemento do heap %d %d \n", y, *menorj);
    return y;
}

void proxNum (FILE *arqs[], int j, int *arqval, int *f, int *n) {
    arqval[j] = fscanf (arqs[j], "%d", n);
    printf("Proximo numero puxado %d %d %d \n", j, arqval[j], *n);
    if (feof (arqs[j])) {
        *f = *f + 1;
        printf("Acabou algum arquivo!, %d", *f);       
    }
}

