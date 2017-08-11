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


#ifndef _adt_h
#define _adt_h


struct celula {
    int line;
    struct celula *next;
};
typedef struct celula cel;


struct nod {
    struct nod *le;
    struct nod *ri;
    cel *head;
    char *w;
};
typedef struct nod node;
typedef node *tree;


/* Cria um node de uma arvore binaria, que tem a string
w como campo principal e insere o inteiro i no campo da lista
encadeada de inteiros 
*/
node *MakeNode (char *w, int i);


/* Verifica se a string w esta em algum node da arvore binaria
de busca, se sim, devolve o endereco deste node, se nao retorna
NULL
*/
node *search (tree r, char *w);


/* Desconstroi a arvore binaria r
*/
void unMakeTree (tree r);

/* Insere o node new, na posicao correta da arvore binaria de
busca cuja raiz e apontada por r
*/
tree insert (tree r, node *new);


/* Imprime o conteudo da arvore binaria de busca r no arquivo
de saida out (sao reservados 30 espacos para a string pois a 
maior palavra nao tecnica do portugues possui 29 letras,
fonte: https://en.wikipedia.org/wiki/Longest_words#Portuguese)
*/
void printTree (tree r, FILE *out);


/* Calcula a altura da arvore r
*/
int treeHeight (tree r);


/* Calcula o numero de nodes da arvore r
*/
int numOfTreeNodes (tree r);


/* Insere o inteiro i no inicio da lista encadeada sem cabeca
apontada por head
*/
cel *insertAtHeadLinkedList (cel *head, int n);

#endif
