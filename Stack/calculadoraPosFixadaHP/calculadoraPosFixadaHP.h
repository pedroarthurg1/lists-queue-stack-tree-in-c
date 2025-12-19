#ifndef __calculadora_Pos_Fixada_HP_H__
    #define __calculadora_Pos_Fixada_HP_H__

    typedef struct lista {
        float info;
        struct lista* prox;
    }Lista;

    typedef struct pilha {
        Lista* topo;
    }Pilha;

    typedef struct calc {
        char f[21];
        Pilha* p;
    }Calc;

    Calc* calc_cria(char* f);
    void calc_operando(Calc* c , float info);
    void calc_operador(Calc* c, char op);
    void calc_libera(Calc* c);
    Pilha* pilha_cria();

    #include "calculadoraPosFixadaHP.c"
#endif