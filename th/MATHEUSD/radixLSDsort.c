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
// Data: 2015-11-01
// 
// Este arquivo faz parte da tarefa H
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorts.h"
#include "randomm.h"


/* Verifica se o vetor de strings v[0..n-1] esta em
ordem lexicografica. Retorna 1 em caso positivo e
0 caso contrario.
*/
int emOrdem (char **v, int n);


/* O programa compara o tempo que leva para ordenar strings 
pelo algoritmo heapsort e radixLSDsort. 
*/
int
main (void)
{
    double start, finish;
    int i, t, size;
    char **c;
    char **a;
    for (size = 40000; size <=320000; size *= 2) {
        printf ("Teste com vetor de %6d elementos " 
            "aleatorios:\n", size);
        c = malloc (size * sizeof (char *));
        a = malloc (size * sizeof (char *));
        for (i = 0; i < size; ++i) {
            c[i] = malloc (10 * sizeof (char));
            a[i] = malloc (10 * sizeof (char));
            t = RandomInteger (100000000, 999999999);
            sprintf (c[i], "%d", t);
            sprintf (a[i], "%d", t);
        }
        start = (double) clock ();
        ordenacaoDigital (c, size, 9);
        finish = (double) clock ();
        printf ("  ordenacao digital %7.2f ms   ", 
            1000 * (finish - start) / CLOCKS_PER_SEC);
        if (emOrdem (c, size) == 1)
            printf ("Ok!\n");
        else 
            printf ("Erro!\n");
        start = (double) clock ();
        heapSort (size, a - 1);
        finish = (double) clock ();
        printf ("  heapsort          %7.2f ms   ", 
            1000 * (finish - start) / CLOCKS_PER_SEC);
        if (emOrdem (a, size) == 1)
            printf ("Ok!\n");
        else 
            printf ("Erro!\n");
        for (i = 0; i < size; ++i) {
            free (c[i]);
            free (a[i]);
            c[i] = NULL;
            a[i] = NULL;
        }
        free (c);
        free (a);
        c = NULL;
        a = NULL;
    }
    return EXIT_SUCCESS;
}


int
emOrdem (char **v, int n)
{
    int i;
    for (i = 1; i < n; ++i)
        if (strcmp (v[i - 1], v[i]) > 0)
            return 0;
    return 1;
}
