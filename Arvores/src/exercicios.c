#include "exercicios.h"
#include "arvore.h"
#define CHAR 0
#define INT 1
#define STRING 2

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
  printf("\nPor niveis:\n");
  int alturaArvore = altura(A);
  porNiveis(A, alturaArvore, CHAR);
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
  int r, alturaArvore;
  alturaArvore = altura(A);
  porNiveis(A, alturaArvore, INT);
  printf("\n\nDigite um valor para ser removido:\n");
  scanf("%d", &r);
  A = remover(A, r);
  printf("\n\n");
  porNiveis(A, alturaArvore, INT);
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
  destroiArvore(B);
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
  destroiArvore(B);
}

void exercicioABB5 (Arvore *A) {
  espelhoSimilar(A);
  imprimeInOrdem(A, INT);
  espelhoSimilar(A);
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
  A = inserir(A, 20);
  A = inserir(A, 8);
  A = inserir(A, 22);
  A = inserir(A, 4);
  A = inserir(A, 12);
  A = inserir(A, 10);
  A = inserir(A, 14);
  int esq, dir;
  printf("Digite os dois nós:\n");
  scanf("%d %d", &esq, &dir);
  printf("\nAncestral: %d\n\n", ancestral(A, esq, dir));
  destroiArvore(A);
}

void exercicioExtra () {
  Arvore *A = criaArvoreVazia();
  A = inserir(A, 50);
  A = inserir(A, 30);
  A = inserir(A, 90);
  A = inserir(A, 20);
  A = inserir(A, 40);
  A = inserir(A, 95);
  int alturaArvore = altura(A);
  porNiveis(A, alturaArvore, INT);
  espelhoSimilar(A);
  porNiveis(A, alturaArvore, INT);
  destroiArvore(A);
}

Arvore* inicialExerciciosAVL () {
  Arvore *A = criaArvoreVazia();
  A = inserirAVL(A, 'Q');
  A = inserirAVL(A, 'Z');
  A = inserirAVL(A, 'B');
  A = inserirAVL(A, 'Y');
  A = inserirAVL(A, 'T');
  A = inserirAVL(A, 'M');
  A = inserirAVL(A, 'E');
  A = inserirAVL(A, 'W');
  A = inserirAVL(A, 'X');
  A = inserirAVL(A, 'S');
  A = inserirAVL(A, 'F');
  A = inserirAVL(A, 'G');
  A = inserirAVL(A, 'A');
  A = inserirAVL(A, 'H');
  A = inserirAVL(A, 'N');
  A = inserirAVL(A, 'O');
  A = inserirAVL(A, 'P');
  A = inserirAVL(A, 'R');
  return A;
}

void exercicioAVL1 (Arvore *A) {
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
}

void exercicioAVL2 (Arvore *A) {
  printf("Inicial:\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'A');
  printf("###Removido o 'A':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'H');
  printf("###Removido o 'H':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'E');
  printf("###Removido o 'E':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'W');
  printf("###Removido o 'W':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'G');
  printf("###Removido o 'G':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'N');
  printf("###Removido o 'N':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'P');
  printf("###Removido o 'P':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
  A = removerAVL(A, 'O');
  printf("###Removido o 'O':\n");
  porNiveis(A, altura(A), CHAR);
  imprimeEscada(A, 0, CHAR);
}

void exercicioAVL3 () {
  Arvore *A = criaArvoreVazia();
  A = inserirAVL(A, 14);
  A = inserirAVL(A, 5);
  A = inserirAVL(A, 28);
  A = inserirAVL(A, 2);
  A = inserirAVL(A, 8);
  A = inserirAVL(A, 18);
  A = inserirAVL(A, 33);
  A = inserirAVL(A, 1);
  A = inserirAVL(A, 3);
  A = inserirAVL(A, 6);
  A = inserirAVL(A, 11);
  A = inserirAVL(A, 15);
  A = inserirAVL(A, 20);
  A = inserirAVL(A, 30);
  A = inserirAVL(A, 38);
  A = inserirAVL(A, 4);
  A = inserirAVL(A, 7);
  A = inserirAVL(A, 10);
  A = inserirAVL(A, 12);
  A = inserirAVL(A, 16);
  A = inserirAVL(A, 19);
  A = inserirAVL(A, 21);
  A = inserirAVL(A, 29);
  A = inserirAVL(A, 31);
  A = inserirAVL(A, 35);
  A = inserirAVL(A, 39);
  A = inserirAVL(A, 13);
  A = inserirAVL(A, 22);
  A = inserirAVL(A, 32);
  A = inserirAVL(A, 34);
  A = inserirAVL(A, 36);
  A = inserirAVL(A, 40);
  A = inserirAVL(A, 37);
  printf("Inicial:\n");
  porNiveis(A, altura(A), INT);
  imprimeEscada(A, 0, INT);
  A = removerAVL(A, 1);
  printf("###Removido o '1':\n");
  porNiveis(A, altura(A), INT);
  imprimeEscada(A, 0, INT);
  destroiArvore(A);
}

void exercicioAVL4 () {
  ArvorePalavra *A = NULL;
  A = inserirPalavra(A, "Pedro");
  printf("###Adicionado 'Pedro':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Joaquim");
  printf("###Adicionado 'Joaquim':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Sandra");
  printf("###Adicionado 'Sandra':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Daniele");
  printf("###Adicionado 'Daniele':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Jhony");
  printf("###Adicionado 'Jhony':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Bruna");
  printf("###Adicionado 'Bruna':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Roberto");
  printf("###Adicionado 'Roberto':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Ricardo");
  printf("###Adicionado 'Ricardo':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Rafael");
  printf("###Adicionado 'Rafael':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Hayama");
  printf("###Adicionado 'Hayama':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Lorena");
  printf("###Adicionado 'Lorena':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Mariana");
  printf("###Adicionado 'Mariana':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Marina");
  printf("###Adicionado 'Marina':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Roberta");
  printf("###Adicionado 'Roberta':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Chayene");
  printf("###Adicionado 'Chayene':\n");
  imprimeEscadaPalavras(A, 0);
  A = inserirPalavra(A, "Edmundo");
  printf("###Adicionado 'Edmundo':\n");
  imprimeEscadaPalavras(A, 0);
  destroiArvorePalavra(A);
}
