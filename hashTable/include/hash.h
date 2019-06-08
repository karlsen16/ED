#ifndef __HASH_H
#define __HASH_H
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct node {
    char k[256];
    struct node *next;
} Node;

typedef struct hash {
    int M;            /*N ́umero de entradas no hash.  */
    int N;            /*N ́umero de chaves armazenadas.*/
    Node **list;      /*Vetor de listas.*/
} Hash;

Hash* create_hash (int M);
void insert_chained (Hash *H, char *v);
void print_hash (Hash *H);
void free_hash (Hash *H);
int hash_function (char *v, int M);

#endif /* __HASH_H */
