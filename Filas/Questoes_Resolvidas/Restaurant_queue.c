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

void addfinal(lista* l, int numero) {
    NO* v0 = malloc(sizeof(NO));
    v0->numeracao = numero;
    if(l->tamanho == 0) {
        l->inicio = v0;
        l->final = v0;
    }
    else {
        l->final->prox = v0;
        v0->anterior = l->final;
        l->final = v0;
    }
    l->tamanho++;
}

void remover(lista* l) {
    if(l->tamanho > 1) {
        l->inicio = l->inicio->prox;
        free(l->inicio->anterior);
    }
    if(l->tamanho == 1) {
        l->inicio = NULL;
        l->final = NULL;
        free(l->inicio->anterior);
    }
    l->tamanho--;
}

int main() {
    int q, op, n;
    scanf("%d", &q);
    lista* l = malloc(sizeof(lista));

    for(int i=0; i<q; i++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d", &n);
            addfinal(l, n);
        }
        else {
            printf("%d\n", l->inicio->numeracao);
            remover(l);
        }
    }
}
