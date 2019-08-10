#include "lista.h"

void testesComum (Lista *L);
void testesComum2 (Lista *L);
void testesRecursivo (Lista *L);
void testesPonteiros (Lista *L);
void testesPonteiros2 (Lista *L);
void testesCircular (Lista *L);
void testesCircular2 (Lista *L);

int main () {
	Lista *L = criarLista();
	testesComum(L);
	testesComum2(L);
	testesRecursivo(L);
	testesPonteiros(L);
	testesPonteiros2(L);
	testesCircular(L);
	testesCircular2(L);
	return 0;
}

void testesComum (Lista *L) {
	L = inserirLista(L, 3);
	L = inserirLista(L, 5);
	L = inserirLista(L, 8);
	imprimeLista(L);
	Lista *aux = buscaLista(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	L = removerLista(L, 3);
	aux = inserirLista(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista(L, aux));
	L = aux;
	imprimeLista(L);
	L = inserirLista(L, 1);
	imprimeLista(L);
	L = inserirLista(L, 7);
	imprimeLista(L);
	L = removerLista(L, 7);
	imprimeLista(L);
	L = removerLista(L, 8);
	imprimeLista(L);
	L = inserirLista(L, 8);
	imprimeLista(L);
	aux = buscaLista(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	imprimeLista(L);
	destroiLista(L);
}

void testesComum2 (Lista *L) {
	L = inserirOrdenadoLista(L, 3);
	L = inserirOrdenadoLista(L, 5);
	L = inserirOrdenadoLista(L, 8);
	imprimeLista(L);
	Lista *aux = buscaLista(L, 3);
	L = removerLista(L, 3);
	aux = inserirLista(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista(L, aux));
	L = aux;
	imprimeLista(L);
	L = inserirOrdenadoLista(L, 1);
	imprimeLista(L);
	L = inserirOrdenadoLista(L, 7);
	imprimeLista(L);
	L = removerLista(L, 7);
	imprimeLista(L);
	L = removerLista(L, 8);
	imprimeLista(L);
	L = inserirOrdenadoLista(L, 8);
	imprimeLista(L);
	aux = buscaLista(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	imprimeLista(L);
	destroiLista(L);
}
void testesRecursivo (Lista *L) {
	L = inserirLista(L, 3);
	L = inserirLista(L, 5);
	L = inserirLista(L, 8);
	imprimeRecursivoLista(L);
	imprimeRecursivoInversoLista(L);
	Lista *aux = buscaRecursivoLista(L, 3);
	L = removerRecursivoLista(L, 3);
	aux = inserirLista(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualRecursivoLista(L, aux));
	L = aux;
	imprimeRecursivoLista(L);
	L = inserirLista(L, 1);
	imprimeRecursivoLista(L);
	L = inserirLista(L, 7);
	imprimeRecursivoLista(L);
	L = removerRecursivoLista(L, 7);
	imprimeRecursivoLista(L);
	L = removerRecursivoLista(L, 8);
	imprimeRecursivoLista(L);
	L = inserirLista(L, 8);
	imprimeRecursivoLista(L);
	aux = buscaRecursivoLista(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	imprimeRecursivoLista(L);
	destroiRecursivoLista(L);
}

void testesPonteiros (Lista *L) {
	inserirPonteiroLista(&L, 3);
	inserirPonteiroLista(&L, 5);
	inserirPonteiroLista(&L, 8);
	imprimeLista(L);
	Lista **aux = buscaPonteiroLista(&L, 3);
	removerPonteiroLista(&L, 3);
	inserirPonteiroLista(&L, 2);
	printf("\nRemovido o 3 e adicionado o 2.\n");
	imprimeLista(L);
	inserirPonteiroLista(&L, 1);
	imprimeLista(L);
	inserirPonteiroLista(&L, 7);
	imprimeLista(L);
	removerPonteiroLista(&L, 7);
	imprimeLista(L);
	removerPonteiroLista(&L, 8);
	imprimeLista(L);
	inserirPonteiroLista(&L, 8);
	imprimeLista(L);
	aux = buscaPonteiroLista(&L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(*aux));
	imprimeLista(L);
	destroiLista(L);
}

void testesPonteiros2 (Lista *L) {
	inserirOrdenadoPonteiroLista(&L, 3);
	inserirOrdenadoPonteiroLista(&L, 5);
	inserirOrdenadoPonteiroLista(&L, 8);
	imprimeLista(L);
	Lista **aux = buscaPonteiroLista(&L, 3);
	removerPonteiroLista(&L, 3);
	inserirOrdenadoPonteiroLista(&L, 2);
	printf("\nRemovido o 3 e adicionado o 2.\n");
	imprimeLista(L);
	inserirOrdenadoPonteiroLista(&L, 1);
	imprimeLista(L);
	inserirOrdenadoPonteiroLista(&L, 7);
	imprimeLista(L);
	removerPonteiroLista(&L, 7);
	imprimeLista(L);
	removerPonteiroLista(&L, 8);
	imprimeLista(L);
	inserirOrdenadoPonteiroLista(&L, 8);
	imprimeLista(L);
	aux = buscaPonteiroLista(&L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(*aux));
	imprimeLista(L);
	destroiLista(L);
}

void testesCircular (Lista *L) {
	L = inserirListaCircular(L, 3);
	L = inserirListaCircular(L, 5);
	L = inserirListaCircular(L, 8);
	imprimeListaCircular(L);
	Lista *aux = buscaListaCircular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	L = removerListaCircular(L, 3);
	aux = inserirListaCircular(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualListaCircular(L, aux));
	L = aux;
	imprimeListaCircular(L);
	L = inserirListaCircular(L, 1);
	imprimeListaCircular(L);
	L = inserirListaCircular(L, 7);
	imprimeListaCircular(L);
	L = removerListaCircular(L, 7);
	imprimeListaCircular(L);
	L = removerListaCircular(L, 8);
	imprimeListaCircular(L);
	L = inserirListaCircular(L, 8);
	imprimeListaCircular(L);
	aux = buscaListaCircular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	imprimeListaCircular(L);
	destroiListaCircular(L);
}

void testesCircular2 (Lista *L) {
	L = inserirOrdenadoListaCircular(L, 3);
	L = inserirOrdenadoListaCircular(L, 5);
	L = inserirOrdenadoListaCircular(L, 8);
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	Lista *aux = buscaListaCircular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	L = removerListaCircular(L, 3);
	aux = inserirOrdenadoListaCircular(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualListaCircular(L, aux));
	L = aux;
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	L = inserirOrdenadoListaCircular(L, 1);
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	L = inserirOrdenadoListaCircular(L, 7);
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	L = removerListaCircular(L, 7);
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	L = removerListaCircular(L, 8);
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	L = inserirOrdenadoListaCircular(L, 8);
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular (L);
	aux = buscaListaCircular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista(aux));
	imprimeCrescenteListaCircular(L);
	imprimeDecrescenteListaCircular(L);
	destroiListaCircular(L);
}
