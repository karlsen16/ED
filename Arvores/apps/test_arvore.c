#include "arvore.h"
#include "exercicios.h"

int main () {

  Arvore *A = inicialExerciciosArvore();
  // exercicio1Arvore(A);
  // exercicio2Arvore(A);
  // exercicio3Arvore(A);
  // exercicio4Arvore(A);
  // exercicio5Arvore(A);
  // exercicio6Arvore(A);

  Arvore *B = inicialExerciciosABB();

  // exercicioABB1(B);
  // exercicioABB2(B);
  // exercicioABB3();
  // exercicioABB4();
  // exercicioABB5(B);
  // exercicioABB6(B);
  // exercicioABB7();

  exercicioExtra();

  destroiArvore(A);
  destroiArvore(B);

  return 0;
}
