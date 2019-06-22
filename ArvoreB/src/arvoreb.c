#include "arvoreb.h"

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
    for(i = 0; i < (2*T); i++)
      destroiArvoreB(A->filhos[i]);
    free(A);
  }
}

ArvoreB* constroiNo () {
  ArvoreB *A = (ArvoreB*)malloc(sizeof(ArvoreB));
  A->n = 0;
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
  while((i < (A->n-1)) && (chave > A->chaves[i]))
    i++;
  if(chave == A->chaves[i])
    return FOUND;
  else if(A->folha)
    return NOT_FOUND;
  else if(chave < A->chaves[i])
    return buscar(A->filhos[i], chave);
  else
    return buscar(A->filhos[i+1], chave);
}

ArvoreB *inserir (ArvoreB *A, TIPO chave) {
  if(vazia(A)) {
    A = constroiNo();
    A->n++;
    A->folha = TRUE;
    A->chaves[0] = chave;
    A->raiz = TRUE;
  }
  else {
    ArvoreB *tmp;
    if(A->folha && A->raiz) {
      if(!cheia(A))
        jogaPraDireita(A, chave, retornaIndice(A, chave), NULL, NULL);
      else {
        ArvoreB *R = constroiNo();
        R->raiz = TRUE;
        tmp = distribuir(R, A, chave);
        tmp = inserir(tmp, chave);
        *A = *R;
        free(R);
      }
    }
    else if(!A->folha) {
      int indice = retornaIndice(A, chave);
      tmp = A->filhos[indice];
      if(cheia(A) && cheia(tmp))
        tmp = distribuir(A, tmp, chave);
      tmp = inserir(tmp, chave);
    }
    else {
      if(cheia(A)) {

      }
      else
        jogaPraDireita(A, chave, retornaIndice(A, chave), NULL, NULL);
    }
  }
  return A;
}

ArvoreB* distribuir (ArvoreB *P, ArvoreB *F, TIPO chave) {
  TIPO promovido = F->chaves[T-1];
  ArvoreB *E = constroiNo();
  ArvoreB *D = constroiNo();
  constroiVetores(F, E, D);
  jogaPraDireita(P, promovido, retornaIndice(P, promovido), E, D);
  P->folha = FALSE;
  if(chave < promovido)
    return E;
  else
    return D;
}

void constroiVetores (ArvoreB *O, ArvoreB *E, ArvoreB *D) {
  int i;
  for(i = 0; i < T-1; i++)
    copiar(O, i, E, i);
  i++;
  for(; i < 2*T-1; i++)
    copiar(O, i, D, i-T);
  E->folha = D->folha = O->folha;
  E->raiz = D->raiz = FALSE;
  E->n = D->n = T-1;
}

void copiar (ArvoreB *O, int indiceO, ArvoreB *D, int indiceD) {
  D->filhos[indiceD] = O->filhos[indiceO];
  D->filhos[indiceD+1] = O->filhos[indiceO+1];
  D->chaves[indiceD] = O->chaves[indiceO];
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

void ordenaVetor (ArvoreB *A) {
  int i, cont;
  TIPO aux;
  for(cont = A->n-1; cont > 0; cont--)
    for(i = cont; i > 0; i--) {
      if(A->chaves[i] < A->chaves[i-1]) {
        aux = A->chaves[i];
        A->chaves[i] = A->chaves[i-1];
        A->chaves[i+1] = aux;
      }
    }
}

void jogaPraDireita (ArvoreB *A, TIPO chave, int indice, ArvoreB *E, ArvoreB *D) {
  int i;
  for(i = A->n; i > indice; i--) {
    A->chaves[i] = A->chaves[i-1];
    A->filhos[i+1] = A->filhos[i];
  }
  A->chaves[i] = chave;
  A->filhos[i] = E;
  A->filhos[i+1] = D;
  A->n++;
}

int livre (ArvoreB *A, TIPO chave) {
  int indice = retorna(A, chave), indicador = 0;
  if(A->filhos)


}
/*
ArvoreB* remover (ArvoreB *A, TIPO chave) {

}*/
