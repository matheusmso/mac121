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


#ifndef heap_h
#define heap_h


#include <stdio.h>


typedef struct celula {
    int ind;
    int num;
} cel;


/* Funcao recebe m arquivos de entrada contendo numeros em ordem crescente, 
 um arquivo de saida e retorna a quantidade de numeros de todos os arquivos 
 de entrada. Alem disso reorganiza todos os numeros de todos os arquivos de 
 entrada e os imprime em ordem crescente no arquivo de saida.
 */
int heap (FILE **entrada, FILE *saida, int m);


#endif /* heap_h */
