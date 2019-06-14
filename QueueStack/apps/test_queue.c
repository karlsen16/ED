#include "queue.h"

int main () {
   int i, passoMorte, n;
   printf("Jogo de Josephus, digite o passo da morte e número de competidores: ");
   scanf("%d %d", &passoMorte, &n);
   Queue *Q = createQueue ();
   for (i = 1; i <= n; i++)
      Q = enqueue(Q, i);

   i = 1;
   while (!Empty(Q)) {
       int front = Front(Q);
       Q = dequeue(Q);
       if (Empty(Q)){
          printf(", sobrevivente: %d\n", front);
       }
       else if ((i % passoMorte) == 0) {
          printf("%d ", front);
       }
       else {
          Q = enqueue (Q, front);
       }
       i++;
   }
   freeQueue (Q);
   return 0;
}
