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

#ifndef dicionario_h
#define dicionario_h
#include <stdio.h>


/* O dicionario e representado por uma struct com tres campos:
// o numero n de palavras, um vetor de strings dic[0..n-1],
// e a capacidade total N do vetor dic.
*/

typedef
struct {
    char **dic;
    int    n, N;
} *Dicionario;


/* Cria um dicionario vazio.
*/
Dicionario criaDicionarioVazio (void) ;


/* Popula o dicionario d com as palavras do texto que esta
// no arquivo de entrada.
*/
void constroiDicionario (Dicionario d, FILE *entrada) ;


/* Imprime o dicionario d no arquivo de saida.
*/
void imprimeDicionario (Dicionario d, FILE *saida) ;


/* Libera o espaco ocupado pelo dicionario d.
*/
void desalocaDicionario (Dicionario d) ;

#endif /* dicionario_h */
