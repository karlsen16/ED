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

ArvoreB* remover (ArvoreB *A, TIPO chave);




/*
typedef struct _local {
  int nivel;
  int no;
  int indice;
  int found;
  TIPO chave;
}Local;

Local* iniciaBusca (ArvoreB *A, TIPO chave);
void destroiLocal (Local *L);
Local* buscar (ArvoreB *A, Local *L);
*/

#endif   /* ___ARVOREB_H_ */
