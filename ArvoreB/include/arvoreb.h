#ifndef ___ARVOREB_H_
#define ___ARVOREB_H_

#include <stdio.h>
#include <stdlib.h>

#define TIPO char
#define T 2
#define NOT_FOUND -1
#define TRUE 1
#define FALSE 0

typedef struct _arvoreB {
  int n;
  int folha;
  TIPO chaves[2*T-1];
  struct _arvoreB *filhos[2*T];
}ArvoreB;

ArvoreB* constroiArvoreBVazia ();
int vazia (ArvoreB *A);
int cheia (ArvoreB *A);
void destroiArvoreB (ArvoreB *A);
ArvoreB* constroiFolha ();
void imprimir (ArvoreB *A, int nivel);
int buscar (ArvoreB *A, TIPO chave);
ArvoreB *inserir (ArvoreB *A, TIPO chave);
void jogaPraDireita (ArvoreB *A, TIPO chave, int indice);
void moveNoMaiores (ArvoreB *O, ArvoreB* D, TIPO chave);
int retornaIndice (ArvoreB *A, TIPO chave);

ArvoreB* remover (ArvoreB *A, TIPO chave);

#endif   /* ___ARVOREB_H_ */
