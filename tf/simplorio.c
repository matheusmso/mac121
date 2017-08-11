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
#include "simplorio.h"


static int
minIndex (int *v, int *flag, int m)
{
    int i, imin = 1;
    for (i = 1; i < m; i++) {
        if (flag[i] == 1) {
            imin = i;
            break;
        }
    }
    if (i == m)
        return 0;
    for (i = imin + 1; i < m; i++)
        if (v[i] <= v[imin] && flag[i] == 1)
            imin = i;
    return imin;
}


int
simplorio (FILE **entrada, FILE *saida, int m)
{
    int i, min, total = 0;
    int *flag;
    int *v;
    flag = malloc (m * sizeof (int));
    v = malloc (m * sizeof (int));
    for (i = 1; i < m; i++) {
        if (fscanf (entrada[i], "%d", &v[i]) == EOF)
            flag[i] = 0;
        else
            flag[i] = 1;
    }
    while (1) {
        min = minIndex (v, flag, m);
        if (min == 0)
            break;
        fprintf (saida, "%d\n", v[min]);
        total++;
        if (fscanf (entrada[min], "%d", &v[min]) == EOF)
            flag[min] = 0;
    }
    free (flag);
    free (v);
    flag = NULL;
    v = NULL;
    return total;
}
