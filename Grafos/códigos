#include<stdio.h>
#include<stdlib.h>

struct grafo {
    int eh_ponderado;
    int grau_max;
    int n_vertices;
    int** arestas;
    float** pesos;
    int* grau;
    struct lista** adjacentes;
};

typedef struct NO {
    int numeracao;
    struct NO* prox;
} NO;

typedef struct lista {
    int n;
    struct NO* cabeca;
    struct NO* final;
} lista;

void cria_grafo(int n_vertices) {
    struct grafo* grafo = malloc(sizeof(struct grafo));
    struct lista** adjacentes = malloc(sizeof(lista)*n_vertices);
    for(int i=0; i<n_vertices; i++) {
        adjacentes[i]->n = 0;
        adjacentes[i]->cabeca = NULL;
    }
    grafo->adjacentes = adjacentes;
}

void adiciona_aresta(struct grafo* grafo, int n, int m) {
    add(grafo->adjacentes[n], m);
}

void add(struct lista* lista, int n) {
    
}

void libera_grafo(struct grafo* grafo) {
    for(int i=0; i<grafo->n_vertices; i++) {
        libera_lista(grafo->adjacentes[i]);
    }
    free(grafo);
}

void libera_lista() {
    
}

imprime_grafo

int main() {

}
