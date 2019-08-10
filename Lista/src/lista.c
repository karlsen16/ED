#include "lista.h"
#include <stdlib.h>

struct lista {
	TIPO info;
	struct lista *prox;
};

Lista* criarLista () {
	return NULL;
}

TIPO retornaLista (Lista*L) {
	if(L)
		return L->info;
	else
		return -1;
}

/*Comum*/
int igualLista (Lista *L, Lista *L2) {
	Lista *aux, *aux2;
	for(aux = L, aux2 = L2; aux != NULL && aux2 != NULL; aux = aux->prox, aux2 = aux2->prox)
		if(aux->info != aux2->info)
			return 0;
	return aux == aux2;
}

void destroiLista (Lista *L) {
	if(L) {
		Lista *aux = L->prox;
		free(L);
		destroiLista(aux);
	}
}

Lista* inserirLista (Lista *L, TIPO valor) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = L;
	return novo;
}

Lista* buscaLista (Lista *L, TIPO valor) {
	Lista *peao;
	for(peao = L; peao != NULL && peao->info != valor; peao = peao->prox);
	return peao;
}

Lista* inserirOrdenadoLista (Lista *L, TIPO valor) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	Lista *peao, *aux = NULL;
	for(peao = L; peao != NULL && peao->info < valor; peao = peao->prox)
		aux = peao;
	if(!aux) {
		novo->prox = L;
		L = novo;
	}
	else {
		novo->prox = peao;
		aux->prox = novo;
	}
	return L;
}

Lista* removerLista (Lista *L, TIPO valor) {
	Lista *peao, *aux = NULL;
	for(peao = L; peao != NULL && peao->info != valor; peao = peao->prox)
		aux = peao;
	if(!peao)
		return L;
	if(!aux)
		L = peao->prox;
	else
		aux->prox = peao->prox;
	free(peao);
	return L;
}

void imprimeLista (Lista *L) {
	Lista *peao;
	for(peao = L; peao != NULL; peao = peao->prox)
		printf("%3d", peao->info);
	printf("\n");
}

/*Recursivo*/
int igualRecursivoLista (Lista *L, Lista *L2) {
	if(!L && !L2)
		return 1;
	else if(!L || !L2)
		return 0;
	else
		return L->info == L2->info && igualRecursivoLista(L->prox, L2->prox);
}

void destroiRecursivoLista (Lista *L) {
	if(L) {
		destroiLista(L->prox);
		free(L);
	}
}

Lista* buscaRecursivoLista (Lista *L, TIPO valor) {
	if(L && L->info != valor)
			return buscaRecursivoLista(L->prox, valor);
	return L;
}

Lista* removerRecursivoLista (Lista *L, TIPO valor) {
	if(L) {
		if(L->info == valor) {
			Lista *aux = L;
			L = L->prox;
			free(aux);
		}
		else
			L->prox = removerRecursivoLista(L->prox, valor);
	}
	return L;
}

void imprimeRecursivoLista (Lista *L) {
	if(L) {
		printf("%3d", L->info);
		imprimeRecursivoLista(L->prox);
	}
	else
		printf("\n");
}

void imprimeRecursivoInversoLista (Lista *L) {
	if(L) {
		imprimeRecursivoInversoLista(L->prox);
		printf("%3d", L->info);
	}
}

/*Ponteiro*/
void inserirPonteiroLista (Lista **L, TIPO valor) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = *L;
	*L = novo;
}

Lista** buscaPonteiroLista (Lista **L, TIPO valor) {
	while(*L != NULL && (*L)->info != valor)
		L = &(*L)->prox;
	return L;
}

void inserirOrdenadoPonteiroLista (Lista **L, TIPO valor) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	while(*L != NULL && (*L)->info < valor)
		L = &(*L)->prox;
	Lista *aux = *L;
	*L = novo;
	novo->prox = aux;
}

void removerPonteiroLista (Lista **L, TIPO valor) {
	Lista **peao = buscaPonteiroLista(L, valor);
	if(*peao) {
		Lista *aux = *peao;
		*peao = (*peao)->prox;
 		if(aux)
 			free(aux);
	}
}

/*Circular*/
int igualListaCircular (Lista *L, Lista *L2) {
	if(((!L || !L2) && (L || L2)) || (!L || (L->info != L2->info)))
		return 0;
	Lista *aux, *aux2;
	for(aux = L->prox, aux2 = L2->prox; aux->prox != L && aux2->prox != L2; aux = aux->prox, aux2 = aux2->prox)
		if(aux->info != aux2->info)
			return 0;
	return 1;
}

void destroiListaCircular (Lista *L) {
	if(L) {
		Lista *peao = L->prox, *aux;
		while(peao != L) {
			aux = peao;
			peao = peao->prox;
			free(aux);
		}
		free(peao);
	}
}

Lista* inserirListaCircular (Lista *L, TIPO valor) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = valor;
	if(!L)
		novo->prox = novo;
	else {
		novo->prox = L;
		Lista *aux = L;
		while(aux->prox != L)
			aux = aux->prox;
		aux->prox = novo;
	}
	return novo;
}

Lista* buscaListaCircular (Lista *L, TIPO valor) {
	if(L) {
		Lista *peao;
		for(peao = L; peao->prox != L && peao->info != valor; peao = peao->prox);
		if(peao->info == valor)
			return peao;
	}
	return NULL;
}

Lista* inserirOrdenadoListaCircular (Lista *L, TIPO valor) {
 	Lista *aux = L;
	if(L && L != L->prox) {
		Lista *peao, *inicio;
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
	return inserirListaCircular(aux, valor);
}

Lista* removerListaCircular (Lista *L, TIPO valor) {
	if(L) {
		Lista *peao = L, *aux = NULL;
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

void imprimeListaCircular (Lista *L) {
	if(L) {
		Lista *peao = L;
		do {
			printf("%3d", peao->info);
			peao = peao->prox;
		}while(peao != L);
		printf("\n");
	}
}

void imprimeCrescenteListaCircular (Lista *L) {
	if(L) {
		Lista *peao, *inicio = L;
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

void imprimeDecrescenteListaCircular (Lista *L) {
	if(L) {
		Lista *peao, *inicio = L;
		TIPO menor = L->info;
		for(peao = L->prox; peao != L; peao = peao->prox)
			if(peao->info < menor) {
				menor = peao->info;
				inicio = peao;
			}
		peao = inicio;
		auxiliarIDLC(inicio->prox, inicio);
		printf("%3d", inicio->info);
		printf("\n");
	}
}

void auxiliarIDLC (Lista *L, Lista *inicio) {
	if(L != inicio) {
		auxiliarIDLC(L->prox, inicio);
		printf("%3d", L->info);
	}
}
