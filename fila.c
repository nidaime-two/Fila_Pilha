#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int itens[MAX_SIZE];
    int frente, traseira;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->traseira = -1; // aqui inicia a fila
}

int vazia(Fila *fila) {
    return (fila->frente == -1);
}

int cheia(Fila *fila) {
    return (fila->traseira == MAX_SIZE - 1);
}

void enfileirar(Fila *fila, int valor) {
    if (!cheia(fila)) {
        if (vazia(fila)) {
            fila->frente = 0;
        }
        fila->itens[++fila->traseira] = valor;
        printf("Enfileirado o elemento: %d\n", valor);
    } else {
        printf("Fila cheia, não é possível enfileirar o elemento %d.\n", valor);
    }
}


int desenfileirar(Fila *fila) {
    if (!vazia(fila)) {
        int item = fila->itens[fila->frente];
        if (fila->frente == fila->traseira) {
            fila->frente = fila->traseira = -1;
        } else {
            fila->frente++;
        }
        printf("Desenfileirado o elemento: %d\n", item);
        return item;
    } else {
        printf("Fila vazia, não é possível desenfileirar nada.\n");
        return -1;
    }
}

void exibir(Fila *fila) {
    if (!vazia(fila)) {
        printf("Elementos da fila (da frente para a traseira): ");
        for (int i = fila->frente; i <= fila->traseira; i++) {
            printf("%d ", fila->itens[i]); // Exibindo os elementos da fila
        }
        printf("\n");
    } else {
        printf("Fila vazia, nada para exibir.\n");
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Enfileiramento 
    printf("Enfileirando os elementos de 1 a 4:\n");
    for (int i = 1; i <= 4; i++) {
        enfileirar(&fila, i);
    }

    // Desenfileiramento
    printf("\nDesenfileirando os elementos:\n");
    while (!vazia(&fila)) {
        desenfileirar(&fila);
    }

    return 0;
}
