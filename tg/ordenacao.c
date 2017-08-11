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


#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


/* Versao alternativa do malloc, printa um erro caso nao consiga
alocar memoria.
*/
static void *
mallocc (size_t nbytes)
{
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == NULL) {
      printf ("Socorro! malloc devolveu NULL!\n");
      exit (EXIT_FAILURE);
   }
   return ptr;
}


/* Esta função rearranja o vetor v[0..n-1] em ordem crescente.
*/
static void
insercao (int n, int v[])
{
   int i, j, x;
   for (j = 1; j < n; ++j) {
      x = v[j];
      for (i = j - 1; i >= 0 && v[i] > x; --i) 
         v[i + 1] = v[i];
      v[i + 1] = x;
   }
}


/* A função recebe vetores crescentes v[p..q-1] e v[q..r-1] 
e rearranja v[p..r-1] em ordem crescente.
*/
static void 
intercala (int p, int q, int r, int v[]) 
{
   int i, j, k, *w;
   w = mallocc ((r - p) * sizeof (int));
   i = p; j = q;
   k = 0;
   while (i < q && j < r) {
      if (v[i] <= v[j])  w[k++] = v[i++];
      else  w[k++] = v[j++];
   }
   while (i < q)  w[k++] = v[i++];
   while (j < r)  w[k++] = v[j++];
   for (i = p; i < r; ++i)  v[i] = w[i - p];
   free (w);
}


/* A função mergesort rearranja o vetor v[p..r-1] 
em ordem crescente.
*/
static void
mergeSort (int p, int r, int v[])
{
   if (p < r - 1) {
      int q = (p + r) / 2;
      mergeSort (p, q, v);
      mergeSort (q, r, v);
      intercala (p, q, r, v);
   }
}


/* Recebe vetor v[p..r] com p < r. Rearranja os elementos 
do vetor e devolve j em p..r tal que 
v[p..j-1] <= v[j] < v[j+1..r].
*/
static int
separa (int v[], int p, int r)
{
   int c = v[p], i = p + 1, j = r, t;
   while (i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j; 
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   v[p] = v[j], v[j] = c;
   return j; 
}


/* A função rearranja o vetor v[p..r], com p <= r+1, de modo 
que ele fique em ordem crescente.
*/
static void 
quickSort (int v[], int p, int r)
{
   int j;
   while (p < r) {
      j = separa (v, p, r);
      if (j - p < r - j) {
         quickSort (v, p, j - 1);
         p = j + 1; 
      } else {
         quickSort (v, j + 1, r);
         r = j - 1;
      }
   }
}


/* Recebe p em 1..m e rearranja o vetor v[1..m] de modo que o 
"subvetor" cuja raiz é p seja um heap. Supõe que os "subvetores" 
cujas raízes são filhos de p já são heaps. 
*/
static void
peneira (int p, int m, int v[])
{ 
   int f = 2 * p, x = v[p];
   while (f <= m) {
      if (f < m && v[f] < v[f + 1])  ++f;
      if (x >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2 * p;
   }
   v[p] = x;
}


/* Rearranja os elementos do vetor v[1..n] de modo que 
fiquem em ordem crescente.
*/
static void
heapSort (int n, int v[])
{
   int p, m, x;
   for (p = n / 2; p >= 1; --p)
      peneira (p, n, v);
   for (m = n; m >= 2; --m) {
      x = v[1], v[1] = v[m], v[m] = x;
      peneira (1, m - 1, v);
   }
}


/* Rearranja os elementos do vetor v[0..n-1] de modo que 
fiquem em ordem crescente.
*/
void 
heap_sort (int *v, int n)
{
    heapSort (n, v - 1);
}


/* Rearranja os elementos do vetor v[0..n-1] de modo que 
fiquem em ordem crescente.
*/
void
quick_sort (int *v, int n)
{
    quickSort (v, 0, n-1);
}


/* Rearranja os elementos do vetor v[0..n-1] de modo que 
fiquem em ordem crescente.
*/
void
merge_sort (int *v, int n)
{
    mergeSort (0, n, v);
}


/* Rearranja os elementos do vetor v[0..n-1] de modo que 
fiquem em ordem crescente.
*/
void 
insertion_sort (int *v, int n)
{
    insercao (n, v);
}
