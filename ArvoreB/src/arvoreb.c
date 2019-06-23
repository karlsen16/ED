#include "arvoreb.h"

/*Funções auxiliares, autoexplicativas*/
ArvoreB* constroiArvoreBVazia () {
  return NULL;
}

int vazia (ArvoreB *A) {
  return(A == NULL);
}

int elegivel (ArvoreB *A) {
  return(A->n > T-1);
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

/*Função de Inserção com estratégia cima para baixo*/
ArvoreB *inserir (ArvoreB *A, TIPO chave) {
  /*Constrói o primeiro nó de uma árvore B vazia*/
  if(vazia(A)) {
    A = constroiNo();
    A->n++;
    A->folha = TRUE;
    A->chaves[0] = chave;
    A->raiz = TRUE;
  }
  /*Insere a chave numa árvore B não vazia*/
  else {
    ArvoreB *tmp;
    /*Caso o nó recebido seja raiz*/
    if(A->raiz) {
      /*A raiz é o único nó da árvore B e ainda tem espaço*/
      /*A chave é apenas inserida na raiz*/
      if(A->folha && !cheia(A))
        ordenaVetor(A, chave, NULL, NULL);
      /*A função livre indica que a raiz vai sofrer modificações*/
      /*livre == TRUE indica que o nó está livre de modificações*/
      else if(!livre(A, chave)) {
        /*A raiz está cheia, é criada uma nova raiz acima dela*/
        if(cheia(A)) {
          ArvoreB *R = constroiNo();
          R->raiz = TRUE;
          /*É feita a distribuição adequada das chaves atuais*/
          tmp = distribuir(R, A, chave);
          /*Agora a árvore B já está pronta para apenas inserir a nova chave*/
          tmp = inserir(tmp, chave);
          *A = *R;
          free(R);
        }
        /*Ainda tem espaço na raiz, então ela*/
        /*apenas recebe a chave promovida dos filhos*/
        else {
          int indice = retornaIndice(A, chave);
          tmp = A->filhos[indice];
          tmp = distribuir(A, tmp, chave);
          tmp = inserir(tmp, chave);
        }
      }
      /*Raiz livre de modificações, apenas identifica o*/
      /* próximo nó e continua o processo de inserção*/
      else {
        int indice = retornaIndice(A, chave);
        tmp = A->filhos[indice];
        tmp = inserir(tmp, chave);
      }
    }
    /*Nó interno que não é raiz e nem folha*/
    else if(!A->folha) {
      int indice = retornaIndice(A, chave);
      tmp = A->filhos[indice];
      /*Verifica se ele está livre de modificações*/
      if(!livre(A, chave))
        /*Se necessário, redistribui as chaves atuais*/
        /*Já faz o trabalho de promover a mediana de filhos*/
        tmp = distribuir(A, tmp, chave);
      /*Finalmente insere a chave nova*/
      tmp = inserir(tmp, chave);
    }
    /*Nó folha que já possui espaço para inserir a chave nova*/
    /*Como a árvore B foi modificada de cima para baixo*/
    /*se chegar até aqui é porque o espaço para a chave*/
    /*já foi providenciado*/
    else
      ordenaVetor(A, chave, NULL, NULL);
  }
  return A;
}

/*Separa o nó filho (F) em dois: nó da esquerda (E)*/
/*com chaves menores que a mediana, e nó da direita (D)*/
/*com chaves maiores que a mediana. Também promove a mediana*/
/*para o nó pai (P) e retorna o nó adequado para continuar*/
/*a inserção da nova chave (chave)*/
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

/*Funcão auxiliar da distribuir, faz a cópia das*/
/*chaves adequadas do nó origem (O) para os nós*/
/*esquerda (E) e direita (D)*/
void constroiVetores (ArvoreB *O, ArvoreB *E, ArvoreB *D) {
  int i;
  E->folha = D->folha = O->folha;
  E->raiz = D->raiz = FALSE;
  E->n = D->n = T-1;
  for(i = 0; i < T-1; i++)
    copiar(O, i, E, i);
  i++;
  for(; i < 2*T-1; i++)
    copiar(O, i, D, i-T);
}

/*Função auxiliar da constroiVetores, faz a cópia*/
/*de uma única chave e seus filhos do nó origem (O)*/
/*para o nó destino (D)*/
void copiar (ArvoreB *O, int indiceO, ArvoreB *D, int indiceD) {
  if(indiceO == 0 || indiceD == 0)
    D->filhos[indiceD] = O->filhos[indiceO];
  D->filhos[indiceD+1] = O->filhos[indiceO+1];
  D->chaves[indiceD] = O->chaves[indiceO];
}

/*Retorna a posição em que a chave ficaria no vetor*/
/*também serve para determinar o nó filho onde a*/
/*chave deve ser inserida*/
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

/*Insere uma chave nova em um nó (A) não cheio*/
/*e faz a reordenação das chaves e filhos*/
void ordenaVetor (ArvoreB *A, TIPO chave, ArvoreB *E, ArvoreB *D) {
  int i, indice = retornaIndice(A, chave);
  for(i = A->n; i > indice; i--) {
    A->chaves[i] = A->chaves[i-1];
    A->filhos[i+1] = A->filhos[i];
  }
  A->chaves[i] = chave;
  A->filhos[i] = E;
  A->filhos[i+1] = D;
  A->n++;
}

/*Determina se o nó (A) vai precisar de modificações*/
/*livre == TRUE significa livre de modificações*/
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
    /*caso 1*/
    if(A->folha) {
      if(pertence(A, chave))
        removeOrdenado(A, chave);
    }
    else {
      int indice = retornaIndice(A, chave);
      ArvoreB *tmp;
      /*casos 2*/
      if(pertence(A, chave)) {
        /*caso 2a*/
        tmp = herdeiroEsquerda(A, indice);
        if(elegivel(tmp)) {
          elevar(A, tmp, indice, tmp->n-1);
        }
        else {
          /*caso 2b*/
          tmp = herdeiroDireita(A, indice);
          if(elegivel(tmp)) {
            elevar(A, tmp, indice, 0);
          }
          /*caso 2c*/
          else {
            /*Caso 2c simples em que a chave a ser removida*/
            /*está em nó pai de folha com pelo menos 2 chaves*/
            if(A->filhos[indice]->folha && A->n > 1) {
              ArvoreB *mesclado = mesclar(A->filhos[indice], A->filhos[indice+1]);
              if(indice == 0)
                A->filhos[indice+1] = mesclado;
              else
                A->filhos[indice] = mesclado;
              removeOrdenado(A, chave);
            }
            else {
              /*outros casos 2c*/
            }
          }
        }
      }
      /*Verifica o nó filho*/
      else {
        /*casos 3*/
        if(A->filhos[indice]->folha &&
          pertence(A->filhos[indice], chave) &&
          !elegivel(A->filhos[indice])) {
          /*caso 3a*/
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
          else if(elegivel(A)) {
            int i;
            removeOrdenado(A->filhos[indice], chave);
            if(indice == 0) {
              A->filhos[1] = inserir(A->filhos[1], A->chaves[0]);
              for(i = 0; i < A->filhos[indice]->n; i++)
                A->filhos[1] = inserir(A->filhos[1], A->filhos[0]->chaves[i]);
              removeOrdenado(A, A->chaves[0]);
            }
            else if(indice == 1) {
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
  if(chave == A->chaves[i])
    return TRUE;
  else
    return FALSE;
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
  if(!vazia(hold))
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
  ArvoreB *tmp = A->filhos[indice+1];
  while(!tmp->folha)
    tmp = tmp->filhos[0];
  return tmp;
}

void elevar (ArvoreB *P, ArvoreB *F, int indice, int promovido) {
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
  if(!tmp->folha) {
    tmp->filhos[E->n] = mesclar(hold, D->filhos[0]);
  }
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
