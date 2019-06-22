#include "exercicios.h"
#include "arvoreb.h"

ArvoreB* inicialCormen() {
  ArvoreB *A = constroiArvoreBVazia();
  A = inserir(A, 'F');
  A = inserir(A, 'S');
  A = inserir(A, 'Q');
  A = inserir(A, 'K');
  A = inserir(A, 'C');
  A = inserir(A, 'L');
  A = inserir(A, 'H');
  A = inserir(A, 'T');
  A = inserir(A, 'V');
  A = inserir(A, 'W');
  A = inserir(A, 'M');
  A = inserir(A, 'R');
  A = inserir(A, 'N');
  A = inserir(A, 'P');
  A = inserir(A, 'A');
  A = inserir(A, 'B');
  A = inserir(A, 'X');
  A = inserir(A, 'Y');
  A = inserir(A, 'D');
  A = inserir(A, 'Z');
  A = inserir(A, 'E');
  return A;
}

void exercicioCormen (ArvoreB *A) {
  imprimir(A, 0);
}

void exercicio1 () {
  ArvoreB *A = constroiArvoreBVazia();
  A = inserir(A, 'D');
  A = inserir(A, 'H');
  A = inserir(A, 'L');
  A = inserir(A, 'A');
  A = inserir(A, 'B');
  A = inserir(A, 'C');
  A = inserir(A, 'E');
  A = inserir(A, 'F');
  A = inserir(A, 'G');
  A = inserir(A, 'I');
  A = inserir(A, 'J');
  A = inserir(A, 'K');
  A = inserir(A, 'M');
  A = inserir(A, 'N');
  A = inserir(A, 'O');
  imprimir(A, 0);
  destroiArvoreB(A);
}
