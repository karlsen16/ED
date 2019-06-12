#ifndef ___ARVOREB_H_
#define ___ARVOREB_H_

#include <stdio.h>
#include <stdlib.h>

/*Estrutura básica para uma árvore B: */
typedef struct _node {
  int n; /*Número de chaves armazenadas no nó!*/
  int folha; /*Booleano que indica se o nó é folha ou não!*/
  TIPO chaves[2 * T + 1]; /*Número máximo de chaves {tipo char} em um nó!*/
  struct _node *filhos[2 * T]; /*Ponteiros para os filhos de cada nó!*/
} No, Arvore;

Arvore* criar ();
void imprimir (Arvore *a, int nivel);
int buscar (Arvore *a, TIPO chave);
Arvore* remover (Arvore *raiz, TIPO chave);
Arvore *inserir (Arvore *raiz, TIPO chave);



#endif   /* ___ARVOREB_H_ */
