#include "calculadoraPosFixadaHP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int pilha_vazia(Pilha* p) {
    return (p->topo == NULL);
}

float pilha_pop(Pilha* p ) {
    Lista* t;
    float v;
    if(pilha_vazia(p)) {
        printf("PILHA VAZIA");
        exit(1);
    }
    t = p->topo;
    v = t->info;
    p->topo = t->prox;
    free(t);
    return v;
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

Calc* calc_cria(char* formato) {
    Calc* c = (Calc*)malloc(sizeof(Calc));
    strcpy(c->f,formato);
    c->p = pilha_cria();
    return c;

}

void calc_operando(Calc* c , float info) {
    pilha_push(c->p,info);  // empilha operando
    printf(c->f,info);      // imprime topo da pilha
}

void calc_operador(Calc* c , char op) {
    float v1 , v2 , v;
    if(pilha_vazia(c->p))
        v2 = 0.0;
    else
    v2 = pilha_pop(c->p);
    if(pilha_vazia(c->p))
        v1 = 0.0;
    else
    v1 = pilha_pop(c->p);
    
    switch (op) {
        case '+' : v = v1+v2; break;
        case '-' : v = v1-v2; break;
        case '*' : v = v1*v2; break;
        case '/' : v = v1/v2; break;
    }
}

void calc_libera(Calc* c) {
    pilha_libera(c->p);
    free(c);

}