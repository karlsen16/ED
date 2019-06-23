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

ArvoreB* inicialEu() {
  ArvoreB *A = constroiArvoreBVazia();
  A = inserir(A, 'A');
  A = inserir(A, 'D');
  A = inserir(A, 'E');
  A = inserir(A, 'B');
  A = inserir(A, 'C');
  return A;
}

ArvoreB* inicialLista2() {
  ArvoreB *A = constroiArvoreBVazia();
  A = inserir(A, 91);
  A = inserir(A, 90);
  A = inserir(A, 80);
  A = inserir(A, 71);
  A = inserir(A, 72);
  A = inserir(A, 50);
  A = inserir(A, 45);
  A = inserir(A, 47);
  A = inserir(A, 10);
  A = inserir(A, 8);
  A = inserir(A, 7);
  A = inserir(A, 5);
  A = inserir(A, 2);
  A = inserir(A, 3);
  A = inserir(A, 22);
  A = inserir(A, 44);
  A = inserir(A, 55);
  A = inserir(A, 66);
  A = inserir(A, 68);
  A = inserir(A, 17);
  A = inserir(A, 6);
  A = inserir(A, 21);
  A = inserir(A, 67);
  return A;
}

ArvoreB* inicialMago() {
  ArvoreB *A = constroiArvoreBVazia();
  A = inserir(A, 47);
  A = inserir(A, 57);
  A = inserir(A, 73);
  A = inserir(A, 74);
  A = inserir(A, 77);
  A = inserir(A, 78);
  A = inserir(A, 94);
  A = inserir(A, 22);
  A = inserir(A, 19);
  A = inserir(A, 8);
  A = inserir(A, 37);
  A = inserir(A, 7);
  A = inserir(A, 2);
  A = inserir(A, 5);
  A = inserir(A, 6);
  return A;
}

void exercicio1 (ArvoreB *A) {
  imprimir(A, 0);
}

void exercicio2 (ArvoreB *A) {
  imprimir(A, 0);
  A = remover(A, 'D');
  A = remover(A, 'E');
  A = remover(A, 'B');
  // A = remover(A, 'S');
  // A = remover(A, 'Y');
  // A = remover(A, 'Z');
  printf("\n");
  imprimir(A, 0);
}

void exercicio3 (ArvoreB *A) {
  imprimir(A, 0);
  printf("\nEncontrou o 'N'? %d.\n\n", buscar(A, 'N'));
}
