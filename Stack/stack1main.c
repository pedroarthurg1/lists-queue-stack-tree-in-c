#include <stdio.h>
#include <stdlib.h>
#include "stack1/stack1.h"

int main() {
    // Cria a pilha
    Pilha* p = pilha_cria();

    // Empilha alguns valores (float)
    pilha_push(p, 10.5);
    pilha_push(p, 20.2);
    pilha_push(p, 30.0);
    pilha_push(p, 45.7);

    printf("Pilha apos insercoes:\n");
    pilha_imprime(p);
    printf("\n");

    // Remove (pop) o elemento do topo
    float removido = pilha_pop(p);
    printf("Elemento removido: %f\n\n", removido);

    printf("Pilha apos remocao:\n");
    pilha_imprime(p);
    printf("\n");

    // Verifica se esta vazia
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("A pilha nao esta vazia.\n");
    }

    // Libera a memoria
    pilha_libera(p);

    return 0;
}