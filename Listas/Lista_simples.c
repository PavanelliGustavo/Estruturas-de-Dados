#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int numeracao;
    struct NO* prox;
    struct NO* anterior;
} NO;

typedef struct lista{
    NO* inicio;
    NO* final;
    int tamanho;
} lista;

void criar(char nome) {
    typedef struct NO2{
        int numeracao;
        struct NO2* prox;
        struct NO2* anterior;
    } NO2;

    typedef struct lista2{
        NO2* inicio;
        NO2* final;
        int tamanho;
    } lista2;

    lista2* m0 = malloc(sizeof(lista2));
    n0->tamanho = 0;
    n0->inicio = NULL;
    n0->final = NULL;
}

void add(lista* l, int numeracao) {
    NO* v0 = malloc(sizeof(NO));
    v0->numeracao = numeracao;
    if(l->tamanho != 0) {
        v0->prox = l->inicio;
        l->inicio->anterior = v0;
        l->inicio = v0;
    }
    else {
        l->inicio = v0;
        l->final = v0;
    }
    l->tamanho++;
}

void addfinal(lista* l, int numeracao) {
    NO* v0 = malloc(sizeof(NO));
    v0->numeracao = numeracao;
    if(l->tamanho != 0) {
        l->final->prox = v0;
        v0->anterior = l->final;
        l->final = v0;
    }
    else {
        l->inicio = v0;
        l->final = l->inicio;
    }
    l->tamanho++;
}

void remover(lista* l, int numeracao) {
    if(l->tamanho == 1) {
            l->inicio = NULL;
            l->final = NULL;
            l->tamanho--;
            free(l->inicio);
    }
    else if(l->tamanho > 1){
        NO* atual = l->inicio;
        while(atual->numeracao != numeracao) {
            atual = atual->prox;
        }
        atual->anterior->prox = atual->prox;
        atual->prox->anterior = atual->anterior;
        l->tamanho--;
        free(atual);
    }
}

void printar(lista* l) {
    NO* atual = l->inicio;
    int contador = 0;
    while(contador < l->tamanho) {
        printf("numeracao NO = %d\n", atual->numeracao);
        atual = atual->prox;
        contador++;
    }
}

void tamanho(lista* l) {
    printf("%d\n", l->tamanho);
}

int main() {
    lista* m0 = malloc(sizeof(lista));
    m0->tamanho = 0;
    m0->inicio = NULL;
    m0->final = NULL;
}
