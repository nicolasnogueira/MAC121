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
///////////////////////////////////////////////////////////////*/

/* //// Indice Remissivo //////////////////////////////////////// 
// 
// O programa processa um arquivo de texto e constroi um indice 
// remissivo do texto. O índice remissivo e uma tabela de duas 
// colunas, na primeira coluna aparece o dicionario do texto, 
// em ordem lexicografica, na segunda coluna, para cada palavra 
// do dicionario, aparecem os numeros das linhas do arquivo que 
// contem a palavra.
//
// Exemplo de arquivo de texto:
//
// 1. Quanto tempo gastam os algoritmos 
// 2. de busca e insercao 
// 3. numa arvore de busca?
// 4. Para ambos os algoritmos,
// 5. o tempo e limitado 
// 6. pela altura da arvore.
// 7. tem o seguinte índice remissivo:
//
// algoritmos   1, 4
// altura       6
// ambos        4
// arvore       3, 6
// busca        2, 3
// da           6
// de           2, 3
// e            2, 5
// gastam       1
// insercao     2
// limitado     5
// numa         3
// o            5
// os           1, 4
// para         4
// pela         6
// quanto       1
// tempo        1, 5
//
///////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvorebinaria.h"
#include "minimath.h"

int main (int argc, char **argv) {
    FILE *entrada, *saida;
    arvore r;
    double inicio, fim;
    int numnos;
    r = NULL;
    if (argc != 3) {
        fprintf (stderr, "USAGE: %s <input> <output>\n",
                 argv[0]);
        return EXIT_FAILURE;
    }
    entrada = fopen (argv[1], "r");
    saida = fopen (argv[2], "w");
    inicio = (double) clock () / CLOCKS_PER_SEC;
    r = criarIndice (entrada);
    fim = (double) clock () / CLOCKS_PER_SEC;
    fclose (entrada);
    numnos = calcNos (r);
    imprimeInd (r, saida);
    fclose (saida);
    printf ("Tempo de construcao do indice: %0.4f\n",
            fim - inicio);
    printf ("Numero de nos (n): %d\n", numnos);
    printf ("Altura: %d\n", altura (r));
    printf ("Piso de log n: %d\n", pisolog (numnos));
    desalocarArvore (r);

    return EXIT_SUCCESS;
}
