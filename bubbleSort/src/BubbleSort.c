#include "stdafx.h"
#include "BubbleSort.h"

void bubbleSort (int n, void *V, int tam, int (*cmp)(void*, void*)) {
  int i;
  for(i = n-1; i > 0; i--) {
    int j, guarda = 0;
    for(j = 0; j < i; j++) {
      void *p1 = acessa(V, j, tam);
      void *p2 = acessa(V, j+1, tam);
      if(cmp(p1, p2)) {
        troca(p1, p2, tam);
        guarda = 1;
      }
    }
    if(!guarda)
      return;
  }
}

static void* acessa (void *V, int i, int tam) {
  char *t = (char*)V;
  t += tam*i;
  return (void*)t;
}

int comparaI (void *A, void *B) {
  int *p1 = (int*)A;
  int *p2 = (int*)B;
  return (*p1 > *p2);
}

int comparaS (void *A, void *B) {
  TIPO *p1 = (TIPO*)A;
  TIPO *p2 = (TIPO*)B;
  if(strcmp(p1->CAMPO, p2->CAMPO) > 0)
    return 1;
  else
    return 0;
}

static void troca (void *A, void *B, int tam) {
  char *p1 = (char*)A;
  char *p2 = (char*)B;
  int i;
  for(i = 0; i < tam; i++) {
    char aux = p1[i];
    p1[i] = p2[i];
    p2[i] = aux;
  }
}

void imprime (int n, void *V, char *S) {
  PTIPO *p = (PTIPO*)V;
  int i;
  for(i = 0; i < n; i++)
    printf(S, p[i]EP);
  printf("\n\n");
}
