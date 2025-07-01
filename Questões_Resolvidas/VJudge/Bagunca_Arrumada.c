#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no* esq;
  struct no* dir;
}No;

typedef struct arvore {
  No* raiz;
  int tamanho;
}ArvoreBB;

No* busca_folha(No* no_remover);

ArvoreBB* cria_arvore() {
  ArvoreBB* abb = malloc(sizeof(ArvoreBB));
  if (abb == NULL) {
    return NULL;
  }
  abb->raiz = NULL;
  abb->tamanho = 0;
  return abb;
}

void insere_elemento(int valor, ArvoreBB* arvore) {
  No* novoNo = malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("Erro na alocacao de memoria\n");
    return;
  }
  novoNo->valor = valor;
  novoNo->esq = NULL;
  novoNo->dir = NULL;

  if (arvore->tamanho == 0) {
    arvore->raiz = novoNo;
  } else {
    No* pai = arvore->raiz;
    int nao_achei = 1;
    while (nao_achei) {
      if (valor < pai->valor) {
        if (pai->esq == NULL) {
          nao_achei = 0;
          pai->esq = novoNo;
        }
        pai = pai->esq;
      } else{
        if (pai->dir == NULL) {
          nao_achei = 0;
          pai->dir = novoNo;
        }
        pai = pai->dir;
      }
    }
  }
  arvore->tamanho++;
}

void imprime_arvore_pos_order(No* elemento) {
  if (elemento != NULL) {
    imprime_arvore_pos_order(elemento->esq);
    imprime_arvore_pos_order(elemento->dir);
    printf("%d ", elemento->valor);
  }
}

int main() {

    int n, a;
    scanf("%d", &n);

    ArvoreBB* arvore = cria_arvore();

    for(int i=0; i<n; i++) {
        scanf("%d", &a);
        insere_elemento(a, arvore);
    }

    imprime_arvore_pos_order(arvore->raiz);

    return 0;
}
