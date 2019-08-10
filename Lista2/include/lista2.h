#ifndef ____LISTA2_H_
#define ____LISTA2_H_

#include <stdio.h>
#define TIPO int
typedef struct lista2 Lista2;

Lista2* criarLista2 ();
TIPO retornaLista2 (Lista2 *L);

/*Comum*/
int igualLista2 (Lista2 *L, Lista2 *L2);
void destroiLista2 (Lista2 *L);
Lista2* inserirLista2 (Lista2 *L, TIPO valor);
Lista2* inserirFinalLista2 (Lista2 *L, TIPO valor);
Lista2* buscaLista2 (Lista2 *L, TIPO valor);
Lista2* inserirOrdenadoLista2 (Lista2 *L, TIPO valor);
Lista2* removerLista2 (Lista2 *L, TIPO valor);
void imprimeLista2 (Lista2 *L);
void imprimeInversoLista2 (Lista2 *L);

/*Recursivo*/
int igualRecursivoLista2 (Lista2 *L, Lista2 *L2);
void destroiRecursivoLista2 (Lista2 *L);
Lista2* buscaRecursivoLista2 (Lista2 *L, TIPO valor);
Lista2* removerRecursivoLista2 (Lista2 *L, TIPO valor);
void imprimeRecursivoLista2 (Lista2 *L);
void imprimeRecursivoInversoLista2 (Lista2 *L);

/*Ponteiro*/
void inserirPonteiroLista2 (Lista2 **L, TIPO valor);
void inserirPonteiroFinalLista2 (Lista2 **L, TIPO valor);
Lista2** buscaPonteiroLista2 (Lista2 **L, TIPO valor);
void inserirOrdenadoPonteiroLista2 (Lista2 **L, TIPO valor);
void removerPonteiroLista2 (Lista2 **L, TIPO valor);

/*Circular*/
int igualLista2Circular (Lista2 *L, Lista2 *L2);
void destroiLista2Circular (Lista2 *L);
Lista2* inserirLista2Circular (Lista2 *L, TIPO valor);
Lista2* buscaLista2Circular (Lista2 *L, TIPO valor);
Lista2* inserirOrdenadoLista2Circular (Lista2 *L, TIPO valor);
Lista2* removerLista2Circular (Lista2 *L, TIPO valor);
void imprimeLista2Circular (Lista2 *L);
void imprimeCrescenteLista2Circular (Lista2 *L);
void imprimeDecrescenteLista2Circular (Lista2 *L);
void auxiliarIDL2C (Lista2 *L, Lista2 *inicio);

#endif  /* ____LISTA2_H_ */
