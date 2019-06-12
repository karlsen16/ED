#include "arvoreb.h"

#define TIPO char
#define T 2           /*Número que define mínimo e máximo de chaves!*/
#define NOT_FOUND -1  /*Valor retornado quando o nó não existe!*/
#define TRUE 1        /*Booleano para verdadeiro!*/
#define FALSE 0       /*Booleano para falso!*/

/*Função para criar e inicializar uma árvore B:*/
Arvore* criar () {
   Arvore *a = (Arvore *)malloc(sizeof(Arvore));
   a->n = 0;
   a->folha = TRUE;
   return a;
}

/*Função para buscar uma chave em uma árvore B:*/
void imprimir (Arvore *a, int nivel) {

   int i;

   /*Imprime recuo para definir o nível do nó: */
   for (i = 0; i < nivel; i++) { printf("  "); }

   /*Imprime as chaves armazenadas no nó: */
   printf("|");
   for (i = 0; i < a->n; i++) {
      printf("%c|", a->chaves[i]);
      //printf("%02d|", a->chaves[i]);
   }
   printf("\n");

   /*Recursivamente imprime as chaves dos filhos: */
   for (i = 0; i <= a->n; i++) {
      if (a->folha == FALSE) {
         imprimir(a->filhos[i], nivel + 1);
      }
   }
}

/*Função para buscar uma chave em uma árvore B:*/
int buscar (Arvore *a, TIPO chave) {

   int i = 0;

   /*Procurando a chave no vetor de chaves: */
   while ((i < a->n) && (chave > a->chaves[i])) {
     i = i + 1;
   }

   if (chave == a->chaves[i]) {
      /*Achou a chave!*/
      return i;
   }
   else if (a->folha) {
      /*Não achou a chave!*/
      return NOT_FOUND;
   }
   else {
      /*Buscando a chave no filho: */
      if (a->folha == FALSE) {
         return buscar (a->filhos[i], chave);
      }
   }
}

Arvore* remover (Arvore *raiz, TIPO chave) {
   /*Dois casos!!!!!!!!!!!!!!*/
}

Arvore *inserir (Arvore *raiz, TIPO chave) {
   /*Completar!!!!!!!!!!!!!!*/
}
