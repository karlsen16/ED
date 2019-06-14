#ifndef STACK__H
#define STACK__H

#include <stdio.h>

typedef struct stack {
  int info;
  struct stack *next;
}Stack;

Stack* createStack ();
void freeStack (Stack *S);
Stack* push (Stack *S, int elem);
Stack* pop (Stack *S);
int top (Stack *S);
int Empty (Stack *S);


#endif /* STACK_H */
