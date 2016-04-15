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
#define TRUE 1

void 

int verificaB (FILE *arquivob, int n) {
    int num1, num2, k, cont = 0;
    k = fscanf (arquivob, "%d", &num1);
    if (k != 1)
        if (n == 1)
            return 1;
        else
            return 0;
    cont++;
    while (TRUE) {
        k = fscanf (arquivob, "%d", &num2);
        if (k == 1){
            if (num1 > num2)
                return 0;
            else {
                cont++;
                num1 = num2;
            }
        } else if (cont == n)
            return 1;
        else
            return 0;
    }
}