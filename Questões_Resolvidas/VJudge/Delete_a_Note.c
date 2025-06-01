#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200000
    
typedef struct numero {
    int numeracao;
    struct numero* prox;
    struct numero* anterior;
} numero;

typedef struct lista {
    numero* inicio;
    numero* final;
    int tamanho;
} lista;

void addfinal(lista* l, int numeracao) {
    numero* a = malloc(sizeof(numero));
    a->numeracao = numeracao;
    if(l->tamanho != 0) {
        a->anterior = l->final;
        l->final->prox = a;
        l->final= a;
    }
    else {
        l->inicio = a;
        l->final = a;
    }
    l->tamanho++;
}

void remover(lista* l, int numeracao) {
    if(l->tamanho == 1) {
        l->inicio = NULL;
        l->final = NULL;
        free(l->inicio);
    }
    else if(l->tamanho > 1) {
        numero* atual = l->inicio;
        int i = 0;
        while (i<=numeracao) {
            atual = atual->prox;
            i++;
        }
        atual->anterior->prox = atual->prox;
        atual->prox->anterior = atual->anterior;
        free(atual);
    }
    l->tamanho--;
}

void printar(lista* l) {
    numero* atual = l->inicio;
    for(int i = 0; i<l->tamanho; i++) {
        printf("%d ", atual->numeracao);
        atual = atual->prox;
    }
}

int main() {
    lista* quest = malloc(sizeof(lista));
    quest->tamanho = 0;
    quest->inicio = NULL;
    quest->final = NULL;
    
    int n, i, a;
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &a);
        addfinal(quest, a);
    }

    printar(quest);
    
    scanf("%d", &a);
    remover(quest, a);
    
    printar(quest);
}
