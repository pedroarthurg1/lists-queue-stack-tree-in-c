#include "stack1.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* pilha_cria() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_push(Pilha* p , float info) {
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->info = info;
    n->prox = p->topo;
    p->topo = n;
}

float pilha_pop(Pilha* p) {
    Lista* t;   //  referencia ao no anterior
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia\n");
        exit(1);
    }
    t = p->topo;
    v = t->info;
    p->topo = t->prox;
    free(t);
    return v;
}   

int pilha_vazia(Pilha* p) {
    return (p->topo == NULL);       
}

void pilha_libera(Pilha* p) {
    Lista* q = p->topo;
    while(q != NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_imprime(Pilha* p) {
    for(Lista* q = p->topo; q != NULL; q = q->prox)
        printf("%f\n",q->info);
}