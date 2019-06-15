#ifndef __ARVORE_H
#define __ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _arvore {
  int info;
  struct _arvore *esq;
  struct _arvore *dir;
} Arvore;

Arvore* criaArvoreVazia ();
void destroiArvore (Arvore *A);
Arvore* constroiArvore (char elem, Arvore *esq, Arvore *dir);
Arvore* constroiFolha (char elem);
Arvore* inserir (Arvore *A, int valor);
Arvore* remover (Arvore *A, int valor);
int vazia (Arvore *A);
int folha (Arvore *A);
int min (Arvore *A);
int max (Arvore *A);
int menorRamo (Arvore *A);
int maiorRamo (Arvore *A);
int ancestral (Arvore *A, int esq, int dir);
void imprimePreOrdem (Arvore *A, int tipo);
void imprimeInOrdem (Arvore *A, int tipo);
void imprimePosOrdem (Arvore *A, int tipo);
void imprimePreOrdemR (Arvore *A, int tipo);
void imprimeInOrdemR (Arvore *A, int tipo);
void imprimePosOrdemR (Arvore *A, int tipo);
void imprimeMarcadores (Arvore *A, int tipo);
int pertenceArvore (Arvore *A, char c);
int buscaBinaria (Arvore *A, int valor);
int contaNos (Arvore *A);
int contaNosFolha (Arvore *A);
int altura (Arvore *A);
void espelhoSimilar (Arvore *A);
void porNiveis (Arvore *A, int altura);
int retornaTamanhoVetor (int altura);
void imprimePorNiveis (Arvore **V, int tamanhoVetor, int iterador);
void imprimeEspacos (int n);

#endif /* __ARVORE_H */
