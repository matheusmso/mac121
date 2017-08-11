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


#include "adt.h"
#include <string.h>
#include <stdlib.h>


static int breakline = 0;


/* Cria uma celula de uma lista encadeada
*/
static cel *
MakeCel (int i)
{
    cel *head;
    head = malloc (sizeof (cel));
    head->next = NULL;
    head->line = i;
    return head;
}


/* Imprime de forma reversa um lista encadeada sem cabeca
apontada por head no arquivo de saida out
*/
static void
rPrintLinkedList (cel *head, FILE *out) 
{
    if (head != NULL) {
        rPrintLinkedList (head->next, out);
        if (breakline == 5) {
            fprintf (out, "\n%*c", 32, ' ');
            breakline = 0;
        }
        if (head->next == NULL || breakline == 0) {
            fprintf (out, "%d", head->line);
            breakline++;
        }
        else {
            fprintf (out, ", %d", head->line);
            breakline++;
        }
    }
}


/* Desconstroi lista encadeada sem cabeca apontada por
head
*/
static void 
unMakeLinkedList (cel *head)
{
    cel *temp;
    while ((temp = head) != NULL) {
        head = head->next;
        free (temp);
        temp = NULL;
    }
}


cel *
insertAtHeadLinkedList (cel *head, int n)
{
    cel *new;
    new = malloc (sizeof (cel));
    new->next = head;
    new->line = n;
    return new;
}


node *
MakeNode (char *w, int i)
{
    node *new;
    new = malloc (sizeof (node));
    new->le = new->ri = NULL;
    new->w = w;
    new->head = MakeCel (i);
    return new;
}


node *
search (tree r, char *w)
{
    if (r == NULL || strcmp (r->w, w) == 0)
        return r;
    if (strcmp (r->w, w) > 0)
        return search (r->le, w);
    return search (r->ri, w);
}


tree
insert (tree r, node *new)
{
    node *s, *f;
    if (r == NULL) return new;
    s = r;
    while (s != NULL) {
        f = s;
        if (strcmp (s->w, new->w) > 0)
            s = s->le;
        else
            s = s->ri;
    }
    if (strcmp (f->w, new->w) > 0)
        f->le = new;
    else
        f->ri = new;
    return r;
}


void
printTree (tree r, FILE *out)
{
    if (r != NULL) {
        printTree (r->le, out);
        fprintf (out, "%-*s  ", 30, r->w);
        rPrintLinkedList (r->head, out);
        fprintf (out, "\n");
        breakline = 0;
        printTree (r->ri, out);
    }
}


void
unMakeTree (tree r) 
{
    if (r != NULL) {
        unMakeTree (r->le);
        unMakeTree (r->ri);
        free (r->w);
        r->w = NULL;
        unMakeLinkedList (r->head);
        r->head = NULL;
        free (r);
    }
}


int
treeHeight (tree r)
{
    int hl, hr;
    if (r == NULL)
        return -1;
    hl = treeHeight (r->le);
    hr = treeHeight (r->ri);
    if (hl < hr) return hr + 1;
    return hl + 1;
}


int
numOfTreeNodes (tree r) 
{
    if (r == NULL) return 0;
    return 1 + numOfTreeNodes(r->le) + numOfTreeNodes(r->ri);
}
