#include "TAD_EXERCICIOSAULA15.h"
#include <stdlib.h>
#include <stdio.h>

Lista* lst_cria() {
    return NULL;
}

Lista* lst_insere(Lista* l , int info) {
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    
        if(!nova){
            printf("FALHA AO ALOCAR MEMORIA");
            return l;
        }
    
    nova->info = info;
    nova->prox = l;
    return nova;
}

Lista* lst_imprime(Lista* l) {
    for(Lista* p = l ; p != NULL ; p->prox)
        printf("%d",p->info);
    
}

void lst_libera(Lista* l) {
    Lista* p = l;
    while(p != NULL) {
        Lista* t = p->prox;
        free(l);
        t = p;
    }
}
int lst_vazia(Lista* l) {
    return l == NULL;
}

Lista* lst_insere_fim(Lista* l, int info) {
    if(l == NULL) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = info;
    novo->prox = NULL;
    return novo;
    }

    l->prox = lst_insere_fim(l->prox , info);
    return l;
    
}

Lista* lst_remove(Lista* l , int info) {
        Lista* ant = NULL;
        Lista* p = l;
        while(p != NULL && p->info != info){
            ant = p;
            p = p->prox;
        }
        if(ant = NULL) {
            l = p->prox;
        }
        else {
            ant->prox = p->prox;
        }
        free(p);
        return l;
}

int lst_tamanho(Lista* l) {
    if( l == NULL)
        return 0;           // verifica se a lista acabou
    return 1 + lst_tamanho(l->prox);
}

Lista* lst_insere_ordenado(Lista* l , int info) {
    if( l == NULL || info < l->info) 
        lst_insere(l , info);       // inserindo na cabeça da lista
    l->prox = lst_insere_ordenado(l->prox , info);          // inserindo sem ser na cabeça 
    return l;
}




