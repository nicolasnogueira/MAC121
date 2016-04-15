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
// Data: 2015-08-31
// 
// Este arquivo faz parte da tarefa D
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/*///// Lista de palavras distintas  ////////////////////////////
//
//   O programa imprime uma lista de palavras sem repeticoes de 
//   um arquivo de texto. As palavras da lista s�o armazenadas 
//   em ordem lexicografica.
//  
//   Exemplo: Quando processamos as seguintes duas linhas
//
//   A variavel x99, do tipo int, e diferente da x89,
//   que e do tipo char.
//
//   A saida que temos e a seguinte:
//
//   a
//   char
//   da
//   diferente
//   do
//   e
//   int
//   que
//   tipo
//   variavel
//   x89
//   x99
//
///////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    struct cel *prox;
    char       *conteudo; 
};

typedef struct cel celula;
typedef char *string;

/* //// Funcao readLine /////////////////////////////////////////
//
//   Fun��o de leitura de linha de arquivo de texto retirada do 
//   s�tio disponibilizado pelo professor em:
//   http://www.ime.usp.br/~pf/algoritmos/aulas/io2.html#resizing
//
//   Esta funcao le um arquivo de texto infile e devolve uma 
//   string que equivale a uma linha processada deste arquivo.
//
////////////////////////////////////////////////////////////// */

string readLine (FILE *infile) {
    string line, nline;
    int n, ch, size;
    n = 0;
    size = 120;
    line = malloc (size + 1);
    while ((ch = getc (infile)) != '\n' && ch != EOF) {
        if (n == size) {
            size *= 2;
            nline = malloc (size + 1);
            strncpy (nline, line, n);
            free (line);
            line = nline;
        }
        line[n++] = ch;
    }
    if (n == 0 && ch == EOF) {
        free (line);
        return NULL;
    }
    line[n] = '\0';
    nline = malloc (n + 1);
    strcpy (nline, line);
    free (line);
    return nline;
}

/* //// Funcao normalizar ///////////////////////////////////////
//
//   Fun��o que le uma string e retorna a mesma string com todos
//   os caracteres em caixa baixa.
//
////////////////////////////////////////////////////////////// */

string normalizar (string palavra) {
    int n = 0;
    while (palavra[n] != '\0') {
        if (palavra[n] >= 65 && palavra[n] <= 90)
            palavra[n] = palavra[n] + 32;
        n++;
    }
    return palavra;
}

/* //// Funcao insereDicionario /////////////////////////////////
//
//   Fun��o que recebe um ponteiro de um celula que representa a
//   cabeca de uma lista encadeada e uma string palavra a ser
//   inserida nesta lista, respeitando a ordem lexicografica.
//
////////////////////////////////////////////////////////////// */

void insereDicionario (celula *ini, string palavra) {
    string npalavra = normalizar (palavra);
    celula *p, *q;
    int dif;
    p = ini->prox;
    q = ini;
    while (p != NULL) {
        /* q representa a celula anterior e p representa a celula
        // que tem a palavra a ser inserida na lista*/
        dif = (strcmp (p->conteudo, npalavra));
        if (dif > 0) {
            celula *nova;
            nova = malloc (sizeof (celula));
            nova->conteudo = npalavra;
            nova->prox = q->prox;
            q->prox = nova;
            break;
        } else if (dif == 0)
            break;
        p = p->prox;
        q = q->prox;
    }
    if (p == NULL) {
        celula *nova;
        nova = malloc (sizeof (celula));
        nova->conteudo = npalavra;
        nova->prox = q->prox;
        q->prox = nova;
    }
}

/* //// Funcao imprimeDicionario /////////////////////////////////
//
//   Fun��o que recebe um ponteiro de um celula que representa a
//   cabeca de uma lista encadeada e imprime o conteudo em ordem
//   de cada celula desta lista.
//
////////////////////////////////////////////////////////////// */

void imprimeDicionario (celula *ini) {
    celula *p;
    for (p = ini->prox; p != NULL; p = p->prox) 
        printf ("%s\n", p->conteudo);
}

/* //// Funcao processarLinha ///////////////////////////////////
//
//   Fun��o que funciona de maneira analoga a funcao readLine,
//   por�m, recebe um ponteiro de uma celula cabeca de uma lista 
//   encadeada e processa cada palavra da string linha, chamando
//   a funcao insereDicionario para a insercao dessas palavras
//   na lista encadeada.
//
////////////////////////////////////////////////////////////// */

void processarLinha (celula *ini, string linha) {
    string palavra, temp;
    int ler = 0, escrita = 0, tamanho = 20;
    palavra = malloc (tamanho + 1);
    while (linha[ler] != '\0') {
        if (linha[ler] != ' ') {
            if (escrita == tamanho) {
                tamanho *= 2;
                temp = malloc (tamanho + 1);
                strncpy (temp, palavra, tamanho);
                free (palavra);
                palavra = temp;
            }
            if ((linha[ler] >= 48 && linha[ler] <= 57)
                || (linha[ler] >= 65 && linha[ler] <= 90)
                || (linha[ler] >= 97 && linha[ler] <= 122))
                palavra[escrita] = linha[ler];
            escrita++;
            ler++;
        } else {
            palavra[escrita] = '\0';
            temp = malloc (tamanho + 1);
            strcpy (temp, palavra);
            free (palavra);
            insereDicionario (ini, temp);
            escrita = 0;
            tamanho = 20;
            palavra = malloc (tamanho + 1);
            ler++;
        }
    }
    palavra[escrita] = '\0';
    temp = malloc (tamanho + 1);
    strcpy (temp, palavra);
    free (palavra);
    insereDicionario (ini, temp);
}

/* //// Funcao desalocar ////////////////////////////////////////
//
//   Fun��o que desaloca toda a memoria utilizada pela lista
//   que tem a celula cabeca apontada por ini.
//
////////////////////////////////////////////////////////////// */

void desalocar (celula* ini) {
    celula *atual, *temp;
    atual = ini;
    while (atual != NULL) {
        temp = atual->prox;
        free (atual);
        atual = temp;
    }
}

int main (void) {
    string s;
    celula *ini;
    ini = malloc (sizeof (celula));
    ini->prox = NULL;
    while ((s = readLine (stdin)) != NULL)
        processarLinha (ini, s);
    imprimeDicionario (ini);
    desalocar (ini);
    return EXIT_SUCCESS;
}