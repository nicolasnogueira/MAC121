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
   int c, espacos = 0, clinha = 1;
   char ilegais[64] = {'A', 'A', 'A', 'A', 'A', 'A', ' ', 'C',
                       'E', 'E', 'E', 'E', 'I', 'I', 'I', 'I',
                       ' ', 'N', 'O', 'O', 'O', 'O', 'O', ' ',
                       ' ', 'U', 'U', 'U', 'U', 'Y', ' ', ' ',
                       'a', 'a', 'a', 'a', 'a', 'a', ' ', 'c',
                       'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i',
                       ' ', 'n', 'o', 'o', 'o', 'o', 'o', ' ',
                       ' ', 'u', 'u', 'u', 'u', 'y', ' ', 'y'};
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
            if (c == 10) {
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
            if (c >= 192){
               putc (ilegais[c-192], stdout);
            } else
               putc (' ', stdout);
         } else
            putc(c, stdout);
      }
   }
   return EXIT_SUCCESS;
}

