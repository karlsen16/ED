#include <stdlib.h>
#include "hash.h"

Hash* create_hash (int M) {
    Hash *H = (Hash *)malloc(sizeof(Hash));
    H->M = M;
    H->N = 0;
    H->list = (Node **)malloc(M*sizeof(Node*));
    int h;
    for (h = 0; h < H->M; h++)
        H->list[h] = NULL;
    return H;
}

void insert_chained (Hash *H, char *v) {
    int h = hash_function (v, H->M);
    Node *n = (Node *)malloc(sizeof(Node));
    sprintf(n->k, "%s", v);
    n->next = H->list[h];
    H->list[h] = n;                 /*n  ́e a nova cabe ̧ca!*/
    H->N++;                         /*incremento do num. de chaves!*/
}

void print_hash (Hash *H) {
    int h;
    for (h = 0; h < H->M; h++) {
        Node *aux;
        for (aux = H->list[h]; aux != NULL; aux = aux->next)
            printf ("| %s ", aux->k);
        printf ("| \n");
    }
}

void free_hash (Hash *H) {
    int h;
    for (h = 0; h < H->M; h++)
        free (H->list[h]);
    free (H);
}

int hash_function (char *v, int M) {
    int i, h = v[0];
    for (i = 1; v[i] != '\0'; i++)
        h = (h * 256 + v[i]) % M;
    return h;
}
