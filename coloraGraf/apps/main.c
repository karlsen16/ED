#include "grafos.h"

int main () {
  GrafoA *G = inicializaGrafoAdj();
  exercicio1 (G);
  liberarGrafoAdj(G);

  return 0;
}
