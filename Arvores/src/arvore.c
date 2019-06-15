#include "arvore.h"
#define CHAR 0
#define INT 1
#define MAX(a,b) (a>b) ? (a) : (b)
#define MIN(a,b) (a<b) ? (a) : (b)

Arvore* criaArvoreVazia () {
  return NULL;
}

void destroiArvore (Arvore *A) {
  if(!vazia(A)) {
    destroiArvore(A->esq);
    destroiArvore(A->dir);
    free(A);
  }
}

Arvore* constroiArvore (char elem, Arvore *esq, Arvore *dir) {
  Arvore *A;
  A = (Arvore*)malloc(sizeof(Arvore));
  A->info = elem;
  A->dir = dir;
  A->esq = esq;
  return A;
}

Arvore* constroiFolha (char elem) {
  Arvore *A;
  A = (Arvore*)malloc(sizeof(Arvore));
  A->info = elem;
  A->dir = NULL;
  A->esq = NULL;
  return A;
}

Arvore* inserir (Arvore *A, int valor) {
  if(vazia(A))
    A = constroiFolha(valor);
  else if(valor < A->info)
    A->esq = inserir(A->esq, valor);
  else
    A->dir = inserir(A->dir, valor);
  return A;
}

Arvore* remover (Arvore *A, int valor) {
  if(vazia(A))
    return NULL;
  else {
    if(A->info > valor)
      A->esq = remover(A->esq, valor);
    else if(A->info < valor)
      A->dir = remover(A->dir, valor);
    else {
      if(folha(A)) {
        free(A);
        A = NULL;
      }
      else if(vazia(A->dir)) {
        Arvore *tmp = A;
        A = A->esq;
        free(tmp);
      }
      else if(vazia(A->esq)) {
        Arvore *tmp = A;
        A = A->dir;
        free(tmp);
      }
      else {
        Arvore *tmp = A->esq;
        while(!vazia(tmp->dir))
          tmp = tmp->dir;
        A->info = tmp->info;
        tmp->info = valor;
        A->esq = remover(A->esq, valor);
      }
    }
  }
  return A;
}

int vazia (Arvore *A) {
  return(A == NULL);
}

int folha (Arvore *A) {
  return((vazia(A->esq)) && (vazia(A->dir)));
}

int min (Arvore *A) {
  if(!vazia(A))
    if(!vazia(A->esq))
      return min(A->esq);
    else
      return A->info;
  else
    return -1;
}

int max (Arvore *A) {
  if(!vazia(A))
    if(!vazia(A->dir))
      return max(A->dir);
    else
      return A->info;
  else
    return -1;
}

int menorRamo (Arvore *A) {
  if(folha(A))
    return A->info;
  else if(vazia(A->esq))
    return A->info+menorRamo(A->dir);
  else if(vazia(A->dir))
    return A->info+menorRamo(A->esq);
  else
    return A->info+(MIN(menorRamo(A->esq), menorRamo(A->dir)));
}

int maiorRamo (Arvore *A) {
  if(!vazia(A))
    return A->info+(MAX(maiorRamo(A->esq), maiorRamo(A->dir)));
  return 0;
}

int ancestral (Arvore *A, int esq, int dir) {
  int aux = MIN(esq, dir);
  dir = MAX(esq, dir);
  esq = aux;
  if((A->info == esq || A->info == dir) || (A->info > esq && A->info < dir))
    return A->info;
  else if(A->info > esq && A->info > dir)
    return ancestral(A->esq, esq, dir);
  else
    return ancestral(A->dir, esq, dir);
}

void imprimePreOrdem (Arvore *A, int tipo) {
  if(!vazia(A)) {
    if(tipo == CHAR)
      printf("%c  ", A->info);
    else
      printf("%d  ", A->info);
    imprimePreOrdem(A->esq, tipo);
    imprimePreOrdem(A->dir, tipo);
  }
}

void imprimeInOrdem (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprimeInOrdem(A->esq, tipo);
    if(tipo == CHAR)
      printf("%c  ", A->info);
    else
      printf("%d  ", A->info);
    imprimeInOrdem(A->dir, tipo);
  }
}

void imprimePosOrdem (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprimePosOrdem(A->esq, tipo);
    imprimePosOrdem(A->dir, tipo);
    if(tipo == CHAR)
      printf("%c  ", A->info);
    else
      printf("%d  ", A->info);
  }
}

