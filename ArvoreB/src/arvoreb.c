#include "arvoreb.h"

#define TIPO char
#define T 2
#define NOT_FOUND -1
#define TRUE 1
#define FALSE 0

ArvoreB* constroiArvoreBVazia () {
  return NULL;
}

int vazia (ArvoreB *A) {
  return(A == NULL);
}

int cheia (ArvoreB *A) {
  return(A->n == 2*T-1);
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
  else if(A->folha)
    return NOTFOUND;
  else if(chave < A->chave[i])
    return buscar(A->filhos[i], chave);
  else
    return buscar(A->filhos[i+1], chave);
}

ArvoreB *inserir (ArvoreB *A, TIPO chave) {
  if(vazia(A)) {
    A = constroiFolha();
    A->chaves[0] = chave;
  }
  else if(!A->folha) {
    A->filhos[retornaIndice(A, chave)] = inserir(A->filhos[retornaIndice(A, chave)], chave);
  }
  else if(!cheia(A)) {
    jogaPraDireita(A, chave, retornaIndice(A, chave));
  }
  else {
      /*ÚLTIMO CASO FALTANDO*/
  }
  A->n++;
  return A;
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
    if(O->chaves[i] > chave) {
      cont++;
      D = inserir(D, O->chaves[i]);
      if(!O->folha) {
        D->filhos[cont] = O->filhos[i+1]
        if(cont == 1) {
          D->filhos[cont-1] = constroiFolha();
          moveNoMaiores(O->filhos[i], D->filhos[cont-1], chave);
        }
      }
      O = remover(O, O->chaves[i]);
    }
  }
}

int retornaIndice (ArvoreB *A, TIPO chave) {
  if(vazia(A))
    return 0;
  else {
    int i = 0;
    while(i < A->n) {
      if(A->chaves[i] > chave)
        return i;
      i++;
    }
    return i;
  }
}


/*
void divideDistribui (ArvoreB *P, ArvoreB *F, TIPO chave) {
  int i, mediana = F->n/2;
  ArvoreB *novo = constroiFolha();
  if()
  for(i = )


}*/

ArvoreB* remover (ArvoreB *A, TIPO chave) {
   /*Dois casos!!!!!!!!!!!!!!*/
}
