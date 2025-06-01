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

lista* queue() {
    lista* n0 = malloc(sizeof(lista));
    n0->tamanho = 0;
    n0->inicio = NULL;
    n0->final = NULL;
    return n0;
}

void enqueue(lista* l, int numeracao) {
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

void dequeue(lista* l) {
    if(l->tamanho == 1) {
            l->inicio = NULL;
            l->final = NULL;
            free(l->inicio);
    }
    else if(l->tamanho > 1){
        l->inicio = l->inicio->prox;
        free(l->inicio->anterior);
    }
    l->tamanho--;
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

int size(lista* l) {
    return l->tamanho;
}

NO* front(lista* l) {
    return l->inicio;
}

int isEmpty(lista* l) {
    return l->tamanho == 0;
}

int main() {
    lista* m0 = malloc(sizeof(lista));
    m0->tamanho = 0;
    m0->inicio = NULL;
    m0->final = NULL;
}
