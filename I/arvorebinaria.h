#ifndef _ARVOREBINARIA_H
#define _ARVOREBINARIA_H

#include <stdio.h>

/*///////// Tipo de dados ///////////////////////////////////////
//
// O indice remissivo e representado por uma arvore binaria
// de busca composta por nohs que sao structs com quatro campos:
// uma string chave, uma lista encadeada lista e dois ponteiros
// para os nohs filhos direita e esquerda. O endereco do noh raiz
// da arvore e definido como arvore.
//
// A lista encadeada sem cabeca e representada por uma struct 
// celula com dois campos: um inteiro conteudo e um ponteiro para
// o proximo elemento da lista prox.
//
///////////////////////////////////////////////////////////////*/

typedef struct lcel {
    int conteudo;
    struct lcel *prox;
} celula;

typedef struct cel {
    char *chave;
    struct lcel *lista;
    struct cel *esq;
    struct cel *dir;
} noh;

typedef noh *arvore;

/* //// Funcao altura /////////////////////////////////////////// 
//
// Devolve a altura da �rvore bin�ria cuja raiz � r.
//
///////////////////////////////////////////////////////////////*/

int altura (arvore r);

/*///// Funcao calcNos ////////////////////////////////////////// 
// 
// Recebe uma arvore r e retorna o numero de nos desta arvore.
//
///////////////////////////////////////////////////////////////*/

int calcNos (arvore r);

/* //// Funcao criarIndice ////////////////////////////////////// 
// 
//  Dado um arquivo entrada, cria uma arvore binaria de busca
//  que e um indice remissivo para este arquivo de entrada e
//  retorna a arvore.
//
///////////////////////////////////////////////////////////////*/

arvore criarIndice (FILE * entrada);

/* //// Funcao imprimeInd ///////////////////////////////////////
// 
// Recebe uma arvore r e um arquivo saida, imprime no arquivo
// o indice remissivo armazenado na arvore r.
//
///////////////////////////////////////////////////////////////*/

void imprimeInd (arvore r, FILE * saida);

/*///// desalocarArvore /////////////////////////////////////////
//
//   Libera o espaco ocupado pela arvore r.              
//
///////////////////////////////////////////////////////////////*/

void desalocarArvore (arvore r);

#endif
