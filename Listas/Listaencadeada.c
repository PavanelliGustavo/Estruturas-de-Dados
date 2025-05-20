#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int numeracao;
    char passageiro;
    struct NO* prox;
    struct NO* anterior;
} vagao;

typedef struct Lista{
    vagao* inicio;
    vagao* final;
    int tamanho;
} metro;

void add(metro* l, int numeracao, char passageiro) {
    vagao* v0 = malloc(sizeof(vagao));
    v0->numeracao = numeracao;
    v0->passageiro = passageiro;
    v0->prox = l->inicio;
    v0->anterior = l->final;
    l->inicio = v0;
    l->tamanho++;
}

void addfinal(metro* l, int numeracao, char passageiro) {
    vagao* v0 = malloc(sizeof(vagao));
    v0->numeracao = numeracao;
    v0->passageiro = passageiro;
    if(l->tamanho != 0) {
        l->final->prox = v0;
        v0->anterior = l->final;
        l->final = v0;
        l->final->prox = l->inicio;
    }
    else {
        l->inicio = v0;
        l->final = l->inicio;
        v0->anterior = v0;
        l->final->prox = l->inicio;
    }
    l->tamanho++;
}

void remove(metro* l, int numeracao) {
    if(l->tamanho != 0) {
        vagao* atual = l->inicio;
        int contador = 0;
        while(contador != numeracao) {
            atual = atual->prox;
            contador++;
        }
        atual->anterior->prox = atual->prox;
        atual->prox->anterior = atual->anterior;
        l->tamanho--;
        free(atual);
    }
}

void printar(metro* l) {
    vagao* atual = l->inicio;
    while(atual->prox != l->final) {
        printf("numeracao vagao = %d e passageiro vagao = %c\n", atual->numeracao, atual->passageiro);
        atual = atual->prox;
    }
}

int main() {
    metro m0;
    m0.tamanho = 0;
    m0.inicio = NULL;
    m0.final = m0.inicio;
    add(&m0, 0, 'a');
    add(&m0, 1, 'b');
    printar(&m0);
    add(&m0, 2, 'c');
    addfinal(&m0, 3, 'd');
    add(&m0, 4, 'e');
    remove(&m0, 2);
}
