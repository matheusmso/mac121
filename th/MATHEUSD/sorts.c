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


#include "sorts.h"
#include <string.h>
#include <stdlib.h>


static void
peneira (int p, int m, char **v)
{ 
    int f = 2 * p; 
    char *x;
    x = v[p];
    while (f <= m) {
        if (f < m && strcmp (v[f], v[f+1]) < 0) 
            ++f;
        if (strcmp (x, v[f]) >= 0) 
            break;
        v[p] = v[f];
        p = f, f = 2 * p;
    }
    v[p] = x;
    x = NULL;
}


void
heapSort (int n, char **v)
{
    int p, m;
    char *x;
    for (p = n/2; p >= 1; --p)
        peneira (p, n, v);
    for (m = n; m >= 2; --m) {
        x = v[1];
        v[1] = v[m]; 
        v[m] = x;
        peneira (1, m-1, v);
    }
    x = NULL;
}


void 
ordenacaoDigital (char **v, int n, int W) 
{
    int d, i, r, p;
    int R = 128;
    int *fp;
    char **aux;
    fp = malloc ((R+1) * sizeof (int));
    aux = malloc (n * sizeof (char *));
    for (d = W-1; d >= 0; d--) {
        for (r = 0; r <= R; r++) 
            fp[r] = 0;
        for (i = 0; i < n; i++) { 
            p = v[i][d] + 1;
            fp[p] += 1;
        }
        for (r = 1; r <= R; r++) 
            fp[r] += fp[r-1]; 
        for (i = 0; i < n; i++) {
            p = v[i][d];
            aux[fp[p]] = v[i]; 
            fp[p]++; 
        }
        for (i = 0; i < n; i++)
            v[i] = aux[i];
    }
    free (fp);
    free (aux);
    fp = NULL;
    aux = NULL;
}
