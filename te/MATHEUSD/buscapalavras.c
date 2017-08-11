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
#include <time.h> /* clock, CLOCKS_PER_SEC */
#include "bb.h"
#include "dicionario.h"


void interacao (char *pal, Dicionario d) ;
char *proximaPalavraInput (void) ;


/*///////////////////////////////////////////////////////////////
// Funcoes ////////////////////////////////////////////////////*/

int
main (int argc, char *argv[])
{
    char *pal;
    double start, finish, elapsed;
    Dicionario d;
    FILE *entrada;
    FILE *saida;
    if (argc != 3) {
        printf ("Erro no input!");
        return EXIT_FAILURE;
    }
    entrada = fopen (argv[1], "r");
    saida = fopen (argv[2], "w");
    start = (double) clock() / CLOCKS_PER_SEC;
    d = criaDicionarioVazio ();
    constroiDicionario (d, entrada);
    finish = (double) clock() / CLOCKS_PER_SEC;
    elapsed = finish - start;
    imprimeDicionario (d, saida);
    fprintf (saida, "%f\n", elapsed);
    fclose (entrada);
    fclose (saida);
    while (1) {
        putc ('>', stdout);
        pal = proximaPalavraInput();
        if (pal == NULL) {
            printf ("Adeus\n");
            break;
        }
        interacao (pal, d);
    }
    desalocaDicionario (d);
    return EXIT_SUCCESS;
}


/* Imprime na tela as posicoes da string pal e de suas vizinha(s).
// Se pal estiver no dicionario imprime as posicoes
// e as palavras sua e de sua vizinha a direita. Caso contrario 
// imprime as posicoes e as palavras que seriam suas vizinhas, se
// pal pertencesse a d.
*/
void
interacao (char *pal, Dicionario d)
{
    int i;
    if (pal[0] >= 48 && pal[0] <= 57) {
        printf ("Palavra nao comeca com letra.\n"
                "Por favor tente novamente.\n");
        return;
    }
    i = buscaBinariaP (pal, d);
    if (i <= d->n - 1) {
        if (strcmp (pal, d->dic[i]) == 0) {
            printf ("(%d, %s) ", i, d->dic[i]);
            if (i == d->n - 1)
                printf ("essa palavra e a ultima do dicionario\n");
            else
                printf ("(%d, %s)\n", i+1, d->dic[i+1]);
        }
        else {
            if (i == 0)
                printf ("essa palavra vem antes da primeira do "
                        "dicionario ");
            else
                printf ("(%d, %s) ", i-1, d->dic[i-1]);
            printf ("(%d, %s)\n", i, d->dic[i]);
        }
    }
    if (i == d->n) {
        printf ("essa palavra vem depois da ultima "
                "(%d, %s) \n", i-1, d->dic[i-1]);
    }
}


/* Devolve a proxima palavra de stdin. Se stdin for a palavra vazia,
// devolve NULL.
*/
char *
proximaPalavraInput (void)
{
    int i, c;
    char *pal;
    int B;
    char *buffer;
    do {
        c = getc (stdin);
        if (c == '\n') return NULL;
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
        c = getc (stdin);
    } while (c != EOF && isalnum (c));
    buffer[i] = '\0';
    pal = malloc (strlen (buffer) + 1);
    strcpy (pal, buffer);
    free (buffer);
    for (i = 0; pal[i] != '\0'; i++)
        pal[i] = tolower (pal[i]);
    return pal;
}
