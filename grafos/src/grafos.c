#include "grafos.h"
#include <stdlib.h>

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

void insere_verticeA (GrafoA *G, int id) {
    NoA *n = (NoA *)malloc(sizeof(NoA));
    n->id = id;
    n->next = NULL;
    int i;
    for(i = 0; i < G->V; i++)
        if(G->Adj[i] == NULL){
            G->Adj[i] = n;
            break;
        }
}

void imprime_grafoA (GrafoA *G) {
    int i;
    for(i = 0; i < G->V; i++){
        printf("%d |>", G->Adj[i]->id);
        if(G->Adj[i] != NULL)
            printf("%d |>", G->Adj[i]->id);
        else
            printf("%  |>");
        while(G->Adj[i] != NULL){
            printf(" %d ", G->Adj[i]->id);
            G->Adj[i] = G->Adj[i]->next;
        }
        printf("\n");
    }
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (NoM **)malloc(tamanho * sizeof(NoM *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (NoM *)malloc(tamanho * sizeof(NoM));
   }
   return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}
