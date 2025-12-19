#ifndef __TAD_EXERCICIOS_AULA_15_H__
    #define __TAD_EXERCICIOS_AULA_15_H__

    typedef struct lista {
        int info;
        struct list* prox;
    }Lista;

    Lista* lst_cria();          // cria vazia
    Lista* lst_insere(Lista* l, int info);          //  insere elemento na lista
    Lista* lst_imprime(Lista* l);           //imprime lista em ordem
    void lst_libera(Lista* l);              // libera lista 
    int lst_vazia(Lista* l);                 // lista vazia , auxiliar para verificacao , retorna 1 se for vazia e 0 se nao for vazia
    Lista* lst_imprime_fim(Lista* l, int info);         // usando recursividade ela insere elementos no fim da lista existente
    Lista* lst_remove(Lista* l , int info);             // remove valor da lista
    Lista* lst_insere_ordenado(Lista* l , int info);


#include "TAD_EXERCICIOSAULA15.c"
#endif