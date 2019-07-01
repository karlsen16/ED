#include "arvoreb.h"

ArvoreB* constroiArvoreBVazia () {
  return NULL;
}

int vazia (ArvoreB *A) {
  return(A == NULL);
}

int elegivel (ArvoreB *A) {
  if(!A->raiz)
    return(A->n > T-1);
  else
    return(A->n > 1);
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
  if(!vazia(A)) {
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
}

int buscar (ArvoreB *A, TIPO chave) {
  int i = 0;
  while((i < (A->n-1)) && (chave > A->chaves[i]))
    i++;
  if(chave == A->chaves[i])
    return TRUE;
  else if(A->folha)
    return FALSE;
  else if(chave < A->chaves[i])
    return buscar(A->filhos[i], chave);
  else
    return buscar(A->filhos[i+1], chave);
}

ArvoreB *inserir (ArvoreB *A, TIPO chave) {
  if(vazia(A)) {
    A = constroiNo();
    A->n++;
    A->raiz = A->folha = TRUE;
    A->chaves[0] = chave;
  }
  else {
    if(A->folha && !cheia(A))
      ordenaVetor(A, chave, NULL, NULL);
    else {
      ArvoreB *tmp;
      if(A->raiz && cheia(A) && !livre(A, chave)) {
        ArvoreB *R = constroiNo();
        R->raiz = TRUE;
        tmp = distribuir(R, A, chave);
        *A = *R;
        free(R);
      }
      else if(!A->folha){
        tmp = A->filhos[retornaIndice(A, chave)];
        if(!livre(A, chave))
          tmp = distribuir(A, tmp, chave);
      }
      tmp = inserir(tmp, chave);
    }
  }
  return A;
}

ArvoreB* distribuir (ArvoreB *P, ArvoreB *F, TIPO chave) {
  ArvoreB *E = constroiNo();
  ArvoreB *D = constroiNo();
  constroiVetores(F, E, D);
  TIPO promovido = F->chaves[T-1];
  ordenaVetor(P, promovido, E, D);
  P->folha = FALSE;
  if(chave < promovido)
    return E;
  else
    return D;
}

void constroiVetores (ArvoreB *O, ArvoreB *E, ArvoreB *D) {
  E->folha = D->folha = O->folha;
  E->raiz = D->raiz = FALSE;
  E->n = D->n = T-1;
  int i;
  for(i = 0; i < T-1; i++)
    copiar(O, i, E, i);
  i++;
  for(; i < 2*T-1; i++)
    copiar(O, i, D, i-T);
}

void copiar (ArvoreB *O, int indiceO, ArvoreB *D, int indiceD) {
  if(indiceO == 0 || indiceD == 0)
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
      if(A->chaves[i] >= chave)
        return i;
      i++;
    }
    return i;
  }
}

int indicePai (ArvoreB *A, int indice) {
  if(indice == A->n)
    indice--;
  return indice;
}

void ordenaVetor (ArvoreB *A, TIPO chave, ArvoreB *E, ArvoreB *D) {
  int i, indice = retornaIndice(A, chave);
  for(i = A->n; i > indice; i--) {
    A->chaves[i] = A->chaves[i-1];
    A->filhos[i+1] = A->filhos[i];
  }
  A->chaves[i] = chave;
  free(A->filhos[i]);
  A->filhos[i] = E;
  A->filhos[i+1] = D;
  A->n++;
}

int livre (ArvoreB *A, TIPO chave) {
  if(A->folha)
    if(cheia(A))
      return FALSE;
    else
      return TRUE;
  else {
    int indice = retornaIndice(A, chave);
    if(A->filhos[indice]->folha)
      return(!cheia(A->filhos[indice]));
    else {
      if(cheia(A->filhos[indice]))
        return livre(A->filhos[indice], chave);
      else
        return TRUE;
    }
  }
}

