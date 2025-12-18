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

int main() {
    List* l;
    l = lst_cria();// create and init void list

    int x , y, z;
    printf("Digite um elemento para inserir na lista: ");
    scanf("%d",&x);
    printf("Digite um elemento para inserir na lista: ");
    scanf("%d",&y);
    printf("Digite um elemento para procurar na lista:");
    scanf("%d",&z);
    l = lst_insere(l , x);         // insert 23 in list
    l = lst_insere(l , y);     
    lst_search(l,y);   
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