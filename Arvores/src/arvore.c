#include "arvore.h"
#include <string.h>
#define CHAR 0
#define INT 1
#define STRING 2
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

int altura (Arvore *A) {
  if(vazia(A))
    return -1;
  else if(!folha(A))
    return 1+(MAX(altura(A->esq), altura(A->dir)));
  else
    return 0;
}

int balanceamento (Arvore *A) {
  return (altura(A->dir)-altura(A->esq));
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

Arvore* rotacaoSimplesEsq (Arvore *A) {
  Arvore *T = A->dir;
  A->dir = T->esq;
  T->esq = A;
  return T;
}

Arvore* rotacaoSimplesDir (Arvore *A) {
  Arvore *T = A->esq;
  A->esq = T->dir;
  T->dir = A;
  return T;
}

Arvore* rotacaoDuplaEsq (Arvore *A) {
  A->dir = rotacaoSimplesDir(A->dir);
  return rotacaoSimplesEsq(A);
}

Arvore* rotacaoDuplaDir (Arvore *A) {
  A->esq = rotacaoSimplesEsq(A->esq);
  return rotacaoSimplesDir(A);
}

Arvore* atualizarBalanceamentoEsq (Arvore *A) {
  if(balanceamento(A) == -2) {
    if(balanceamento(A->esq) <= 0)
      A = rotacaoSimplesDir(A);
    else
      A = rotacaoDuplaDir(A);
  }
  return A;
}

Arvore* atualizarBalanceamentoDir (Arvore *A) {
  if(balanceamento(A) == 2) {
    if(balanceamento(A->dir) >= 0)
      A = rotacaoSimplesEsq(A);
    else
      A = rotacaoDuplaEsq(A);
  }
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

Arvore* inserirAVL (Arvore *A, int valor) {
  if(vazia(A))
    A = constroiFolha(valor);
  else if(valor < A->info) {
    A->esq = inserirAVL(A->esq, valor);
    A = atualizarBalanceamentoEsq(A);
  }
  else {
    A->dir = inserirAVL(A->dir, valor);
    A = atualizarBalanceamentoDir(A);
  }
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
      else if(vazia(A->esq)) {
        Arvore *tmp = A;
        A = A->dir;
        free(tmp);
      }
      else if(vazia(A->dir)) {
        Arvore *tmp = A;
        A = A->esq;
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

Arvore* removerAVL (Arvore *A, int valor) {
  if (vazia(A))
    return NULL;
  else {
    if (valor < A->info) {
      A->esq = removerAVL (A->esq, valor);
      A = atualizarBalanceamentoDir (A);
    }
    else if (valor > A->info) {
      A->dir = removerAVL (A->dir, valor);
      A = atualizarBalanceamentoEsq (A);
    }
    else {
      if (folha(A)) {
        free (A);
        A = NULL;
      }
      else if (vazia(A->esq)) {
        Arvore *tmp = A;
        A = A->dir;
        free (tmp);
      }
      else if (vazia(A->dir)) {
        Arvore *tmp = A;
        A = A->esq;
        free (tmp);
      }
      else {
        Arvore *tmp = A->esq;
        while (!vazia(tmp->dir))
          tmp = tmp->dir;
        A->info = tmp->info;
        tmp->info = valor;
        A->esq = removerAVL (A->esq, valor);
        A = atualizarBalanceamentoDir (A);
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

void imprime (Arvore *A, int tipo) {
  if(tipo == CHAR)
    printf("%2c", A->info);
  else
    printf("%2d", A->info);
}

void imprimeChar (int n, char c) {
  int i;
  for(i = 0; i < n; i++)
    printf("%c", c);
}

void imprimeFilhos (Arvore *A, int espacos, int tipo) {
  if(!vazia(A->esq))
    imprime(A->esq, tipo);
  else
    espacos += 2;
  imprimeChar(espacos, ' ');
  if(!vazia(A->dir))
    imprime(A->dir, tipo);
  else
    imprimeChar(2, ' ');
}

void imprimePreOrdem (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprime(A, tipo);
    imprimePreOrdem(A->esq, tipo);
    imprimePreOrdem(A->dir, tipo);
  }
}

void imprimeInOrdem (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprimeInOrdem(A->esq, tipo);
    imprime(A, tipo);
    imprimeInOrdem(A->dir, tipo);
  }
}

void imprimePosOrdem (Arvore *A, int tipo) {
  if(!vazia(A)) {
    imprimePosOrdem(A->esq, tipo);
    imprimePosOrdem(A->dir, tipo);
    imprime(A, tipo);
  }
}

void imprimeMarcadores (Arvore *A, int tipo) {
  printf("<");
  if(!vazia(A)) {
    imprime(A, tipo);
    imprimeMarcadores(A->esq, tipo);
    imprimeMarcadores(A->dir, tipo);
  }
  printf(">");
}

void imprimeEscada (Arvore *A, int nivel, int tipo) {
  if (!vazia(A)) {
    int i;
    for (i = 0; i < nivel; i++)
      imprimeChar(6, ' ');
    printf("Chave:");
    imprime(A, tipo);
    printf(" (altura: %d, fb: %+d) no nível: %d\n", altura(A), balanceamento(A), nivel);
    imprimeEscada(A->esq, nivel+1, tipo);
    imprimeEscada(A->dir, nivel+1, tipo);
  }
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

void porNiveis (Arvore *A, int altura, int tipo) {
  if(altura == 0) {
    imprime(A, tipo);
    printf("\n\n");
  }
  else {
    int i, tamanhoVetor, espacador;
    tamanhoVetor = retornaTamanhoVetor(altura);
    espacador = tamanhoVetor*2;
    Arvore **V = (Arvore**)malloc(tamanhoVetor*sizeof(Arvore*));
    V[0] = A;
    imprimeChar(espacador, ' ');
    imprime(V[0], tipo);
    printf("\n");
    for(i = 1; i < tamanhoVetor; i++)
      V[i] = NULL;
    imprimePorNiveis(V, tamanhoVetor, 2, espacador, tipo);
  }
}

void imprimePorNiveis (Arvore **V, int tamanhoVetor, int iterador, int espacador, int tipo) {
  int i, valor = tamanhoVetor/iterador, espacoAuxiliar;
  espacador /= 2;
  espacoAuxiliar = 2*espacador-2;
  for(i = 0; i < tamanhoVetor; i += 2*valor) {
    if(i == 0)
      imprimeChar(espacador, ' ');
    if(!vazia(V[i])) {
      imprimeFilhos(V[i], espacoAuxiliar, tipo);
      imprimeChar(espacoAuxiliar, ' ');
      V[i+valor] = V[i]->dir;
      V[i] = V[i]->esq;
    }
    else
      imprimeChar(2*espacoAuxiliar+4, ' ');
  }
  printf("\n");
  iterador *= 2;
  if(iterador <= tamanhoVetor)
    imprimePorNiveis(V, tamanhoVetor, iterador, espacador, tipo);
  else {
    printf("\n\n");
  }
}

ArvorePalavra* inserirPalavra (ArvorePalavra *A, char *S) {
  if(A == NULL) {
    A = (ArvorePalavra*)malloc(sizeof(ArvorePalavra));
    char *tmp = (char*)malloc(sizeof(char)*strlen(S)+1);
    strcpy(tmp, S);
    A->S = tmp;
    A->esq = A->dir = NULL;
  }
  else if(strcmp(S, A->S) < 0) {
    A->esq = inserirPalavra(A->esq, S);
    A = atualizarBalanceamentoEsqP(A);
  }
  else {
    A->dir = inserirPalavra(A->dir, S);
    A = atualizarBalanceamentoDirP(A);
  }
  return A;
}

int alturaPalavra (ArvorePalavra *A) {
  if(A == NULL)
    return -1;
  else if((A->esq != NULL) || (A->dir != NULL))
    return 1+(MAX(alturaPalavra(A->esq), alturaPalavra(A->dir)));
  else
    return 0;
}

int balanceamentoPalavra (ArvorePalavra *A) {
  return (alturaPalavra(A->dir)-alturaPalavra(A->esq));
}

void imprimeEscadaPalavras (ArvorePalavra *A, int nivel) {
  if (A != NULL) {
    int i;
    for (i = 0; i < nivel; i++)
      imprimeChar(6, ' ');
    printf("Chave: %s (altura: %d, fb: %+d) no nível: %d\n", A->S, alturaPalavra(A), balanceamentoPalavra(A), nivel);
    imprimeEscadaPalavras(A->esq, nivel+1);
    imprimeEscadaPalavras(A->dir, nivel+1);
  }
}

void destroiArvorePalavra (ArvorePalavra *A) {
  if(A != NULL) {
    destroiArvorePalavra(A->esq);
    destroiArvorePalavra(A->dir);
    free(A);
  }
}

ArvorePalavra* rotacaoSimplesEsqP (ArvorePalavra *A) {
  ArvorePalavra *T = A->dir;
  A->dir = T->esq;
  T->esq = A;
  return T;
}

ArvorePalavra* rotacaoSimplesDirP (ArvorePalavra *A) {
  ArvorePalavra *T = A->esq;
  A->esq = T->dir;
  T->dir = A;
  return T;
}

ArvorePalavra* rotacaoDuplaEsqP (ArvorePalavra *A) {
  A->dir = rotacaoSimplesDirP(A->dir);
  return rotacaoSimplesEsqP(A);
}

ArvorePalavra* rotacaoDuplaDirP (ArvorePalavra *A) {
  A->esq = rotacaoSimplesEsqP(A->esq);
  return rotacaoSimplesDirP(A);
}

ArvorePalavra* atualizarBalanceamentoEsqP (ArvorePalavra *A) {
  if(balanceamentoPalavra(A) == -2) {
    if(balanceamentoPalavra(A->esq) <= 0)
      A = rotacaoSimplesDirP(A);
    else
      A = rotacaoDuplaDirP(A);
  }
  return A;
}

ArvorePalavra* atualizarBalanceamentoDirP (ArvorePalavra *A) {
  if(balanceamentoPalavra(A) == 2) {
    if(balanceamentoPalavra(A->dir) >= 0)
      A = rotacaoSimplesEsqP(A);
    else
      A = rotacaoDuplaEsqP(A);
  }
  return A;
}
