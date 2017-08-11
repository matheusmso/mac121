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
// Data: 2015-09-19
//
// Este arquivo faz parte da tarefa E
// da disciplina MAC0121.
//
////////////////////////////////////////////////////////////// */


#include <string.h> /* strcmp */
#include "dicionario.h"
#include "bb.h"


/*///////////////////////////////////////////////////////////////
// Funcoes ////////////////////////////////////////////////////*/

int
buscaBinaria (char *pal, Dicionario d)
{
    int lower, upper, mid;
    upper = d->n - 1;
    lower = 0;
    while (lower <= upper) {
        mid = lower + (upper - lower) / 2;
        if (strcmp (pal, d->dic[mid]) <= 0) {
            if (strcmp (pal, d->dic[mid]) == 0)
                return -1;
            else
                upper = mid - 1;
        }
        else
            lower = mid + 1;
    }
    return lower;
}


int
buscaBinariaP (char *pal, Dicionario d)
{
    int lower, upper, mid;
    upper = d->n - 1;
    lower = 0;
    while (lower <= upper) {
        mid = lower + ((upper - lower) / 2);
        if (strcmp (pal, d->dic[mid]) <= 0) {
            if (strcmp (pal, d->dic[mid]) == 0)
                return mid;
            else
                upper = mid - 1;
        }
        else
            lower = mid + 1;
    }
    return lower;
}
