#ifndef ___GRAFOS_H__
#define ___GRAFOS_H__
#include <stdio.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

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

GrafoA* criar_grafo_adj (int tamanho);
void insere_verticeA (GrafoA *G, int id);
void imprime_grafoA (GrafoA *G);


GrafoM* criar_grafo_mat (int tamanho);
void liberar_grafo_adj (GrafoA *G);
void liberar_grafo_mat (GrafoM *G);



#endif /*___GRAFOS_H__ */
