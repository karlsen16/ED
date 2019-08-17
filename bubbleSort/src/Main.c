#include "stdafx.h"
#include "BubbleSort.h"

int main () {
  // int V[10] = {7,2,9,1,3,5,4,2,6,8};
  // imprime(10, V, "%+03d");
  // bubbleSort(10, V, sizeof(int), comparaI);
  // imprime(10, V, "%+03d");

  Aluno V[3] = {{"C", "8192321", 'G', "ab@jesus"},
                {"B", "1232321", 'B', "lu@jesus"},
                {"A", "9999999", 'Z', "zz@jesus"}};
  imprime(3, V, "%s\n");
  bubbleSort(3, V, sizeof(Aluno), comparaS);
  imprime(3, V, "%s\n");

  return 0;
}
