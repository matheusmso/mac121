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


/*///////////////////////////////////////////////////////////////
// Constantes, tipos de dados, e prototipos de funcoes ////////*/

#include <stdlib.h> /* malloc, free, EXIT_SUCCESS */
#include <stdio.h>  /* getc, EOF, fprintf */
#include <string.h> /* strcpy, strcmp, strlen */
#include <ctype.h>  /* isalnum, tolower */
#include "dicionario.h"
#include "bb.h"


char *proximaPalavra (FILE *entrada) ;
void inserePalavra (char *pal, Dicionario d) ;
void expandeDicionario (Dicionario d) ;


/*///////////////////////////////////////////////////////////////
// Funcoes ////////////////////////////////////////////////////*/

Dicionario
criaDicionarioVazio (void)
{
    Dicionario d;
    d = malloc (sizeof *d);
    d->N = 16;
    d->dic = malloc (d->N * sizeof (char *));
    d->n = 0;
    return d;
}


void
constroiDicionario (Dicionario d, FILE *entrada)
{
    char *pal;
    while ((pal = proximaPalavra (entrada)) != NULL) {
        int i;
        for (i = 0; pal[i] != '\0'; i++)
            pal[i] = tolower (pal[i]);
        inserePalavra (pal, d);
    }
}


char *
proximaPalavra (FILE *entrada)
{
    int i, c;
    char *pal;
    int B;
    char *buffer;
    do {
        c = getc (entrada);
        if (c == EOF) return NULL;
    } while (!isalnum (c));
    B = 4;
    buffer = malloc (B);
    i = 0;
    do {
        buffer[i++] = c;
        if (i >= B) {
            int i;
            char *novobuffer = malloc (2 * B);
            for (i = 0; i < B; i++)
                novobuffer[i] = buffer[i];
            free (buffer);
            B *= 2;
            buffer = novobuffer;
        }
        c = getc (entrada);
    } while (c != EOF && isalnum (c));
    buffer[i] = '\0';
    pal = malloc (strlen (buffer) + 1);
    strcpy (pal, buffer);
    free (buffer);
    return pal;
}


void
inserePalavra (char *pal, Dicionario d)
{
    int i, j;
    if (pal[0] >= 48 && pal[0] <= 57) {
        free (pal);
        return;
    }
    i = buscaBinaria (pal, d);
    if (i >= 0) {
        if (d->n == d->N)
            expandeDicionario (d);
        for (j = d->n-1; j >= i; j--)
            d->dic[j+1] = d->dic[j];
        d->dic[i] = pal;
        d->n += 1;
    } else free (pal);
}


void
expandeDicionario (Dicionario d)
{
    char **novodic;
    int i;
    novodic = malloc (2 * d->N * sizeof (char *));
    for (i = 0; i < d->N; i++)
        novodic[i] = d->dic[i];
    free (d->dic);
    d->dic = novodic;
    d->N *= 2;
}


void
imprimeDicionario (Dicionario d, FILE *saida)
{
    int i;
    fprintf (saida, "Lista de palavras distintas "
             "(%d palavras):\n\n", d->n);
    for (i = 0; i < d->n; i++)
        fprintf (saida, "%s\n", d->dic[i]);
    fprintf (saida, "\n");
    fprintf (saida, "espaco reservado para o dicionario: "
             "%d palavras\n", d->N);
    fprintf (saida, "tempo gasto para criar e popular o "
             "dicionario em segundos: ");
}


void
desalocaDicionario (Dicionario d)
{
    int i;
    for (i = 0; i < d->n; i++) free (d->dic[i]);
    free (d->dic);
    free (d);
}
