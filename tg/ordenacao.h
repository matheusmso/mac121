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
// Data: 2015-10-12
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */


#ifndef _ordenacao_h
#define _ordenacao_h


/* As quatro funcoes abaixo rearranjam os elementos do vetor 
v[0..n-1] de modo que fiquem em ordem crescente.
*/


/* Consome tempo proporcional a n * (log n).
*/
void heap_sort (int *v, int n);


/* Consome tempo proporcional a n * (log n). No pior caso,
do vetor estar quase ordenado  o numero de comparacoes pode
chegar a ordem de n ^ 2.
*/
void quick_sort (int *v, int n);


/* Consome tempo proporcional a n * (log n).
*/
void merge_sort (int *v, int n);


/* Consome tempo proporcional a n ^ 2. No melhor caso o numero
de comparacoes nao supera n.
*/
void insertion_sort (int *v, int n);


#endif
