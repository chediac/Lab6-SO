#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};

typedef struct reg celula;

celula* cria_celula(int valor) {
    celula *nova = (celula*)malloc(sizeof(celula));
    if (nova == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->conteudo = valor;
    nova->prox = NULL;
    return nova;
}

void imprime_lista(const celula *cabeca) {
    printf("Valores na lista: ");
    for (const celula *atual = cabeca; atual != NULL; atual = atual->prox) {
        printf("%d -> ", atual->conteudo);
    }
    printf("NULL\n");
}

void remove_lista(celula **cabeca) {
    while (*cabeca != NULL) {
        celula *temp = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(temp);
    }
}

int main() {
    celula *cabeca = cria_celula(10);
    cabeca->prox = cria_celula(20);
    cabeca->prox->prox = cria_celula(30);

    imprime_lista(cabeca);
    printf("Tamanho de cada célula: %lu bytes\n", sizeof(celula));

    remove_lista(&cabeca);
    printf("Lista removida e memória liberada.\n");

    long long memoria_disponivel = 1073741824; 
    long long max_elementos = memoria_disponivel / sizeof(celula);
    printf("Máximo de elementos com 1 GB de memória: %lld\n", max_elementos);

    return 0;
}
