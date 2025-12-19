#include "TADEXERCICIOSAULA15/TAD_EXERCICIOSAULA15.h"

int main() {
    Lista* l = lst_cria();

    l = lst_insere(l, 10);
    l = lst_insere(l, 20);
    l = lst_insere(l, 30);

    lst_imprime(l);
    printf("\n");

    l = lst_insere_fim(l, 40);
    l = lst_insere_fim(l, 50);

    lst_imprime(l);
    printf("\n");

    l = lst_insere_ordenado(l, 25);
    l = lst_insere_ordenado(l, 5);

    lst_imprime(l);
    printf("\n");

    printf("%d\n", lst_tamanho(l));

    if (lst_vazia(l)) {
        printf("Vazia\n");
    } else {
        printf("Nao Vazia\n");
    }

    l = lst_remove(l, 20);
    l = lst_remove(l, 50);

    lst_imprime(l);
    printf("\n");

    lst_libera(l);

    return 0;
}