#ifndef __ARVORE_H
#define __ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _arvore {
  int info;
  struct _arvore *esq;
  struct _arvore *dir;
}Arvore;

Arvore* criaArvoreVazia ();
void destroiArvore (Arvore *A);
int altura (Arvore *A);
int balanceamento (Arvore *A);
Arvore* constroiArvore (char elem, Arvore *esq, Arvore *dir);
Arvore* constroiFolha (char elem);
Arvore* rotacaoSimplesEsq (Arvore *A);
Arvore* rotacaoSimplesDir (Arvore *A);
Arvore* rotacaoDuplaEsq (Arvore *A);
Arvore* rotacaoDuplaDir (Arvore *A);
Arvore* atualizarBalanceamentoEsq (Arvore *A);
Arvore* atualizarBalanceamentoDir (Arvore *A);
Arvore* inserir (Arvore *A, int valor);
Arvore* inserirAVL (Arvore *A, int valor);
Arvore* remover (Arvore *A, int valor);
Arvore* removerAVL (Arvore *A, int valor);
int vazia (Arvore *A);
int folha (Arvore *A);
int min (Arvore *A);
int max (Arvore *A);
int menorRamo (Arvore *A);
int maiorRamo (Arvore *A);
int ancestral (Arvore *A, int esq, int dir);
void imprime (Arvore *A, int tipo);
void imprimeChar (int n, char c);
void imprimeFilhos (Arvore *A, int espacos, int tipo);
void imprimePreOrdem (Arvore *A, int tipo);
void imprimeInOrdem (Arvore *A, int tipo);
void imprimePosOrdem (Arvore *A, int tipo);
void imprimeMarcadores (Arvore *A, int tipo);
void imprimeEscada (Arvore *A, int nivel, int tipo);
int pertenceArvore (Arvore *A, char c);
int buscaBinaria (Arvore *A, int valor);
int contaNos (Arvore *A);
int contaNosFolha (Arvore *A);
void espelhoSimilar (Arvore *A);
int retornaTamanhoVetor (int altura);
void porNiveis (Arvore *A, int altura, int tipo);
void imprimePorNiveis (Arvore **V, int tamanhoVetor, int iterador, int espacador, int tipo);

typedef struct _arvorePalavra {
  char *S;
  struct _arvorePalavra *esq;
  struct _arvorePalavra *dir;
}ArvorePalavra;

ArvorePalavra* inserirPalavra (ArvorePalavra *A, char *S);
int alturaPalavra (ArvorePalavra *A);
int balanceamentoPalavra (ArvorePalavra *A);
void imprimeEscadaPalavras (ArvorePalavra *A, int nivel);
void destroiArvorePalavra (ArvorePalavra *A);
ArvorePalavra* rotacaoSimplesEsqP (ArvorePalavra *A);
ArvorePalavra* rotacaoSimplesDirP (ArvorePalavra *A);
ArvorePalavra* rotacaoDuplaEsqP (ArvorePalavra *A);
ArvorePalavra* rotacaoDuplaDirP (ArvorePalavra *A);
ArvorePalavra* atualizarBalanceamentoEsqP (ArvorePalavra *A);
ArvorePalavra* atualizarBalanceamentoDirP (ArvorePalavra *A);

#endif /* __ARVORE_H */
