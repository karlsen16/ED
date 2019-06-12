#include "grafos.h"
#include <stdlib.h>

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criarGrafoAdj (int tamanho) {
  int v;
  GrafoA *G = (GrafoA*)malloc(sizeof(GrafoA));
  G->E = 0;
  G->V = tamanho;
  G->Adj = (NoA**)malloc(tamanho*sizeof(NoA*));
  for(v = 0; v < G->V; v++)
    G->Adj[v] = NULL;
  return G;
}

void adicionaArestaGrafoA (int u, int v, GrafoA *G, int peso) {
  NoA *aux, *ultimo = NULL;
  for(aux = G->Adj[u]; aux != NULL; aux = aux->next) {
    if (aux->id == v) {
      printf("a aresta (%d,%d) já existe!!!\n", u, v);
      return;
    }
    ultimo = aux;
  }
  NoA *novo = (NoA*)malloc(sizeof(NoA));
  novo->id = v;
  novo->next = NULL;
  if(peso != 0)
    novo->peso = peso;
  if(ultimo != NULL)
    ultimo->next = novo;
  else
    G->Adj[u] = novo;
  G->E++;
}

void adicionaArestaLista (int u, int v, GrafoA *G, int peso) {
  adicionaArestaGrafoA (u, v, G, peso);
  adicionaArestaGrafoA (v, u, G, peso);
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criarGrafoMatriz (int tamanho) {
  int v;
  GrafoM *G = (GrafoM*)malloc(sizeof(GrafoM));
  G->E = 0;
  G->V = tamanho;
  G->Mat = (NoM**)malloc(tamanho*sizeof(NoM*));
  for (v = 0; v < G->V; v++)
    G->Mat[v] = (NoM*)malloc(tamanho*sizeof(NoM));
  return G;
}

void inicializaGrafoMat (GrafoM *G) {
  int i, j;
  for(i = 0; i < G->V; i++)
    for(j = 0; j < G->V; j++)
      G->Mat[i][j].peso = 0;
}

void adicionaArestaGrafoM (int u, int v, GrafoM *G, int peso) {
  if(G->Mat[u][v].peso == 0)
    G->Mat[u][v].peso = peso;
  else
    printf("a aresta (%d,%d) ja existe!!!\n", u, v);
  G->E++;
}

void adicionaArestaMatriz (int u, int v, GrafoM *G, int peso) {
  adicionaArestaGrafoM (u, v, G, peso);
  adicionaArestaGrafoM (v, u, G, peso);
}

void imprimeGrafoMat (GrafoM *G) {
  int i, j;
  printf("Grafo (Matriz de adjacencia):\n    ");
  for(i = 0; i < G->V; i++)
    printf("%2d ", i);
  printf("\n\n");
  for(i = 0; i < G->V; i++) {
    printf("%2d  ", i);
    for(j = 0; j < G->V; j++)
      printf("%2d ", G->Mat[i][j].peso);
    printf("\n");
  }
  printf("\n");
}

void imprimeGrafoAdj (GrafoA *G) {
  int i;
  printf("Grafo (Lista de adjacencia):\n");
  for(i = 0; i < G->V; i++) {
    printf("%2d -> ", i);
    NoA *v;
    for(v = G->Adj[i]; v != NULL; v = v->next)
      printf("%2d ", v->id);
    printf("\n");
  }
  printf("\n");
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberarGrafoAdj (GrafoA *G) {
  int v;
  for (v = 0; v < G->V; v++)
    if (G->Adj[v] != NULL)
      free(G->Adj[v]);
  free(G->Adj);
  free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberarGrafoMatriz (GrafoM *G) {
  int v;
  for (v = 0; v < G->V; v++)
    if (G->Mat[v] != NULL)
      free(G->Mat[v]);
  free(G->Mat);
  free(G);
}

void exercicio1 () {
  int verticesGrafoMatriz = 6;
  GrafoM* grafoMatriz = criarGrafoMatriz (verticesGrafoMatriz);
  inicializaGrafoMat(grafoMatriz);
  adicionaArestaMatriz(0, 1, grafoMatriz, 1);
  adicionaArestaMatriz(0, 2, grafoMatriz, 1);
  adicionaArestaMatriz(0, 5, grafoMatriz, 1);
  adicionaArestaMatriz(1, 2, grafoMatriz, 1);
  adicionaArestaMatriz(1, 3, grafoMatriz, 1);
  adicionaArestaMatriz(2, 3, grafoMatriz, 1);
  adicionaArestaMatriz(2, 4, grafoMatriz, 1);
  adicionaArestaMatriz(3, 4, grafoMatriz, 1);
  adicionaArestaMatriz(4, 5, grafoMatriz, 1);
  imprimeGrafoMat(grafoMatriz);

  int verticesGrafoListaAdj = 6;
  GrafoA* grafoListaAdj = criarGrafoAdj (verticesGrafoListaAdj);
  adicionaArestaLista(0, 1, grafoListaAdj, 1);
  adicionaArestaLista(0, 2, grafoListaAdj, 1);
  adicionaArestaLista(0, 5, grafoListaAdj, 1);
  adicionaArestaLista(1, 2, grafoListaAdj, 1);
  adicionaArestaLista(1, 3, grafoListaAdj, 1);
  adicionaArestaLista(2, 3, grafoListaAdj, 1);
  adicionaArestaLista(2, 4, grafoListaAdj, 1);
  adicionaArestaLista(3, 4, grafoListaAdj, 1);
  adicionaArestaLista(4, 5, grafoListaAdj, 1);
  imprimeGrafoAdj(grafoListaAdj);

  liberarGrafoAdj (grafoListaAdj);
  liberarGrafoMatriz (grafoMatriz);
}

void exercicio2 () {
  int verticesGrafoMatriz = 6;
  GrafoM* grafoMatriz = criarGrafoMatriz (verticesGrafoMatriz);
  inicializaGrafoMat(grafoMatriz);
  adicionaArestaGrafoM(0, 1, grafoMatriz, 1);
  adicionaArestaGrafoM(0, 5, grafoMatriz, 1);
  adicionaArestaGrafoM(1, 2, grafoMatriz, 1);
  adicionaArestaGrafoM(1, 3, grafoMatriz, 1);
  adicionaArestaGrafoM(3, 2, grafoMatriz, 1);
  adicionaArestaGrafoM(2, 0, grafoMatriz, 1);
  adicionaArestaGrafoM(2, 4, grafoMatriz, 1);
  adicionaArestaGrafoM(4, 3, grafoMatriz, 1);
  adicionaArestaGrafoM(5, 4, grafoMatriz, 1);
  imprimeGrafoMat(grafoMatriz);

  int verticesGrafoListaAdj = 6;
  GrafoA* grafoListaAdj = criarGrafoAdj (verticesGrafoListaAdj);
  adicionaArestaGrafoA(0, 1, grafoListaAdj, 1);
  adicionaArestaGrafoA(0, 5, grafoListaAdj, 1);
  adicionaArestaGrafoA(1, 2, grafoListaAdj, 1);
  adicionaArestaGrafoA(1, 3, grafoListaAdj, 1);
  adicionaArestaGrafoA(3, 2, grafoListaAdj, 1);
  adicionaArestaGrafoA(2, 0, grafoListaAdj, 1);
  adicionaArestaGrafoA(2, 4, grafoListaAdj, 1);
  adicionaArestaGrafoA(4, 3, grafoListaAdj, 1);
  adicionaArestaGrafoA(5, 4, grafoListaAdj, 1);
  imprimeGrafoAdj(grafoListaAdj);

  liberarGrafoAdj (grafoListaAdj);
  liberarGrafoMatriz (grafoMatriz);
}

void exercicio3 () {
  int verticesGrafoMatriz = 6;
  GrafoM* grafoMatriz = criarGrafoMatriz (verticesGrafoMatriz);
  inicializaGrafoMat(grafoMatriz);
  adicionaArestaGrafoM(0, 1, grafoMatriz, 1);
  adicionaArestaGrafoM(0, 3, grafoMatriz, 5);
  adicionaArestaGrafoM(1, 3, grafoMatriz, 8);
  adicionaArestaGrafoM(3, 4, grafoMatriz, 3);
  adicionaArestaGrafoM(3, 3, grafoMatriz, 6);
  adicionaArestaGrafoM(2, 0, grafoMatriz, 5);
  adicionaArestaGrafoM(2, 3, grafoMatriz, 4);
  adicionaArestaGrafoM(4, 2, grafoMatriz, 7);
  adicionaArestaGrafoM(4, 5, grafoMatriz, 9);
  adicionaArestaGrafoM(5, 0, grafoMatriz, 2);
  imprimeGrafoMat(grafoMatriz);

  int verticesGrafoListaAdj = 6;
  GrafoA* grafoListaAdj = criarGrafoAdj (verticesGrafoListaAdj);
  adicionaArestaGrafoA(0, 1, grafoListaAdj, 1);
  adicionaArestaGrafoA(0, 3, grafoListaAdj, 5);
  adicionaArestaGrafoA(1, 3, grafoListaAdj, 8);
  adicionaArestaGrafoA(3, 4, grafoListaAdj, 3);
  adicionaArestaGrafoA(3, 3, grafoListaAdj, 6);
  adicionaArestaGrafoA(2, 0, grafoListaAdj, 5);
  adicionaArestaGrafoA(2, 3, grafoListaAdj, 4);
  adicionaArestaGrafoA(4, 2, grafoListaAdj, 7);
  adicionaArestaGrafoA(4, 5, grafoListaAdj, 9);
  adicionaArestaGrafoA(5, 0, grafoListaAdj, 2);
  imprimeGrafoAdj(grafoListaAdj);

  liberarGrafoAdj (grafoListaAdj);
  liberarGrafoMatriz (grafoMatriz);
}
