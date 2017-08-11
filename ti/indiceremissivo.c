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


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "adt.h"
#include "textprocessing.h"

/* Funcao imprime o resumo estatisco na tela: o tempo t 
em segundos, numero n de nos da arvore e sua altura h
*/
void printResults (double t, int n, int h);


/* Funcao calcula o piso do log de n na base 2
*/
int floorOfLogBaseTwo (int n);


/* Funcao cria o indice remissivo a partir de um arquivo
de entrada in e devolve o endereco da raiz da arvore 
binaria de busca que o contem
*/
tree createIndex (FILE *in);


/* Este programa cria um indice remissivo a partir do 
arquivo de entrada, de nome argv[1] e o imprime no arquivo
de saida de nome argv[2]. Arquivos que nao terminem em \n 
tem sua ultima linha descartada. Se a mesma palavra aparece
mais de uma vez na mesma linha, a linha e adicionada apenas
uma vez
*/
int
main (int argc, char *argv[])
{
    double start, finish;
    tree index;
    FILE *in, *out;
    if (argc != 3) {
        printf ("Erro no input!\n");
        return EXIT_FAILURE;
    }
    in = fopen (argv[1], "r");
    out = fopen (argv[2], "w");
    start = (double) clock();
    index = createIndex (in);
    finish = (double) clock();
    finish = (finish - start) / CLOCKS_PER_SEC;
    printTree (index, out);
    printResults (finish, numOfTreeNodes(index), treeHeight(index));
    unMakeTree (index);
    index = NULL;
    fclose (in);
    fclose (out);
    in = NULL;
    out = NULL;
    return EXIT_SUCCESS;
}


void
printResults (double t, int n, int h)
{
    printf ("----\n");
    printf ("Demorou %.1f ms para criar o indice remissivo.\n", 
        1000 * t);
    printf ("Numero de nos: %d\n", n);
    printf ("Piso do log2 do numero de nos: %d\n", floorOfLogBaseTwo (n));
    printf ("Altura da arvore: %d\n", h);
    printf ("----\n");
}


int
floorOfLogBaseTwo (int n)
{
    int i = 0;
    while ((n = n>>1) > 0)
        i++;
    return i;
}


tree
createIndex (FILE *in)
{
    int i;
    char *tempw, *l;
    node *temp, *new;
    tree index = NULL;
    for (i = 1; (l = nextLine (in)) != NULL; i++) {
        tempw = strtok (l, " ");
        while (tempw) {
            if (isalpha (tempw[0]) && strlen (tempw) > 2) {
                if ((temp = search (index, tempw)) == NULL) {
                    char *word = malloc (strlen (tempw) + 1);
                    strcpy (word, tempw);
                    new = MakeNode (word, i);
                    index = insert (index, new);
                }
                else if (i != temp->head->line) {
                temp->head = insertAtHeadLinkedList (temp->head, i);
                }
            }
            tempw = strtok (NULL, " ");
        }
        free (l);
        l = NULL;
        tempw = NULL;
    }
    return index;
}
