#ifndef ___GRAFOS_H__
#define ___GRAFOS_H__
#include <stdio.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NIL -1

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
   int peso;        /*Peso armazenado na aresta. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

typedef struct dfs {
  int cor;
  int pai;
  int d;
  int f;
} DFS;

/*Estrutura para um nó em uma matriz de adjacências: */
typedef struct noM {
   int peso;       /*Peso armazenado na aresta. */
} NoM;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoM **Mat; /* Matrix de adjacências. */
} GrafoM;

GrafoA* criarGrafoAdj (int tamanho);
void adicionaArestaGrafoA (int u, int v, GrafoA *G, int peso);
void adicionaArestaLista (int u, int v, GrafoA *G, int peso);
void listaNumeroArestasIncidentesAdj (int u, GrafoA *G);
void listaNumeroArestasSaemAdj (int u, GrafoA *G);
void listaVerticesAdjacentesAdj (int u, GrafoA *G);
GrafoM* criarGrafoMatriz (int tamanho);
void inicializaGrafoMat (GrafoM *G);
void adicionaArestaGrafoM (int u, int v, GrafoM *G, int peso);
void adicionaArestaMatriz (int u, int v, GrafoM *G, int peso);
void listaNumeroArestasIncidentesMatriz (int u, GrafoM *G);
void listaNumeroArestasSaemMatriz (int u, GrafoM *G);
void listaVerticesAdjacentesMatriz (int u, GrafoM *G);
void imprimeGrafoMat (GrafoM *G);
void imprimeGrafoAdj (GrafoA *G);
void imprimeGrafoAdjPonderado (GrafoA *G);
void liberarGrafoAdj (GrafoA *G);
void liberarGrafoMatriz (GrafoM *G);

void Busca_Profundidade (GrafoA *G);
void DFS_Visit (GrafoA *G, int u, DFS *V, int *tempo);
void Caminho_DFS (int s, DFS *V);

#endif /*___GRAFOS_H__ */
