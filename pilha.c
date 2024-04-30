#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int itens[MAX_SIZE];
    int topo; // indice do topo da pilha
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1; // Inicia o topo da pilha
}

int vazia(Pilha *pilha) {
    return (pilha->topo == -1); // Verifica se a pilha está vazia
}

int cheia(Pilha *pilha) {
    return (pilha->topo == MAX_SIZE - 1); // Verifica se a pilha está cheia
}

void empilhar(Pilha *pilha, int valor) {
    if (!cheia(pilha)) {
        pilha->itens[++pilha->topo] = valor;
        printf("Empilhado o elemento: %d\n", valor);
    } else {
        printf("Pilha cheia, não é possível empilhar o elemento %d.\n", valor);
    }
}

int desempilhar(Pilha *pilha) {
    if (!vazia(pilha)) {
        int item = pilha->itens[pilha->topo--];
        printf("Desempilhado o elemento: %d\n", item);
        return item;
    } else {
        printf("Pilha vazia, não é possível desempilhar nada.\n");
        return -1;
    }
}

void exibir(Pilha *pilha) {
    if (!vazia(pilha)) {
        printf("Elementos da pilha (do topo para a base): ");
        for (int i = pilha->topo; i >= 0; i--) {
            printf("%d ", pilha->itens[i]); // Exibindo os elementos da pilha
        }
        printf("\n");
    } else {
        printf("Pilha vazia, nada para exibir.\n");
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    // Empilhamento 
    printf("Empilhando os elementos de 1 a 4:\n");
    for (int i = 1; i <= 4; i++) {
        empilhar(&pilha, i);
    }

    // Desempilhamento
    printf("\nDesempilhando os elementos:\n");
    while (!vazia(&pilha)) {
        desempilhar(&pilha);
    }

    return 0;
}
