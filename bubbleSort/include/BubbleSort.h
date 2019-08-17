#pragma once

#define TIPO Aluno
#define CAMPO mat
#define PTIPO Aluno
#define EP .mat

typedef struct aluno {
  char nome[81];
  char mat[8];
  char turma;
  char email[41];
} Aluno;

void bubbleSort (int n, void *V, int tam, int (*cmp)(void*, void*));
static void* acessa (void *V, int i, int tam);
int comparaI (void *A, void *B);
int comparaS (void *A, void *B);
static void troca (void *A, void *B, int tam);
void imprime (int n, void *V, char *S);
