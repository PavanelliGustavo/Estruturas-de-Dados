#include<stdio.h>
#include<stdlib.h>

typedef struct NO {
    struct NO* prox;
    struct NO* anterior;
    int numeracao;
} NO;

typedef struct lista {
    NO* inicio;
    NO* final;
    int tamanho;
} lista;

void add(lista* l, int numero) {
    NO* v0 = malloc(sizeof(NO));
    v0->numeracao = numero;
    if(l->tamanho == 0) {
        l->inicio = v0;
        l->final = v0;
    }
    else {
        l->inicio->anterior = v0;
        v0->prox = l->inicio;
        l->inicio = v0;
    }
    l->tamanho++;
}

void remover(lista* l) {
    if(l->tamanho == 1) {
        l->inicio = NULL;
        l->final = NULL;
        free(l->inicio);
    }
    else if(l->tamanho > 1) {
        l->inicio = l->inicio->prox;
        free(l->inicio->anterior);
    }
    l->tamanho--;
}

int main() {
    lista* l = malloc(sizeof(lista));
    l->inicio = NULL;
    l->final = NULL;
    l->tamanho = 0;

    for(int i=0; i<99; i++) {
        add(l, 0);
    }
    
    int q, n, x;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%d", &n);
        if(n == 1) {
            scanf("%d", &x);
            add(l, x);
        }
        else {
            printf("%d\n", l->inicio->numeracao);
            remover(l);
        }
    }
}
