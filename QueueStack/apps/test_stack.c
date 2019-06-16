#include "stack.h"

int main () {

  int i = 0;
  char *expr = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  Stack *S = createStack();
  while (expr[i] != '\0') {
    if ( (expr[i] == '+') || (expr[i] == '*') )
      S = push(S, expr[i]);
    else if (expr[i] == ')') {
      printf("%c ", top(S));
      S = pop(S);
    }
    else if ( (expr[i] >= '0') && (expr[i] <= '9') )
      printf("%c ", expr[i]);
    i++;
  }
  printf("\n");
  freeStack (S);
  return 0;
}
