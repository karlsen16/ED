#ifndef ____LISTA_H_
#define ____LISTA_H_

#include <stdio.h>
#define TIPO int
typedef struct lista Lista;

Lista* criarLista ();
TIPO retornaLista (Lista*L);

/*Comum*/
int igualLista (Lista *L, Lista *L2);
void destroiLista (Lista *L);
Lista* inserirLista (Lista *L, TIPO valor);
Lista* buscaLista (Lista *L, TIPO valor);
Lista* inserirOrdenadoLista (Lista *L, TIPO valor);
Lista* removerLista (Lista *L, TIPO valor);
void imprimeLista (Lista *L);

/*Recursivo*/
int igualRecursivoLista (Lista *L, Lista *L2);
void destroiRecursivoLista (Lista *L);
Lista* buscaRecursivoLista (Lista *L, TIPO valor);
Lista* removerRecursivoLista (Lista *L, TIPO valor);
void imprimeRecursivoLista (Lista *L);
void imprimeRecursivoInversoLista (Lista *L);

/*Ponteiro*/
void inserirPonteiroLista (Lista **L, TIPO valor);
Lista** buscaPonteiroLista (Lista **L, TIPO valor);
void inserirOrdenadoPonteiroLista (Lista **L, TIPO valor);
void removerPonteiroLista (Lista **L, TIPO valor);

/*Circular*/
int igualListaCircular (Lista *L, Lista *L2);
void destroiListaCircular (Lista *L);
Lista* inserirListaCircular (Lista *L, TIPO valor);
Lista* buscaListaCircular (Lista *L, TIPO valor);
Lista* inserirOrdenadoListaCircular (Lista *L, TIPO valor);
Lista* removerListaCircular (Lista *L, TIPO valor);
void imprimeListaCircular (Lista *L);
void imprimeCrescenteListaCircular (Lista *L);
void imprimeDecrescenteListaCircular (Lista *L);
void auxiliarIDLC (Lista *L, Lista *inicio);

#endif  /* ____LISTA_H_ */
