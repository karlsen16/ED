#ifndef QUEUE__H
#define QUEUE__H

#include <stdio.h>

typedef struct queue {
  int info;
  struct queue *next;
}Queue;

Queue* createQueue ();
void freeQueue (Queue *Q);
Queue* enqueue (Queue *Q, int elem);
Queue* dequeue (Queue *Q);
int Front (Queue *Q);
int Empty (Queue *Q);

typedef struct doublyLinkedList {
  int info;
  struct doublyLinkedList *next;
  struct doublyLinkedList *previous;
}List;

List* createList ();
void print (List *L);
void reversePrint (List *L);
List* insertLeft (List *L, int elem);
List* insertRight (List *L, int elem);
List* insertMiddle (List *L, int elem);
List* insertSorted (List *L, int elem);
List* delete (List *L, int elem);
void freeList (List *L);
List* search (List *L, int elem);

#endif /* _QUEUE_H */
