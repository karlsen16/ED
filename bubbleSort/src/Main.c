#include "stdafx.h"
#include "BubbleSort.h"

int main () {
  int V[10] = {7,2,9,1,3,5,4,2,6,8};
  bubbleSort(V, 10);
  imprime(V, 10);
  return 0;
}
