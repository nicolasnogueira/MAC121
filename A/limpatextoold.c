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
// Data: 2015-08-10
// 
// Este arquivo faz parte da tarefa B
// da disciplina MAC0121.
// 
///////////////////////////////////////////////////////////////*/

/*///// Filtro limpa-texto simples  /////////////////////////////
//
//   O programa le um arquivo de texto, realiza um processo de
//   limpeza neste arquivo e grava o resultado em outro. O 
//   processo de limpeza consiste em apagar sinais diacriticos, 
//   eliminar espacos repetidos e trata de alguns caracteres de
//   controle.
//
///////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
   int c, espacos = 0, clinha = 1, crrsp;
   while ((c = getc (stdin)) != EOF) {
      if (c == 32)
         espacos++;
      else {
         if (espacos != 0) {
            if (clinha == 1) {
               while (espacos != 0) {
                  putc (' ', stdout);
                  espacos--;
               }
            } else {
               putc (' ', stdout);
               espacos = 0;
            }
            clinha = 0;
         }
         if (c <= 31) {
            if (c == 10){
               putc ('\n', stdout);
               clinha = 1;
            } else if (c == 9) {
               espacos = 7;
               while (espacos != 0) {
                  putc (' ', stdout);
                  espacos--;
               }
            }
         } else if (c >= 127 && c <= 255) {
            crrsp = 0;
            if (c >= 192 && c <= 197) { /* caractere A */
               crrsp = 1;
               putc ('A', stdout);
            }
            if (c == 199) {             /* caractere C */
               crrsp = 1;
               putc ('C', stdout);
            }
            if (c >= 200 && c <= 203) { /* caractere E */
               crrsp = 1;
               putc ('E', stdout);
            }
            if (c >= 204 && c <= 207) { /* caractere I */
               crrsp = 1;
               putc ('I', stdout);
            }
            if (c == 209) {             /* caractere N */
               crrsp = 1;
               putc ('N', stdout);
            }
            if (c >= 210 && c <= 214) { /* caractere O */
               crrsp = 1;
               putc ('O', stdout);
            }
            if (c >= 217 && c <= 220) { /* caractere U */
               crrsp = 1;
               putc ('U', stdout);
            }
            if (c == 221) {             /* caractere Y */
               crrsp = 1;
               putc ('Y', stdout);
            }
            if (c >= 224 && c <= 229) { /* caractere a */
               crrsp = 1;
               putc ('a', stdout);
            }
            if (c == 231) {             /* caractere c */
               crrsp = 1;
               putc ('c', stdout);
            }
            if (c >= 232 && c <= 235) { /* caractere e */
               crrsp = 1;
               putc ('e', stdout);
            }
            if (c >= 236 && c <= 239) { /* caractere i */
               crrsp = 1;
               putc ('i', stdout);
            }
            if (c == 241) {             /* caractere n */
               crrsp = 1;
               putc ('n', stdout);
            }
            if (c >= 242 && c <= 246) { /* caractere o */
               crrsp = 1;
               putc ('o', stdout);
            }
            if (c >= 249 && c <= 252) { /* caractere u */
               crrsp = 1;
               putc ('u', stdout);
            }
            if (c == 253 || c == 255) { /* caractere y */
               crrsp = 1;
               putc ('y', stdout);
            }
            if (crrsp == 0)
               putc (' ', stdout);
         } else
            putc (c, stdout);
      }
   }
   return EXIT_SUCCESS;
}