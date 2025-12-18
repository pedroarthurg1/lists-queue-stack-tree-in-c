#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int info;
    struct no* sae;
    struct no* sad;
}No;

static int max2(int a , int b) {
    return (a > b ) ? a : b;
}

No* arv_criavazia();
No* arv_cria(No* a);
No* arv_imprime_pre(No* a);
No* arv_imprime_pos(No* a);
No* arv_delete(No* a);
int arv_altura(No* a);
int arv_nos(No* a);
int arv_folhas(No* a);
int arvvazia(No* a);
int arv_soma(No* a);
int arv_estrita(No* a);


int main()
{

}

int arv_altura(No* a) {
    if(a== NULL) {
        return -1; // Arvore vazia...
    }
    else {
        return 1 + max2(arv_altura(a->sae),arv_altura(a->sad));
    }
}

No* arv_imprime_pre(No* a) {
    if(a!=NULL) {
        printf("%d",a->info);
        arv_imprime_pre(a->sae);
        arv_imprime_pre(a->sad);
    }
}

No* arv_imprime_pre(No* a) {
    if(a!=NULL) {
        arv_imprime_pre(a->sae);
        arv_imprime_pre(a->sad);
        printf("%d",a->info);
    }
}

int arv_nos(No* a) {
    if(arvvazia(a)) {
        return 0;   // arvore vazia...
    }
    return 1 + arv_conta_nos(a->sae) + arv_conta_nos(a->sad);
}

int arv_folhas(No* a) {
    if(arvvazia(a)) {
        return 0; // arvore vazia...
    }

    if (a->sae == NULL && a->sad== NULL) {
        return 1;
    }
    
        return arv_folhas(a->sae) + arv_folhas(a->sad);
    
}

int arvvazia(No* a) {
    return a == NULL;
}

int arv_busca(No* a , int info) {
    if(arvvazia(a)) {
        return 0;
    }
    else {
        return a->info == info || arv_busca(a->sae,info) || arv_busca(a->sad,info);
    }

}   

int arv_soma(No* a) {
    if(arvvazia(a)) {
        return 0;
    }
    else {
        return a->info + arv_soma(a->sae) + arv_soma(a->sad);
    }
}

int arv_e_cheia(No* a) {
    if(arvvazia(a)) {
        return 0;   // nao é cheia
    }
    if(a->sae != NULL && a->sad != NULL) {
        return 1;   // é cheia
    }
}

int arv_estrita(No* a) {
    if(a->sae == NULL && a->sad ==  NULL) {
        return 1;
    }
    else if(a->sae != NULL && a->sad !=NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

No* arv_clona(No* a , int info) {
    No* no_clone = (No*)malloc(sizeof(No));
    no_clone->info = info;
    no_clone->sae = a->sae;
    no_clone->sad = a->sad;

    return no_clone;
}

int arv_Menor(No* a) {
    int menorsae = arv_Menor(a->sae);
    int menorsad = arv_Menor(a->sad);
    int menor = arv_Menor(a->info);

    if(menor < menorsae)
        menorsae = menor;

    if(menor < menorsad)
        menorsad = menor;

    return menor;

}