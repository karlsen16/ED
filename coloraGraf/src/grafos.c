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
  novo->visivel = TRUE;
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
        if(v->visivel)
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

void removeNo (GrafoA *G, int indice) {
  int v;
  NoA *walk;
  for(walk = G->Adj[indice]; walk != NULL; walk = walk->next)
    walk->visivel = FALSE;
  G->E -= G->grau[indice];
  G->grau[indice] = 0;
  for (v = 0; v < G->V; v++)
    if (G->Adj[v] != NULL)
      for(walk = G->Adj[v]; walk != NULL; walk = walk->next)
        if(walk->id == indice) {
          walk->visivel = FALSE;
          G->E--;
          if(G->grau[v])
            G->grau[v]--;
          break;
        }
}

GrafoA* inicializaGrafoAdj () {
  FILE *F = fopen("teste.csv", "r");
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

int proximoNo (GrafoA *G, int indice) {
  int i = -1, maiorGrau, maiorSat;
  NoA *walk;
  maiorGrau = maiorSat = 0;
  for(walk = G->Adj[indice]; walk != NULL; walk = walk->next)
    if(!colorido(G, walk->id) && G->sat[walk->id] >= maiorSat && G->grau[walk->id] >= maiorGrau) {
      maiorSat = G->sat[walk->id];
      maiorGrau = G->grau[walk->id];
      i = walk->id;
    }
  if(i == -1) {
    int j;
    for(j = 0; j < G->V; j++)
      if(!colorido(G, j) && G->sat[j] >= maiorSat && G->grau[j] >= maiorGrau) {
        maiorSat = G->sat[j];
        maiorGrau = G->grau[j];
        i = j;
      }
  }
  return i;
}

int colorido (GrafoA *G, int indice) {
  return(G->cor[indice]);
}

void atualizaSat (int indice, GrafoA *G) {
  NoA *v;
  for(v = G->Adj[indice]; v!= NULL; v = v->next)
    if(!vizinhoCor(v->id, indice, G->cor[indice], G))
      G->sat[v->id]++;
}

int vizinhoCor (int indice, int i, int cor, GrafoA *G) {
  NoA *v;
  for(v = G->Adj[indice]; v!= NULL; v = v->next)
    if(G->cor[v->id] == cor && v->id != i)
      return TRUE;
  return FALSE;
}

int determinaCor (GrafoA *G, int indice) {
  int i = 1, flag = 1;
  NoA *walk;
  while(flag == 1) {
    for(walk = G->Adj[indice]; walk != NULL; walk = walk->next) {
      if(G->cor[walk->id] == i)
        break;
    }
    if(walk == NULL)
      flag = 0;
    else
      i++;
  }
  return i;
}

void exercicio1 (GrafoA *G) {
  imprimeGrafoAdj(G);
  int indice = 0, i, V = 0;
  for(i = 0; i < G->V; i++)
    if(G->grau[i] > V) {
      V = G->grau[i];
      indice = i;
    }
  V = G->V-2;
  printf("\nNo escolhido: %d\n\n", indice);
  G->cor[indice] = 1;
  removeNo(G, indice);
  imprimeGrafoAdj(G);
  scanf("%d", &i);
  while(V > 0) {
    atualizaSat(indice, G);
    indice = proximoNo(G, indice);
    printf("\nNo escolhido: %d\n\n", indice);
    G->cor[indice] = determinaCor(G, indice);
    removeNo(G, indice);
    imprimeGrafoAdj(G);
    scanf("%d", &i);
    V--;
  }
  imprimeGrafoAdj(G);
}
