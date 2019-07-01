#include "grafos.h"
#include <stdlib.h>

GrafoA* criarGrafoAdj (int tamanho) {
  int v;
  GrafoA *G = (GrafoA*)malloc(sizeof(GrafoA));
  G->E = 0;
  G->V = tamanho;
  G->Adj = (NoA**)malloc(tamanho*sizeof(NoA*));
  G->grau = (int*)malloc(tamanho*sizeof(int));
  G->sat = (int*)malloc(tamanho*sizeof(int));
  G->cor = (int*)malloc(tamanho*sizeof(int));
  for(v = 0; v < G->V; v++) {
    G->Adj[v] = NULL;
    G->grau[v] = 0;
    G->sat[v] = 0;
    G->cor[v] = 0;
  }
  return G;
}

void adicionaArestaGrafoA (int u, int v, GrafoA *G) {
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
  if(ultimo != NULL)
    ultimo->next = novo;
  else
    G->Adj[u] = novo;
  G->E++;
  G->grau[u]++;
}

void imprimeGrafoAdj (GrafoA *G) {
  int i;
  printf("Grafo (Lista de adjacencia):\n");
  if(G != NULL) {
    for(i = 1; i < G->V; i++) {
      printf("%2d (g:%2d) (c:%2d) (s:%2d) -> ", i, G->grau[i], G->cor[i], G->sat[i]);
      NoA *v;
      for(v = G->Adj[i]; v != NULL; v = v->next)
        printf("%2d ", v->id);
      printf("\n");
    }
    printf("\n");
  }
}

void liberarGrafoAdj (GrafoA *G) {
  if(G != NULL) {
    int v;
    for (v = 0; v < G->V; v++)
      if (G->Adj[v] != NULL)
        liberaNos(G->Adj[v]);
    free(G->Adj);
    free(G->grau);
    free(G->sat);
    free(G->cor);
    free(G);
  }
}

void liberaNos (NoA *N) {
  if(N != NULL) {
    if(N->next != NULL)
      liberaNos(N->next);
    free(N);
  }
}

GrafoA* inicializaGrafoAdj () {
  FILE *F = fopen("grafo08.csv", "r");
  GrafoA *G = criarGrafoAdj(TAM);
  int i, v, flag = 1;
  i = leValor(F, &flag);
  do {
    flag = 1;
    do {
      v = leValor(F, &flag);
      adicionaArestaGrafoA(i, v, G);
    }while(flag == 1);
    i = leValor(F, &flag);
  }while(i != -1);
  printf("\n");
  fclose(F);
  return G;
}

int leValor (FILE *F, int *E) {
  int i = 0;
  char C = getc(F);
  if(C == -1)
    return -1;
  if(C == 32)
    C = getc(F);
  while(C != 44 && C != 10) {
    i *= 10;
    i += C-48;
    C = getc(F);
  }
  if(C == 10)
    *E = 0;
  return i;
}

int maiorGrau (GrafoA *G) {
  int i, maiorGrau, maiorSat, indice;
  maiorGrau = maiorSat = indice = 0;
  for(i = 0; i < G->V; i++)
    if(!colorido(G, i) && G->sat[i] >= maiorSat && G->grau[i] > maiorGrau) {
      maiorSat = G->sat[i];
      maiorGrau = G->grau[i];
      indice = i;
    }
  return indice;
}

int colorido (GrafoA *G, int indice) {
  return(G->cor[indice]);
}

void atualizaSat (int indice, GrafoA *G) {
  NoA *v;
  for(v = G->Adj[indice]; v!= NULL; v = v->next)
    G->sat[v->id]++;
}

void removeNo (GrafoA *G, int indice) {
  liberaNos(G->Adj[indice]);
  G->E -= G->grau[indice];
  G->grau[indice] = 0;
  G->Adj[indice] = NULL;
  int v;
  NoA *walk, *aux;
  for (v = 0; v < G->V; v++) {
    aux = NULL;
    if (G->Adj[v] != NULL)
      for(walk = G->Adj[v]; walk != NULL; walk = walk->next) {
        if(walk->id == indice) {
          if(aux == NULL)
            G->Adj[v] = walk->next;
          else if(walk->next == NULL)
            aux->next = NULL;
          else
            aux->next = walk->next;
          free(walk);
          G->E--;
          G->grau[v]--;
          break;
        }
      aux = walk;
      }
  }
}

/*int determinaCor (GrafoA *G, int indice) {
  int i = 1, flag = 1;
  NoA *walk;
  while(flag == 1) {
    for(walk = G->Adj[indice]; walk != NULL; walk = walk->next) {
      if(walk->)
    }
  }
}*/

void exercicio1 (GrafoA *G) {
  imprimeGrafoAdj(G);
  int indice = maiorGrau(G);
  printf("\nNo escolhido: %d\n\n", indice);
  //G->cor[indice] = determinaCor(G, indice);

  // removeNo(G, indice);
  // atualizaSat(indice, G);
  // imprimeGrafoAdj(G);
}
