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


#include <stdlib.h>
#include "heap.h"


static void
minHeap (int p, int m, cel *a)
{
    int f = 2 * p;
    cel x = a[p];
    while (f <= m) {
        if (f < m && a[f].num > a[f + 1].num) ++f;
        if (x.num <= a[f].num) break;
        a[p] = a[f];
        p = f;
        f = 2 * p;
    }
    a[p] = x;
}


int
heap (FILE **entrada, FILE *saida, int m)
{
    int i, total = 0;
    cel *a;
    a = malloc ((m + 1) * sizeof (cel));
    for (i = 1; i < m + 1; i++) {
        if (fscanf (entrada[i], "%d", &a[i].num) == EOF)
            a[i].ind = 0;
        else
            a[i].ind = i;
    }
    for (i = m / 2; i >= 1; i--)
        minHeap (i, m, a);
    while (m > 0) {
        fprintf (saida, "%d\n", a[1].num);
        total++;
        if (fscanf (entrada[a[1].ind], "%d", &a[1].num) == EOF) {
            a[1] = a[m];
            minHeap (1, m - 1, a);
            m--;
        }
        else
            minHeap (1, m, a);
    }
    free (a);
    a = NULL;
    return total;
}
