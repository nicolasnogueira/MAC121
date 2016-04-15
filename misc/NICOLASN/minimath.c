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
// Data: 2015-11-23 
// 
// Este arquivo faz parte da tarefa I 
// da disciplina MAC0121. 
//
// Este modulo implementa a interface minimath.h
//
// A funcao utilizada aqui foi baseada na solucao da tarefa C
//
///////////////////////////////////////////////////////////////*/

int pisolog (int N) {
    int lg = 0;
    while (N > 1) {
        N = N / 2;
        lg++;
    }
    return lg;
}
