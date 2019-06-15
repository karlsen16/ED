#include "exercicios.h"
#include "arvore.h"
#define CHAR 0
#define INT 1

Arvore* inicialExerciciosArvore () {
  return constroiArvore('a', constroiArvore('b', NULL, constroiFolha('d')), constroiArvore('c', constroiFolha('e'), constroiFolha('f')));;
}

void exercicio1Arvore (Arvore *A) {
  printf("Pre-ordem:\n");
  imprimePreOrdem(A, CHAR);
  printf("\nIn-ordem:\n");
  imprimeInOrdem(A, CHAR);
  printf("\nPos-ordem:\n");
  imprimePosOrdem(A, CHAR);
  printf("\n\n");
}

void exercicio2Arvore (Arvore *A) {
  printf("Marcadores:\n");
  imprimeMarcadores(A, CHAR);
  printf("\n\n");
}

void exercicio3Arvore (Arvore *A) {
  char c;
  printf("Informe o char a ser procurado:\n");
  scanf(" %c", &c);
  printf("Ele pertence? -> %d\n\n", pertenceArvore(A, c));
}

void exercicio4Arvore (Arvore *A) {
  printf("O numero de nos e: %d\n\n", contaNos(A));
}

void exercicio5Arvore (Arvore *A) {
  printf("A altura e: %d\n\n", altura(A));
}

void exercicio6Arvore (Arvore *A) {
  printf("O numero de nos folha e: %d\n\n", contaNosFolha(A));
}

Arvore* inicialExerciciosABB () {
  Arvore *A = NULL;
  A = inserir (A, 50);
  A = inserir (A, 30);
  A = inserir (A, 90);
  A = inserir (A, 20);
  A = inserir (A, 40);
  A = inserir (A, 95);
  A = inserir (A, 10);
  A = inserir (A, 35);
  A = inserir (A, 45);
  return A;
}

void exercicioABB1 (Arvore *A) {
  int r;
  imprimeInOrdem(A, INT);
  printf("\n\nDigite um valor para ser removido:\n");
  scanf("%d", &r);
  A = remover(A, r);
  printf("\n\n");
  imprimeInOrdem(A, INT);
  printf("\n\nDigite um valor para ser buscado:\n");
  scanf("%d", &r);
  printf("\n\nEle pertence? -> %d\n\n", buscaBinaria(A, r));
}

void exercicioABB2 (Arvore *A) {
  imprimeInOrdem(A, INT);
  printf("\n\nMin: %d\n\n", min(A));
  printf("Max: %d\n\n", max(A));
}

void exercicioABB3 () {
  Arvore *B = criaArvoreVazia();
  clock_t Ticks[4];
  int n = 10000;
  int i = 0;

  Ticks[0] = clock();
  while(i < n)
    B = inserir(B, i++);
  Ticks[1] = clock();
  Ticks[2] = clock();
  i = buscaBinaria(B, n);
  Ticks[3] = clock();

  printf("\n\nBusca: %d\n", i);
  printf("\nClock Inserir: %gms\n", (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
  printf("\nClock Buscar: %gms\n\n", (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC);
}

void exercicioABB4 () {
  Arvore *B = criaArvoreVazia();
  clock_t Ticks[4];
  srand(time(NULL));
  int n = 10000;
  int i = 0;

  Ticks[0] = clock();
  while(i < n) {
    B = inserir(B, rand()%n);
    i++;
  }
  Ticks[1] = clock();
  Ticks[2] = clock();
  i = buscaBinaria(B, n);
  Ticks[3] = clock();

  printf("\n\nBusca: %d\n", i);
  printf("\nClock Inserir: %gms\n", (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
  printf("\nClock Buscar: %gms\n\n", (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC);
}

void exercicioABB5 (Arvore *A) {
  imprimeInOrdemR(A, INT);
  printf("\n\n");
}

void exercicioABB6 (Arvore *A) {
  imprimeInOrdem(A, INT);
  printf("\n\nMaior ramo: %d.\n", maiorRamo(A));
  printf("\nMenor ramo: %d.\n\n", menorRamo(A));
  A = remover(A, 10);
  A = inserir(A, 46);
  A = inserir(A, 47);
  A = inserir(A, 19);
  A = inserir(A, 18);
  A = inserir(A, 17);
  A = inserir(A, 16);
  imprimeInOrdem(A, INT);
  printf("\n\nMaior ramo: %d.\n", maiorRamo(A));
  printf("\nMenor ramo: %d.\n\n", menorRamo(A));
}

void exercicioABB7 () {
  Arvore *A = criaArvoreVazia();
  A = inserir (A, 20);
  A = inserir (A, 8);
  A = inserir (A, 22);
  A = inserir (A, 4);
  A = inserir (A, 12);
  A = inserir (A, 10);
  A = inserir (A, 14);
  int esq, dir;
  printf("Digite os dois nós:\n");
  scanf("%d %d", &esq, &dir);
  printf("\nAncestral: %d\n\n", ancestral(A, esq, dir));
}

void exercicioExtra () {
  Arvore *A = criaArvoreVazia();
  A = inserir (A, 50);
  A = inserir (A, 30);
  A = inserir (A, 90);
  A = inserir (A, 20);
  A = inserir (A, 40);
  A = inserir (A, 95);
  porNiveis(A, 2);
  espelhoSimilar(A);
  porNiveis(A, 2);
}
