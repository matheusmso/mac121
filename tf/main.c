/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Matheus de Mello Santos Oliveira
// Numero USP: 8642821
// Sigla: MATHEUSD
// Data: 2015-10-06
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */


/* Este programa recebe arquivos de entrada contendo numeros em
 ordem crescente e faz uma intercalacao de todos eles em um so
 arquivo de saida tambem em ordem crescente.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "simplorio.h"
#include "heap.h"


int inOrder (FILE *saida);


int
main (int argc, const char *argv[])
{
    int i, j;
    double start, finish;
    FILE **entrada;
    FILE *saida;
    entrada = malloc ((argc - 2) * sizeof (FILE *));
    for (i = 1; i < argc - 2; i++)
        entrada[i] = fopen (argv[i + 1], "r");
    saida = fopen (argv[argc - 1], "w");
    start = (double) clock();
    if (strcmp (argv[1], "-s") == 0) {
        j = simplorio (entrada, saida, argc - 2);
        printf ("Total de numeros no arquivo de saida: %d\n", j);
    }
    else if (strcmp (argv[1], "-h") == 0) {
        j = heap (entrada, saida, argc - 3);
        printf ("Total de numeros no arquivo de saida: %d\n", j);
    }
    else {
        printf ("Entre com a flag -h ou -s como primeiro argumento\n");
        return EXIT_FAILURE;
    }
    finish = (double) clock();
    printf ("Tempo de processamento: %f segundos\n",
            (finish - start) / CLOCKS_PER_SEC);
    printf ("Numero de arquivos: %d\n", argc - 3);
    for (i = 1; i < argc - 2; i++) {
        fclose (entrada[i]);
        entrada[i] = NULL;
    }
    fclose (saida);
    free (entrada);
    entrada = NULL;
    saida = fopen (argv[argc - 1], "r");
    j = inOrder (saida);
    if (j == 0)
        printf ("Arquivo de saida com problemas\n");
    fclose (saida);
    saida = NULL;
    return EXIT_SUCCESS;
}


/* Funcao verifica se o arquivo saida esta em ordem crescente 
 retorna 1 se sim e 0 caso contrario.
 */
int
inOrder (FILE *saida)
{
    int a, b;
    if (fscanf (saida, "%d", &a) == EOF)
        return 1;
    while (fscanf (saida, "%d", &b) != EOF) {
        if (a > b) return 0;
        a = b;
    }
    return 1;
}
