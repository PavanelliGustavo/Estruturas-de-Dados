/*  Este programa tem como finalidade simular a brincadeira batata quente
    No nosso caso, temos as crianças a, b, c, d, e brincando e queremos ver
    quem vai ganhar dado os números escolhidos.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct NO {
    struct NO* prox;
    struct NO* anterior;
    char nome;
} NO; 

typedef struct lista {
    NO* inicio;
    NO* final;
    int tamanho;
} lista;

void add(lista* l, char crianca) {
    NO* v0 = malloc(sizeof(NO));
    v0->nome = crianca;
    if(l->tamanho == 0) {
        l->inicio = v0;
        l->final = v0;
        l->final->prox = l->inicio;
        l->inicio->anterior = l->final;
    }
    else {
        l->inicio->anterior = v0;
        v0->prox = l->inicio;
        v0->anterior = l->final;
        l->final->prox = v0;
        l->inicio = v0;
    }
    l->tamanho++;
}

void remover(lista* l, char crianca) {
    NO* v0 = l->inicio;
    while(v0->nome != crianca) {
        v0 = v0->prox;
    }
    v0->anterior->prox = v0->prox;
    v0->prox->anterior = v0->anterior;
    free(v0);
    l->tamanho--;
}

int main() {
    lista* l = malloc(sizeof(lista));
    l->inicio = NULL;
    l->final = NULL;
    l->tamanho = 0;

    int n, contador;

    add(l, 'a');
    add(l, 'b');
    add(l, 'c');
    add(l, 'd');
    add(l, 'e');

    NO* atual = l->inicio;

    for(int i=0; i<4; i++) {
        printf("Escolha um número\n");
        scanf("%d", &n);
        contador = 0;
        while(contador < n) {
            printf("%c\n", atual->nome);
            atual = atual->prox;
            printf("%d\n", contador);
            contador++;
        }
        printf("%c se queimou!\n", atual->nome);
        atual = atual->prox;
        remover(l, atual->anterior->nome);
    }
    printf("%c ganhou!\n", l->inicio->nome);
}
