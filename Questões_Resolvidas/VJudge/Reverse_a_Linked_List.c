#include<stdio.h>
#include<stdlib.h>

typedef struct NO {
    int numero;
    struct NO* prox;
    struct NO* anterior;
} NO;

typedef struct lista {
    NO* inicio;
    NO* final;
    int tamanho;
} lista;

void add(lista* l, int numero) {
    NO* v0 = malloc(sizeof(NO));
    v0->numero = numero;
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

void printar(lista* l) {
    NO* atual = l->inicio;
    for(int i=0; i<l->tamanho; i++) {
        printf("%d ", atual->numero);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {

    int t, n, a;
    scanf("%d", &t);
    lista* l = malloc(sizeof(lista));
    l->inicio = NULL;
    l->final = NULL;
    l->tamanho = 0;

    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        for(int j=0; j<n; j++) {
            scanf("%d", &a);
            add(l, a);
        }
        printar(l);
        l->inicio = NULL;
        l->final = NULL;
        l->tamanho = 0;
    }

    return 0;
}
