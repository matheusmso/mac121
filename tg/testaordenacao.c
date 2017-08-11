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
// Data: 2015-10-12
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */


#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


int testaOrdem (int *v, int n);


int 
main (void)
{
    int i, v[40000];
    for (i = 0; i < 40000; i++)
        v[i] = rand();
    insertion_sort (v, 40000);
    if (testaOrdem (v, 40000) == 1)
        printf("Algoritmo de insercao testado com sucesso!\n");
    for (i = 0; i < 40000; i++)
        v[i] = rand();
    merge_sort (v, 40000);
    if (testaOrdem (v, 40000) == 1)
        printf("Algoritmo mergesort testado com sucesso!\n");
    for (i = 0; i < 40000; i++)
        v[i] = rand();
    quick_sort (v, 40000);
    if (testaOrdem (v, 40000) == 1)
        printf("Algoritmo quicksort testado com sucesso!\n");
    for (i = 0; i < 40000; i++)
        v[i] = rand();
    heap_sort (v, 40000);
    if (testaOrdem (v, 40000) == 1)
        printf("Algoritmo heapsort testado com sucesso!\n");
    return EXIT_SUCCESS;
}


/* Testa se o vetor v[0..n-1] esta em ordem crescente. Retorna
1 em caso positivo e 0 caso contrario.
*/
int
testaOrdem (int *v, int n)
{
    int i;
    if (n <= 1) return 1;
    for (i = 1; i < n; i++)
        if (v[i] < v[i - 1]) return 0;
    return 1;
}
