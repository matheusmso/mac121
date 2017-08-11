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
// Data: 2015-11-17
// 
// Este arquivo faz parte da tarefa I
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */


#include "textprocessing.h"
#include <stdlib.h>
#include <ctype.h>


char *
nextLine (FILE *in)
{
    char *line;
    int k, c, size;
    k = 0;
    size = 50;
    line = malloc (size + 1);
    while ((c = getc (in)) != '\n' && c != EOF) {
        if (k == size) {
            line = realloc (line, 2 * size + 1);
            size *= 2;
        }
        if (isalnum (c))
            line[k++] = tolower (c);
        else
            line[k++] = ' ';
    }
    line[k] = '\0';
    if (c == EOF) {
        free (line);
        line = NULL;
        return NULL;
    }
    return line;
}
