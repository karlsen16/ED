#include "lista2.h"
#include <stdlib.h>

struct lista2 {
	TIPO info;
	struct lista2 *ant;
	struct lista2 *prox;
};

Lista2* criarLista2 () {
	return NULL;
}

TIPO retornaLista2 (Lista2 *L) {
	if(L)
		return L->info;
	else
		return -1;
}

/*Comum*/
int igualLista2 (Lista2 *L, Lista2 *L2) {
	Lista2 *aux, *aux2;
	for(aux = L, aux2 = L2; aux != NULL && aux2 != NULL; aux = aux->prox, aux2 = aux2->prox)
		if(aux->info != aux2->info)
			return 0;
	return aux == aux2;
}

void destroiLista2 (Lista2 *L) {
	if(L) {
		Lista2 *aux = L->prox;
		free(L);
		destroiLista2(aux);
	}
}

Lista2* inserirLista2 (Lista2 *L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	if(L)
		L->ant = novo;
	novo->prox = L;
	novo->ant = NULL;
	return novo;
}

Lista2* inserirFinalLista2 (Lista2 *L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	if(L) {
		Lista2 *peao;
		for(peao = L; peao->prox != NULL; peao = peao->prox);
		novo->ant = peao;
		peao->prox = novo;
	}
	else {
		novo->ant = NULL;
		L = novo;
	}
	novo->prox = NULL;
	return L;
}

Lista2* buscaLista2 (Lista2 *L, TIPO valor) {
	Lista2 *peao;
	for(peao = L; peao != NULL && peao->info != valor; peao = peao->prox);
	return peao;
}

Lista2* inserirOrdenadoLista2 (Lista2 *L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	Lista2 *peao;
	if(L) {
		for(peao = L; peao->prox != NULL && peao->info < valor; peao = peao->prox);
		if(peao->info >= valor) {
			novo->ant = peao->ant;
			if(peao->ant)
				peao->ant->prox = novo;
			peao->ant = novo;
			novo->prox = peao;
			if(peao == L)
				L = novo;
		}
		else {
			novo->ant = peao;
			novo->prox = peao->prox;
			if(peao->prox)
				peao->prox->ant = novo;
			peao->prox = novo;
		}
	}
	else{
		novo->prox = novo->ant = NULL;
		L = novo;
	}
	return L;
}

Lista2* removerLista2 (Lista2 *L, TIPO valor) {
	Lista2 *peao;
	for(peao = L; peao != NULL && peao->info != valor; peao = peao->prox);
	if(!peao)
		return L;
	if(!peao->ant) {
		L = peao->prox;
		L->ant = NULL;
	}
	else {
		peao->ant->prox = peao->prox;
		if(peao->prox)
			peao->prox->ant = peao->ant;
	}
	free(peao);
	return L;
}

void imprimeLista2 (Lista2 *L) {
	Lista2 *peao;
	for(peao = L; peao != NULL; peao = peao->prox)
		printf("%3d", peao->info);
	printf("\n");
}

void imprimeInversoLista2 (Lista2 *L) {
	Lista2 *peao;
	if(L) {
		for(peao = L; peao->prox != NULL; peao = peao->prox);
		while(peao != NULL) {
			printf("%3d", peao->info);
			peao = peao->ant;
		}
	}
	printf("\n");
}

/*Recursivo*/
int igualRecursivoLista2 (Lista2 *L, Lista2 *L2) {
	if(!L && !L2)
		return 1;
	else if(!L || !L2)
		return 0;
	else
		return L->info == L2->info && igualRecursivoLista2(L->prox, L2->prox);
}

void destroiRecursivoLista2 (Lista2 *L) {
	if(L) {
		destroiLista2(L->prox);
		free(L);
	}
}

Lista2* buscaRecursivoLista2 (Lista2 *L, TIPO valor) {
	if(L && L->info != valor)
			return buscaRecursivoLista2(L->prox, valor);
	return L;
}

Lista2* removerRecursivoLista2 (Lista2 *L, TIPO valor) {
	if(L) {
		if(L->info == valor) {
			Lista2 *aux = L;
			L = L->prox;
			free(aux);
		}
		else
			L->prox = removerRecursivoLista2(L->prox, valor);
	}
	return L;
}

void imprimeRecursivoLista2 (Lista2 *L) {
	if(L) {
		printf("%3d", L->info);
		imprimeRecursivoLista2(L->prox);
	}
	else
		printf("\n");
}

void imprimeRecursivoInversoLista2 (Lista2 *L) {
	if(L) {
		imprimeRecursivoInversoLista2(L->prox);
		printf("%3d", L->info);
	}
}

/*Ponteiro*/
void inserirPonteiroLista2 (Lista2 **L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	novo->prox = *L;
	novo->ant = NULL;
	if(*L)
		(*L)->ant = novo;
	*L = novo;
}

void inserirPonteiroFinalLista2 (Lista2 **L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	novo->prox = NULL;
	Lista2 **peao = L;
	if(*peao) {
		while((*peao)->prox != NULL)
			peao = &(*peao)->prox;
		(*peao)->prox = novo;
	}
	novo->ant = *peao;
	if(!*L)
		*L = novo;
}

