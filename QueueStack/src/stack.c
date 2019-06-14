#include <stdlib.h>
#include "stack.h"

Stack* createStack ()
{
  return NULL;
}

void freeStack (Stack *S) {
  Stack *walk;
  while(S != NULL) {
    walk = S->next;
    free(S);
    S = walk;
  }
}

Stack* push (Stack *S, int elem) {
  Stack *new = (Stack*)malloc(sizeof(Stack));
  new->info = elem;
  new->next = S;
  return new;
}

Stack* pop (Stack *S) {
  Stack *aux = S->next;
  free(S);
  return aux;
}

int top (Stack *S) {
  return S->info;
}

int Empty (Stack *S) {
  if(S == NULL)
      return 1;
  else
      return 0;
}