ArvoreB* remover (ArvoreB *A, TIPO chave) {
  if(!vazia(A)) {
    if(A->folha && pertence(A, chave)) {
      if(A->raiz && A->n == 1) {
        free(A);
        A = NULL;
      }
      else
        removeOrdenado(A, chave);
    }
    else {
      int indice = retornaIndice(A, chave), indiceP;
      //indiceP = indicePai(A, indice);
      ArvoreB *tmp;
      if(pertence(A, chave)) {
        tmp = herdeiroEsquerda(A, indice);
        if(elegivel(tmp)) {
          elevar(A, tmp, indice, tmp->n-1);
        }
        else {
          tmp = herdeiroDireita(A, indice);
          if(elegivel(tmp)) {
            elevar(A, tmp, indice, 0);
          }
          else {
            /*casos 2c FAZER!*/
            if(A->filhos[indice]->folha && elegivel(A)) {
              ArvoreB *mesclado = mesclar(A->filhos[indice], A->filhos[indice+1]);
              if(indice == 0)
                A->filhos[indice+1] = mesclado;
              else
                A->filhos[indice] = mesclado;
              removeOrdenado(A, chave);
            }
            else {
                /*casos 2c FAZER!*/
            }
          }
        }
      }
      else {
        if(A->filhos[indice]->folha &&
          pertence(A->filhos[indice], chave) &&
          !elegivel(A->filhos[indice])) {
          int vizinho = verificaVizinhos(A, indice);
          if(vizinho != -1) {
            TIPO promovido;
            A->filhos[indice] = remover(A->filhos[indice], chave);
            if(vizinho > indice) {
              promovido = A->filhos[vizinho]->chaves[0];
              A->filhos[indice] = inserir(A->filhos[indice], A->chaves[indice]);
              A->chaves[indice] = promovido;
            }
            else {
              promovido = A->filhos[vizinho]->chaves[A->filhos[vizinho]->n-1];
              A->filhos[indice] = inserir(A->filhos[indice], A->chaves[indice-1]);
              A->chaves[indice-1] = promovido;
            }
            removeOrdenado(A->filhos[vizinho], promovido);
          }
          /*caso 3b simples*/
          /*Nenhum dos vizinhos podia emprestar uma de suas chaves*/
          /*então os dois vão ser unidos e a chave poderá ser removida*/
          else if(elegivel(A)) {
            int i;
            removeOrdenado(A->filhos[indice], chave);
            if(indice == 0 || indice == 1) {
              A->filhos[1] = inserir(A->filhos[1], A->chaves[0]);
              for(i = 0; i < A->filhos[0]->n; i++)
                A->filhos[1] = inserir(A->filhos[1], A->filhos[0]->chaves[i]);
              removeOrdenado(A, A->chaves[0]);
            }
            else {
              A->filhos[indice-1] = inserir(A->filhos[indice-1], A->chaves[indice-1]);
              for(i = 0; i < A->filhos[indice]->n; i++)
                A->filhos[indice-1] = inserir(A->filhos[indice-1], A->filhos[indice]->chaves[i]);
              removeOrdenado(A, A->chaves[indice-1]);
            }
          }
          else {
            /*outros casos 3b*/
            /*Aqui entraria o caso 3b em que o nó pai*/
            /*da folha com a chave a ser removida*/
            /*possui T-1 chaves*/
          }
        }
        /*Continua o caminho pela árvore*/
        else {
          A->filhos[indice] = remover(A->filhos[indice], chave);
        }
      }
    }
  }
  return A;
}

int pertence (ArvoreB *A, TIPO chave) {
  int i = 0;
  while((i < (A->n-1)) && (chave > A->chaves[i]))
    i++;
  return(chave == A->chaves[i]);
}

void removeOrdenado (ArvoreB *A, TIPO chave) {
  int i, flag = 0;
  ArvoreB *hold = NULL;
  for(i = 0; i < A->n-1; i++) {
    if(A->chaves[i] == chave) {
      flag = 1;
      if(i == 0)
        hold = A->filhos[0];
      else
        hold = A->filhos[i+1];
    }
    if(flag == 1)
      copiar(A, i+1, A, i);
  }
  if(!vazia(hold) && flag == 1)
    A->filhos[i+1] = hold;
  A->n--;
}

ArvoreB* herdeiroEsquerda (ArvoreB *A, int indice) {
  ArvoreB *tmp = A->filhos[indice];
  while(!tmp->folha)
    tmp = tmp->filhos[tmp->n];
  return tmp;
}

ArvoreB* herdeiroDireita (ArvoreB *A, int indice) {
  indice = indicePai(A, indice);
  ArvoreB *tmp = A->filhos[indice+1];
  while(!tmp->folha)
    tmp = tmp->filhos[0];
  return tmp;
}

void elevar (ArvoreB *P, ArvoreB *F, int indice, int promovido) {
  indice = indicePai(P, indice);
  P->chaves[indice] = F->chaves[promovido];
  if(promovido > 0)
    P->filhos[indice] = remover(P->filhos[indice], F->chaves[promovido]);
  else
    P->filhos[indice+1] = remover(P->filhos[indice+1], F->chaves[promovido]);
}

ArvoreB* mesclar (ArvoreB *E, ArvoreB *D) {
  int i;
  ArvoreB *tmp = constroiNo(), *hold;
  tmp->folha = E->folha;
  tmp->raiz = FALSE;
  tmp->n = E->n+D->n;
  for(i = 0; i < E->n; i++)
    copiar(E, i, tmp, i);
  hold = tmp->filhos[i];
  for(; i < E->n+D->n; i++)
    copiar(D, i-E->n, tmp, i);
  if(!tmp->folha)
    tmp->filhos[E->n] = mesclar(hold, D->filhos[0]);
  free(D);
  free(E);
  return tmp;
}

int verificaVizinhos (ArvoreB *A, int indice) {
  if(indice != 0 && elegivel(A->filhos[indice-1]))
    return indice-1;
  else if(indice != A->n && elegivel(A->filhos[indice+1]))
    return indice+1;
  else
    return -1;
}
