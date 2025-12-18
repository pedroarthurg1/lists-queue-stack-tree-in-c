#include <stdio.h>
#include <stdlib.h>
typedef struct list {
    int info;
    struct list* prox;
}List;

List* lst_cria();
List* lst_insere(List* l,int info);
void lst_imprime(List* l);
int lst_vazia(List* l);

int main() {
    List* l;
    l = lst_cria();                 // create and init void list
    l = lst_insere(l , 23);         // insert 23 in list           
    l = lst_insere(l , 45);         // insert 45 in list
    lst_imprime(l);
    

    return 0;
}

List* lst_cria() {
    return NULL;
}

List* lst_insere(List* l,int info) {
    List* novo = (List*)malloc(sizeof(List));

    novo->info = info;
    novo->prox = l;
    return novo;
}

void lst_imprime(List* l) {
    List* p;

    for(p = l ; p != NULL ; p = p->prox) 
        printf("info = %d\n", p->info);
}

int lst_vazia(List* l) {
    return (l == NULL);
}