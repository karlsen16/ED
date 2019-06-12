#include "grafos.h"

int main () {

   int Va = 10; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);

   insere_verticeA(&Ga, 1);
    imprime_grafoA(&Ga);

   int Vm = 10; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}
