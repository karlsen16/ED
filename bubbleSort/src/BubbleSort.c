#include "stdafx.h"
#include "BubbleSort.h"

void bubbleSort (int *V, int tam) {
  int i;
  for(i = tam-1; i > 1; i--) {
    int j;
    for(j = 0; j < i; j++)
      if(V[j] > V[j+1]) {
        int aux = V[j];
        V[j] = V[j+1];
        V[j+1] = aux;
      }
  }
}

void imprime (int *V, int tam) {
  int i;
  for(i = 0; i < tam; i++)
    printf("%+03d", V[i]);
    pritnf("\n\n");
}
