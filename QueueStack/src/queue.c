#include <stdlib.h>
#include "queue.h"

Queue* createQueue () {
  return NULL;
}

void freeQueue (Queue *Q) {
  Queue *aux;
  while(Q != NULL) {
    aux = Q->next;
    free(Q);
    Q = aux;
  }
}

Queue* enqueue (Queue *Q, int elem) {
  Queue *new = (Queue*)malloc(sizeof(Queue));
  new->info = elem;
  new->next = Q;
  return new;
}

Queue* dequeue (Queue *Q) {
  Queue *walk = Q;
  Queue *previous = NULL;
  while(walk != NULL && walk->next != NULL) {
    previous = walk;
    walk = walk->next;
  }
  if(walk == NULL)
    return Q;
  if(previous == NULL)
    Q = walk->next;
  else
    previous->next = walk->next;
  free(walk);
  return Q;
}

int Front (Queue *Q) {
  Queue *walk;
  for(walk = Q; walk->next != NULL; walk = walk->next) {}
  return walk->info;
}

int Empty (Queue *Q) {
  if(Q == NULL)
    return 1;
  else
    return 0;
}

List* createList () {
  return NULL;
}

void print (List *L) {
  List *walk;
  for(walk = L; walk != NULL; walk = walk->next)
    printf("%5d", walk->info);
  printf("\n");
}

void reversePrint (List *L) {
  List *walk;
  for(walk = L; walk != NULL; walk = walk->previous)
    printf("%5d", walk->info);
  printf("\n");
}

List* insertLeft (List *L, int elem) {
  List *new = (List*)malloc(sizeof(List));
  new->info = elem;
  if(L != NULL) {
    new->next = L;
    L->previous = new;
  }
  else
    new->next = NULL;
  new->previous = NULL;
  return new;
}

List* insertRight (List *L, int elem) {
  List *new = (List*)malloc(sizeof(List));
  new->info = elem;
  if(L != NULL) {
    new->previous = L;
    L->next = new;
  }
  else
    new->previous = NULL;
  new->next = NULL;
  return new;
}

List* insertMiddle (List *L, int elem) {
  if(L == NULL || L->previous == NULL)
    return insertLeft(L, elem);
  List *new = (List*)malloc(sizeof(List));
  new->info = elem;
  L->previous->next = new;
  new->previous = L->previous;
  L->previous = new;
  new->next = L;
  return new;
}

List* insertSorted (List *L, int elem) {
  if(L == NULL || L->info >= elem)
    return insertLeft(L, elem);
  List *walk = L;
  while(walk != NULL) {
    if(walk->next == NULL) {
      walk = insertRight(walk, elem);
      break;
    }
    walk = walk->next;
    if(walk->info >= elem) {
      walk = insertMiddle(walk, elem);
      break;
    }
  }
  return L;
}

List* delete (List *L, int elem) {
  List *v = search(L, elem);
  if(v == NULL)
    return L;
  else if(v->next == NULL && v->previous == NULL)
    return NULL;
  else if(v->previous == NULL) {
    v->next->previous = NULL;
    return v->next;
  }
  else if(v->next == NULL) {
    v->previous->next = NULL;
    return v->previous;
  }
  else {
    v->next->previous = v->previous;
    v->previous->next = v->next;
    return L;
  }
}

void freeList (List *L) {
  while(L != NULL) {
    List *aux = L->next;
    free(L);
    L = aux;
  }
}

List* search (List *L, int elem) {
  List *walk = L;
  while(walk != NULL && walk->info != elem)
    walk = walk->next;
  return walk;
}