Lista2 ** buscaPonteiroLista2 (Lista2 **L, TIPO valor) {
	while(*L != NULL && (*L)->info != valor)
		L = &(*L)->prox;
	return L;
}

void inserirOrdenadoPonteiroLista2 (Lista2 **L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	Lista2 **peao = L;
	if(*peao) {
		while((*peao)->prox != NULL && (*peao)->info < valor)
			peao = &(*peao)->prox;
		if((*peao)->info >= valor) {
			novo->prox = *peao;
			novo->ant = (*peao)->ant;
			(*peao)->ant = novo;
			if(!novo->ant)
				*L = novo;
		}
		else {
			novo->ant = *peao;
			novo->prox = (*peao)->prox;
			(*peao)->prox = novo;
		}
	}
	else {
		novo->ant = novo->prox = NULL;
		*L = novo;
	}
}

void removerPonteiroLista2 (Lista2 **L, TIPO valor) {
	Lista2 **peao = buscaPonteiroLista2(L, valor);
	if(*peao) {
		Lista2 *aux = *peao;
		*peao = (*peao)->prox;
		if(*peao)
			(*peao)->ant = aux->ant;
 		if(aux)
 			free(aux);
	}
}

/*Circular*/
int igualLista2Circular (Lista2 *L, Lista2 *L2) {
	if(((!L || !L2) && (L || L2)) || (!L || (L->info != L2->info)))
		return 0;
	Lista2 *aux, *aux2;
	for(aux = L->prox, aux2 = L2->prox; aux->prox != L && aux2->prox != L2; aux = aux->prox, aux2 = aux2->prox)
		if(aux->info != aux2->info)
			return 0;
	return 1;
}

void destroiLista2Circular (Lista2 *L) {
	if(L) {
		Lista2 *peao = L->prox, *aux;
		while(peao != L) {
			aux = peao;
			peao = peao->prox;
			free(aux);
		}
		free(peao);
	}
}

Lista2* inserirLista2Circular (Lista2 *L, TIPO valor) {
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = valor;
	if(!L)
		novo->prox = novo;
	else {
		novo->prox = L;
		Lista2 *aux = L;
		while(aux->prox != L)
			aux = aux->prox;
		aux->prox = novo;
	}
	return novo;
}

Lista2* buscaLista2Circular (Lista2 *L, TIPO valor) {
	if(L) {
		Lista2 *peao;
		for(peao = L; peao->prox != L && peao->info != valor; peao = peao->prox);
		if(peao->info == valor)
			return peao;
	}
	return NULL;
}

Lista2* inserirOrdenadoLista2Circular (Lista2 *L, TIPO valor) {
 	Lista2 *aux = L;
	if(L && L != L->prox) {
		Lista2 *peao, *inicio;
		int flag = 0;
		if(L->info > L->prox->info)
			peao = L->prox;
		else
			peao = L;
		inicio = aux = peao;
		do {
			if(peao->info > valor && (peao->info <= aux->info || !flag)) {
				aux = peao;
				flag = 1;
			}
			peao = peao->prox;
		}while(peao != inicio);
	}
	return inserirLista2Circular(aux, valor);
}

Lista2* removerLista2Circular (Lista2 *L, TIPO valor) {
	if(L) {
		Lista2 *peao = L, *aux = NULL;
		while(peao->prox != L && peao->info != valor) {
			aux = peao;
			peao = peao->prox;
		}
		if(peao->info == valor) {
			if(!aux) {
			 	if(peao->prox == peao)
					L = NULL;
				else {
					aux = peao->prox;
					*peao = *aux;
					peao = aux;
				}
			}
			else
				aux->prox = peao->prox;
			free(peao);
		}
	}
	return L;
}

void imprimeLista2Circular (Lista2 *L) {
	if(L) {
		Lista2 *peao = L;
		do {
			printf("%3d", peao->info);
			peao = peao->prox;
		}while(peao != L);
		printf("\n");
	}
}

void imprimeCrescenteLista2Circular (Lista2 *L) {
	if(L) {
		Lista2 *peao, *inicio = L;
		TIPO menor = L->info;
		for(peao = L->prox; peao != L; peao = peao->prox)
			if(peao->info < menor) {
				menor = peao->info;
				inicio = peao;
			}
		peao = inicio;
		do {
			printf("%3d", peao->info);
			peao = peao->prox;
		}while(peao != inicio);
		printf("\n");
	}
}

void imprimeDecrescenteLista2Circular (Lista2 *L) {
	if(L) {
		Lista2 *peao, *inicio = L;
		TIPO menor = L->info;
		for(peao = L->prox; peao != L; peao = peao->prox)
			if(peao->info < menor) {
				menor = peao->info;
				inicio = peao;
			}
		peao = inicio;
		auxiliarIDL2C(inicio->prox, inicio);
		printf("%3d", inicio->info);
		printf("\n");
	}
}

void auxiliarIDL2C (Lista2 *L, Lista2 *inicio) {
	if(L != inicio) {
		auxiliarIDL2C(L->prox, inicio);
		printf("%3d", L->info);
	}
}
