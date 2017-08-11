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

#ifndef bb_h
#define bb_h
#include "dicionario.h"


/* Busca a string pal dentro do dicionario d e retorna a
// posição onde pal deve ser inserida ou -1 caso pal já
// pertença ao dicionario.
*/
int buscaBinaria (char *pal, Dicionario d) ;


/* Busca a string pal dentro do dicionario d e retorna a 
// posicao onde pal esta ou deveria estar
*/
int buscaBinariaP (char *pal, Dicionario d) ;

#endif /* bb_h */
