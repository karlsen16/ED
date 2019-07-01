#ifndef ___GRAFOS_H__
#define ___GRAFOS_H__
#define TAM 11
#define TRUE 1
#define FALSE 0
#include <stdio.h>

typedef struct noA {
   int id;
   struct noA *next;
   int visivel;
} NoA;

typedef struct grafoA {
   int E;
   int V;
   NoA **Adj;
   int *grau;
   int *sat;
   int *cor;
} GrafoA;

GrafoA* criarGrafoAdj (int tamanho);
void adicionaArestaGrafoA (int u, int v, GrafoA *G);
void imprimeGrafoAdj (GrafoA *G);
void liberarGrafoAdj (GrafoA *G);
void liberaNos (NoA *N);
void removeNo (GrafoA *G, int indice);
GrafoA* inicializaGrafoAdj ();
int leValor (FILE *F, int *E);
int proximoNo (GrafoA *G, int indice);
int colorido (GrafoA *G, int indice);
void atualizaSat (int indice, GrafoA *G);
int vizinhoCor (int indice, int i, int cor, GrafoA *G);
int determinaCor (GrafoA *G, int indice);
void exercicio1 (GrafoA *G);

#endif /*___GRAFOS_H__ */
