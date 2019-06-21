#include "arvoreb.h"
/*
#define TIPO char
#define T 2
#define NOT_FOUND -1
#define TRUE 1
#define FALSE 0
*/
ArvoreB* constroiArvoreBVazia () {
  return NULL;
}

int vazia (ArvoreB *A) {
  return(A == NULL);
}

int cheia (ArvoreB *A) {
  return(A->n == 2*T+1);
}

void destroiArvoreB (ArvoreB *A) {
  if(!vazia(A)) {
    int i;
    for(i = 0; i < (2*T+2); i++)
      destroiArvoreB(A->filhos[i]);
    free(A);
  }
}

ArvoreB* constroiFolha () {
  ArvoreB *A = (ArvoreB*)malloc(sizeof(ArvoreB));
  A->n = 0;
  A->folha = TRUE;
  return A;
}

void imprimir (ArvoreB *A, int nivel) {
  int i;
  for(i = 0; i < nivel; i++) { printf("  "); }
  printf("|");
  for(i = 0; i < A->n; i++)
    printf("%c|", A->chaves[i]);
  printf("\n");
  for(i = 0; i <= A->n; i++)
    if(A->folha == FALSE)
      imprimir(A->filhos[i], nivel+1);
}

int buscar (ArvoreB *A, TIPO chave) {
  int i = 0;
  while((i < (A->n-1)) && (chave > A->chave[i]))
    i++;
  if(chave == A->chave[i])
    return FOUND;
  else if (A->folha)
    return NOTFOUND;
  else
    return buscar(A->filhos[i], chave);
}

ArvoreB *inserir (ArvoreB *A, TIPO chave) {
   /*Completar!!!!!!!!!!!!!!*/
}

void jogaPraDireita (ArvoreB *A, TIPO chave, int indice) {
  int i;
  for(i = A->n; i > indice; i--) {
    A->chaves[i] = A->chaves[i-1];
    if(!A->folha)
      A->filhos[i+1] = A->filhos[i];
  }
  A->chaves[i] = chave;
  if(!A->folha){
    A->filhos[i+1] = constroiFolha();
    moveNoMaiores(A->filhos[i], A->filhos[i+1], chave);
  }
}

void moveNoMaiores (ArvoreB *O, ArvoreB* D, TIPO chave) {
  int i, cont = 0;
  for(i = 0; i < O->n; i++) {
    if(O->chaves[i] > chave)
      cont++;
      D = inserir(D, O->chaves[i]);
      if(!O->folha) {
        D->filhos[cont] = O->filhos[i+1]
        D->filhos[cont-1] = constroiFolha();
        moveNoMaiores(O->filhos[i], D->filhos[cont-1], chave);
      }
      O = remover(O, O->chaves[i]);
  }
}

void divideDistribui (ArvoreB *P, ArvoreB *F, TIPO chave) {
  int i, mediana = F->n/2;
  ArvoreB *novo = constroiFolha();
  if()
  for(i = )


}

ArvoreB* remover (ArvoreB *A, TIPO chave) {
   /*Dois casos!!!!!!!!!!!!!!*/
}


/*
Local* iniciaBusca (ArvoreB *A, TIPO chave) {
  Local *L = (Local*)malloc(sizeof(Local));
  L->nivel = L->no = L->found = 0;
  L->chave = chave;
  L = buscar(A, L);
  return L;
}

void destroiLocal (Local *L) {
  if(L != NULL)
    free(L);
}

Local* buscar (ArvoreB *A, Local *L) {
  int i = 0;
  while((i < (A->n-1)) && (L->chave > A->chaves[i]))
    i++;
  if(L->chave == A->chaves[i]) {
    L->indice = i;
    L->found = TRUE;
  }
  else if(L->chave < A->chaves[i]) {
    L->nivel++;
    L->no = i;
    L = buscar(A[i], L);
  }
  else if(A->folha == FALSE)
      return buscar(A->filhos[i], chave);
  return L;
}
*/
