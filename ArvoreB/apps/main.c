#include "arvoreb.h"
#include "exercicios.h"

int main () {
  ArvoreB *A = inicialCormen();
  ArvoreB *B = inicialEu();
  ArvoreB *C = inicialLista2();
  ArvoreB *D = inicialMago();

  // exercicio1(A);
  // exercicio2(A);
  // exercicio3(A);

  destroiArvoreB(A);
  destroiArvoreB(B);
  destroiArvoreB(C);
  destroiArvoreB(D);
  return 0;
}
