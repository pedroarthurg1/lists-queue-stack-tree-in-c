#include <stdio.h>
#include <stdlib.h>
typedef struct list {
    int info;
    struct list* prox;
}List;

List* lst_cria();
List* lst_insere(List* l,int info);
void lst_imprime(List* l);
int lst_vazia(List* l);                 // return 1 void list and return 0 not void list
List* lst_search(List* l, int info);
List* lst_retira(List* l ,int info);
void lst_libera(List* l);

int main() {
    List* l;
    l = lst_cria();// create and init void list
    int b, r;
    l = lst_insere(l , 1);         // insert 23 in list
    l = lst_insere(l , 2);
    l = lst_insere(l , 3);
    l = lst_insere(l , 4);    
    lst_search(l,b);
    lst_retira(l,r);  
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
        printf("%d\n", p->info);
}

int lst_vazia(List* l) {
    return (l == NULL);
}

List* lst_search(List* l , int info) {
    List* p;
    for(p = l; p != NULL; p = p->prox) {
        if(p->info == info) {
            printf("VALOR ENCONTRADO\n");
            return p;
        }
            
    }
    return NULL;            // NOT FIND ELEMENT
}   

List* lst_retira(List* l ,int info) {
    List* ant = NULL;       // ponteiro para elemento anterior
    List* p = l;            // ponteiro para percorrer lista
    
    while(p != NULL && p->info != info) {
        ant = p;                
        p = p->prox;            // guarda elemento anterior
    }

    if(p == NULL)
        return l;               // elemento nao encontrado

    if(ant == NULL)
        l = p->prox;            //  retira inicio
    else
        ant->prox = p->prox;    // retira meio
}

void lst_libera(List* l) {
    List* p = l;
    while (p != NULL)
    {
        List* t = p->prox;
        free(p);        // libera memoria para onde aponta p
        p = t;          // aponta proximo
    }
    
}