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

void listaNumeroArestasIncidentesAdj (int u, GrafoA *G) {
  int cont = 0, i;
  for(i = 0; i < G->V; i++){
    NoA *v;
    for(v = G->Adj[i]; v!= NULL; v = v->next)
      if(v->id == u)
        cont++;
  }
  printf("Lista de arestas incidentes ao vertice %d: %d.\n\n", u, cont);
}

void listaNumeroArestasSaemAdj (int u, GrafoA *G) {
  int cont = 0;
  NoA *v;
  for(v = G->Adj[u]; v!= NULL; v = v->next)
    cont++;
  printf("Lista de arestas que saem do vertice %d: %d.\n\n", u, cont);
}

void listaVerticesAdjacentesAdj (int u, GrafoA *G) {
  printf("Vertices adjacentes ao vertice %d:", u);
  NoA *v;
  for(v = G->Adj[u]; v!= NULL; v = v->next)
    printf(" %d", v->id);
  printf(".\n\n");
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

void listaNumeroArestasIncidentesMatriz (int u, GrafoM *G) {
  int cont = 0, i;
  for(i = 0; i < G->V; i++)
    if(G->Mat[i][u].peso != 0)
      cont++;
  printf("Lista de arestas incidentes ao vertice %d: %d.\n\n", u, cont);
}

void listaNumeroArestasSaemMatriz (int u, GrafoM *G) {
  int cont = 0, i;
  for(i = 0; i < G->V; i++)
    if(G->Mat[u][i].peso != 0)
      cont++;
  printf("Lista de arestas que saem do vertice %d: %d.\n\n", u, cont);
}

void listaVerticesAdjacentesMatriz (int u, GrafoM *G) {
  int i;
  printf("Vertices adjacentes ao vertice %d:", u);
  for(i = 0; i < G->V; i++)
    if(G->Mat[u][i].peso != 0)
      printf(" %d", i);
  printf(".\n\n");
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

void imprimeGrafoAdjPonderado (GrafoA *G) {
  int i;
  printf("Grafo (Lista de adjacencia):\n");
  for(i = 0; i < G->V; i++) {
    printf("%2d -> ", i);
    NoA *v;
    for(v = G->Adj[i]; v != NULL; v = v->next)
      printf("%2d (w:%d)  ", v->id, v->peso);
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