void imprimePreOrdemR (Arvore *A, int tipo) {
  if(!vazia(A)) {
    if(tipo == CHAR)
      printf("%c  ", A->info);
    else
      printf("%d  ", A->info);
    imprimePreOrdemR(A->dir, tipo);
    imprimePreOrdemR(A->esq, tipo);
  }
}

void imprimeInOrdemR (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprimeInOrdemR(A->dir, tipo);
    if(tipo == CHAR)
      printf("%c  ", A->info);
    else
      printf("%d  ", A->info);
    imprimeInOrdemR(A->esq, tipo);
  }
}

void imprimePosOrdemR (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprimePosOrdemR(A->dir, tipo);
    imprimePosOrdemR(A->esq, tipo);
    if(tipo == CHAR)
      printf("%c  ", A->info);
    else
      printf("%d  ", A->info);
  }
}

void imprimeMarcadores (Arvore *A, int tipo) {
  printf("<");
  if(!vazia(A)) {
    if(tipo == CHAR)
      printf("%c", A->info);
    else
      printf("%d", A->info);
    imprimeMarcadores(A->esq, tipo);
    imprimeMarcadores(A->dir, tipo);
  }
  printf(">");
}

int pertenceArvore (Arvore *A, char c) {
  if(!vazia(A)) {
    if(A->info == c)
      return 1;
    return ((pertenceArvore(A->esq, c)+pertenceArvore(A->dir, c)) != 0 ? 1 : 0);
  }
  return 0;
}

int buscaBinaria (Arvore *A, int valor) {
  if(vazia(A))
    return 0;
  else if(valor < A->info)
    return buscaBinaria(A->esq, valor);
  else if(valor > A->info)
    return buscaBinaria(A->dir, valor);
  else
    return 1;
}

int contaNos (Arvore *A) {
  if(!vazia(A))
    return 1+contaNos(A->esq)+contaNos(A->dir);
  return 0;
}

int contaNosFolha (Arvore *A) {
  if(!vazia(A)) {
    if(folha(A))
      return 1;
    else
      return contaNosFolha(A->esq)+contaNosFolha(A->dir);
  }
  return 0;
}

int altura (Arvore *A) {
  if(!vazia(A))
    if(!folha(A))
      return 1+(MAX(altura(A->esq), altura(A->dir)));
  return 0;
}

void espelhoSimilar (Arvore *A) {
  if(!vazia(A) && !folha(A)) {
    if(vazia(A->esq)) {
      A->esq = A->dir;
      A->dir = NULL;
      espelhoSimilar(A->esq);
    }
    else if(vazia(A->dir)) {
      A->dir = A->esq;
      A->esq = NULL;
      espelhoSimilar(A->dir);
    }
    else {
      Arvore *auxiliar = A->esq;
      A->esq = A->dir;
      A->dir = auxiliar;
      espelhoSimilar(A->esq);
      espelhoSimilar(A->dir);
    }
  }
}

int retornaTamanhoVetor (int altura) {
  int i, tamanhoVetor = 1;
  for(i = 0; i < altura; i++)
    tamanhoVetor *= 2;
  return tamanhoVetor;
}

void porNiveis (Arvore *A, int altura) {
  int i, tamanhoVetor;
  tamanhoVetor = retornaTamanhoVetor(altura);
  Arvore **V = (Arvore**)malloc(tamanhoVetor*sizeof(Arvore*));
  V[0] = A;
  for(i = 1; i < tamanhoVetor; i++)
    V[i] = NULL;
  imprimePorNiveis(V, tamanhoVetor, 2);
}

void imprimeEspacos (int n) {
  int i;
  for(i = 0; i < n; i++)
    printf(" ");
}

void imprimePorNiveis (Arvore **V, int tamanhoVetor, int iterador) {
  int i, valor = tamanhoVetor/iterador;
  for(i = 0; i < tamanhoVetor; i += 2*valor)
    if(!vazia(V[i])) {
      if(i == 0)
        imprimeEspacos(tamanhoVetor*valor);
      else
        imprimeEspacos(tamanhoVetor*valor+i);
      printf("%2d", V[i]->info);
      V[i+valor] = V[i]->dir;
      V[i] = V[i]->esq;
    }
  printf("\n");
  iterador *= 2;
  if(iterador <= tamanhoVetor)
    imprimePorNiveis(V, tamanhoVetor, iterador);
  else {
    for(i = 0; i < tamanhoVetor; i ++)
      if(!vazia(V[i])) {
        imprimeEspacos(2);
        printf("%2d", V[i]->info);
      }
      else
        imprimeEspacos(4);
  }
  printf("\n\n");
}
