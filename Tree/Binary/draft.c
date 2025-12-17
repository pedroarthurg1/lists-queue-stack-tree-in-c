#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    char info;
    struct no* sae;
    struct no* sad;
}No;

static int max2(char a , int b) {
    return (a > b) ? a : b;
}

No *No_criavazia(void);               // cria Noore vazia
No* No_cria(char c,No* sae, No* sad); // cria um nó dadas as informações e as subNoores , sae e sad | Retonr o endereço do no raiz
No* arv_imprime(No* arvore); 
No* arv_libera(No* arvore);
char arv_pertence(No* arvore, char info);
char arv_altura(No* arvore);

int main() {
    No* arvore = no_cria('a',
                    No_cria('b',
                        No_criavazia(),
                        No_cria('d',No_criavazia(),No_criavazia())
                    ),
                    No_cria('c',
                        No_cria('e',No_criavazia(),No_criavazia()),
                        No_cria('f',No_criavazia(),No_criavazia())
                    )   
                );
}


No* No_criavazia(void) {
    return NULL;
}

No* No_cria(char info, No* sae, No* sad) {
    No* nova_No = (No*)malloc(sizeof(No));
    nova_No->info = info;
    nova_No->sae = sae;  
    nova_No->sad = sad;
    return nova_No;

}

// OBSERVAÇÃO: ORDEM DE PERCURSO EM ARVORES BINARIAS 
// PRE ORDEM: RAIZ , SAE , SAD
// ORDEM SIMETRICA: SAE , RAIZ , SAD
// POS ORDEM: SAE , SAD , RAIZ

No* arv_imprime(No* arvore) {
    if(arvore != NULL) {
        printf("%c",arvore->info);
        arv_imprime(arvore->sae);
        arv_imprime(arvore->sad);
    }
}
/*      
void arv_imprime(No* arvore) {x'
    if (!arv_vazia(arvore))
    printf("%c",nova_no->info);
    arv_imprime(nova_no->sae);
    arv_imprime(nova_no->sad4);
}
*/
No* arv_libera(No* arvore) {
    if(arvore != NULL) {
        arv_libera(arvore->sae);
        arv_libera(arvore->sad);
        free(arvore);
    }
}

char arv_pertence(No* arvore, char info) {
    if(arvore == NULL) {
        printf("Arvore esta vazia");
        return 0;
    }
    else {
        return arvore->info = info || arv_pertence(arvore->sae,info) || arv_pertence(arvore->sad,info);
    }
}

/*      FUNÇÃO PERTENCE NA GAMBIARRA



*/

char arv_altura(No* arvore) {
    if (arvore ==  NULL) {
        return -1;
    }
    else {
        return 1 + max2(arv_altura(arvore->sad),arv_altura(arvore->sad));
    }
}