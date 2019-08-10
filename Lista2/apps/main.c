#include "lista2.h"

void testesComum (Lista2 *L);
void testesComum2 (Lista2 *L);
void testesComum3 (Lista2 *L);
void testesRecursivo (Lista2 *L);
void testesPonteiros (Lista2 *L);
void testesPonteiros2 (Lista2 *L);
void testesPonteiros3 (Lista2 *L);
void testesCircular (Lista2 *L);
void testesCircular2 (Lista2 *L);

int main () {
	Lista2 *L = criarLista2();
	// testesComum(L);
	// testesComum2(L);
	// testesComum3(L);
	// testesRecursivo(L);
	// testesPonteiros(L);
	// testesPonteiros2(L);
	// testesPonteiros3(L);
	// testesCircular(L);
	// testesCircular2(L);
	return 0;
}

void testesComum (Lista2 *L) {
	L = inserirLista2(L, 3);
	L = inserirLista2(L, 5);
	L = inserirLista2(L, 8);
	imprimeLista2(L);
	Lista2 *aux = buscaLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	L = removerLista2(L, 3);
	aux = inserirLista2(L, 2);
	imprimeLista2(aux);
	imprimeLista2(L);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista2(L, aux));
	L = aux;
	L = inserirLista2(L, 1);
	imprimeLista2(L);
	L = inserirLista2(L, 7);
	imprimeLista2(L);
	L = removerLista2(L, 7);
	imprimeLista2(L);
	L = removerLista2(L, 8);
	imprimeLista2(L);
	L = inserirLista2(L, 8);
	imprimeLista2(L);
	aux = buscaLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	imprimeLista2(L);
	imprimeInversoLista2(L);
	destroiLista2(L);
}

void testesComum2 (Lista2 *L) {
	L = inserirOrdenadoLista2(L, 3);
	L = inserirOrdenadoLista2(L, 5);
	L = inserirOrdenadoLista2(L, 8);
	imprimeLista2(L);
	Lista2 *aux = buscaLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	L = removerLista2(L, 3);
	aux = inserirOrdenadoLista2(L, 2);
	imprimeLista2(aux);
	imprimeLista2(L);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista2(L, aux));
	L = aux;
	L = inserirOrdenadoLista2(L, 1);
	imprimeLista2(L);
	L = inserirOrdenadoLista2(L, 7);
	imprimeLista2(L);
	L = removerLista2(L, 7);
	imprimeLista2(L);
	L = removerLista2(L, 8);
	imprimeLista2(L);
	L = inserirOrdenadoLista2(L, 8);
	imprimeLista2(L);
	aux = buscaLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	imprimeLista2(L);
	imprimeInversoLista2(L);
	destroiLista2(L);
}

void testesComum3 (Lista2 *L) {
	L = inserirFinalLista2(L, 3);
	L = inserirFinalLista2(L, 5);
	L = inserirFinalLista2(L, 8);
	imprimeLista2(L);
	Lista2 *aux = buscaLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	L = removerLista2(L, 3);
	aux = inserirFinalLista2(L, 2);
	imprimeLista2(aux);
	imprimeLista2(L);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista2(L, aux));
	L = aux;
	L = inserirFinalLista2(L, 1);
	imprimeLista2(L);
	L = inserirFinalLista2(L, 7);
	imprimeLista2(L);
	L = removerLista2(L, 7);
	imprimeLista2(L);
	L = removerLista2(L, 8);
	imprimeLista2(L);
	L = inserirFinalLista2(L, 8);
	imprimeLista2(L);
	aux = buscaLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	imprimeLista2(L);
	imprimeInversoLista2(L);
	destroiLista2(L);
}

void testesRecursivo (Lista2 *L) {
	L = inserirLista2(L, 3);
	L = inserirLista2(L, 5);
	L = inserirLista2(L, 8);
	imprimeRecursivoLista2(L);
	Lista2 *aux = buscaRecursivoLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	L = removerRecursivoLista2(L, 3);
	aux = inserirLista2(L, 2);
	imprimeRecursivoLista2(aux);
	imprimeRecursivoLista2(L);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualRecursivoLista2(L, aux));
	L = aux;
	L = inserirLista2(L, 1);
	imprimeRecursivoLista2(L);
	L = inserirLista2(L, 7);
	imprimeRecursivoLista2(L);
	L = removerRecursivoLista2(L, 7);
	imprimeRecursivoLista2(L);
	L = removerRecursivoLista2(L, 8);
	imprimeRecursivoLista2(L);
	L = inserirLista2(L, 8);
	imprimeRecursivoLista2(L);
	aux = buscaRecursivoLista2(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	imprimeRecursivoLista2(L);
	destroiRecursivoLista2(L);
}

