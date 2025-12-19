#ifndef __STACK1_H__
#define __STACK1_H__

typedef struct lista
{
    float info;
    struct lista *prox;
} Lista;

typedef struct pilha
{
    Lista *topo;
} Pilha;

Pilha *pilha_cria();
void pilha_push(Pilha *p, float info);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);

#include "stack1.c"
#endif