void testesPonteiros (Lista2 *L) {
	inserirPonteiroLista2(&L, 3);
	inserirPonteiroLista2(&L, 5);
	inserirPonteiroLista2(&L, 8);
	imprimeLista2(L);
	Lista2 **aux = buscaPonteiroLista2(&L, 3);
	removerPonteiroLista2(&L, 3);
	inserirPonteiroLista2(&L, 2);
	printf("\nRemovido o 3 e adicionado o 2.\n");
	imprimeLista2(L);
	inserirPonteiroLista2(&L, 1);
	imprimeLista2(L);
	inserirPonteiroLista2(&L, 7);
	imprimeLista2(L);
	removerPonteiroLista2(&L, 7);
	imprimeLista2(L);
	removerPonteiroLista2(&L, 8);
	imprimeLista2(L);
	inserirPonteiroLista2(&L, 8);
	imprimeLista2(L);
	aux = buscaPonteiroLista2(&L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(*aux));
	imprimeLista2(L);
	imprimeInversoLista2(L);
	destroiLista2(L);
}

void testesPonteiros2 (Lista2 *L) {
	inserirOrdenadoPonteiroLista2(&L, 3);
	inserirOrdenadoPonteiroLista2(&L, 5);
	inserirOrdenadoPonteiroLista2(&L, 8);
	imprimeLista2(L);
	Lista2 **aux = buscaPonteiroLista2(&L, 3);
	removerPonteiroLista2(&L, 3);
	inserirOrdenadoPonteiroLista2(&L, 2);
	printf("\nRemovido o 3 e adicionado o 2.\n");
	imprimeLista2(L);
	inserirOrdenadoPonteiroLista2(&L, 1);
	imprimeLista2(L);
	inserirOrdenadoPonteiroLista2(&L, 7);
	imprimeLista2(L);
	removerPonteiroLista2(&L, 7);
	imprimeLista2(L);
	removerPonteiroLista2(&L, 8);
	imprimeLista2(L);
	inserirOrdenadoPonteiroLista2(&L, 8);
	imprimeLista2(L);
	aux = buscaPonteiroLista2(&L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(*aux));
	imprimeLista2(L);
	imprimeInversoLista2(L);
	destroiLista2(L);
}

void testesPonteiros3 (Lista2 *L) {
	inserirPonteiroFinalLista2(&L, 3);
	inserirPonteiroFinalLista2(&L, 5);
	inserirPonteiroFinalLista2(&L, 8);
	imprimeLista2(L);
	Lista2 **aux = buscaPonteiroLista2(&L, 3);
	removerPonteiroLista2(&L, 3);
	inserirPonteiroFinalLista2(&L, 2);
	printf("\nRemovido o 3 e adicionado o 2.\n");
	imprimeLista2(L);
	inserirPonteiroFinalLista2(&L, 1);
	imprimeLista2(L);
	inserirPonteiroFinalLista2(&L, 7);
	imprimeLista2(L);
	removerPonteiroLista2(&L, 7);
	imprimeLista2(L);
	removerPonteiroLista2(&L, 8);
	imprimeLista2(L);
	inserirPonteiroFinalLista2(&L, 8);
	imprimeLista2(L);
	aux = buscaPonteiroLista2(&L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(*aux));
	imprimeLista2(L);
	imprimeInversoLista2(L);
	destroiLista2(L);
}

void testesCircular (Lista2 *L) {
	L = inserirLista2Circular(L, 3);
	L = inserirLista2Circular(L, 5);
	L = inserirLista2Circular(L, 8);
	imprimeLista2Circular(L);
	Lista2 *aux = buscaLista2Circular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	L = removerLista2Circular(L, 3);
	aux = inserirLista2Circular(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista2Circular(L, aux));
	L = aux;
	imprimeLista2Circular(L);
	L = inserirLista2Circular(L, 1);
	imprimeLista2Circular(L);
	L = inserirLista2Circular(L, 7);
	imprimeLista2Circular(L);
	L = removerLista2Circular(L, 7);
	imprimeLista2Circular(L);
	L = removerLista2Circular(L, 8);
	imprimeLista2Circular(L);
	L = inserirLista2Circular(L, 8);
	imprimeLista2Circular(L);
	aux = buscaLista2Circular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	imprimeLista2Circular(L);
	destroiLista2Circular(L);
}

void testesCircular2 (Lista2 *L) {
	L = inserirOrdenadoLista2Circular(L, 3);
	L = inserirOrdenadoLista2Circular(L, 5);
	L = inserirOrdenadoLista2Circular(L, 8);
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	Lista2 *aux = buscaLista2Circular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	L = removerLista2Circular(L, 3);
	aux = inserirOrdenadoLista2Circular(L, 2);
	printf("\nRemovido o 3 e adicionado o 2 -> iguais? %d.\n", igualLista2Circular(L, aux));
	L = aux;
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	L = inserirOrdenadoLista2Circular(L, 1);
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	L = inserirOrdenadoLista2Circular(L, 7);
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	L = removerLista2Circular(L, 7);
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	L = removerLista2Circular(L, 8);
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	L = inserirOrdenadoLista2Circular(L, 8);
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular (L);
	aux = buscaLista2Circular(L, 3);
	printf("\nFeita a busca por 3 -> Resultado: %d.\n", retornaLista2(aux));
	imprimeCrescenteLista2Circular(L);
	imprimeDecrescenteLista2Circular(L);
	destroiLista2Circular(L);
}
