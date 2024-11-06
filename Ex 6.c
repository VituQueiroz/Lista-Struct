#include <stdio.h>

typedef struct {
    char nome[100];
    float preco;
} Produto;

int main() {
    Produto produtos[5];
    float preco_total = 0.0;

    for (int i = 0; i < 5; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
        getchar();
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("Produto %d:\tNome: %s\tPreço: %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
        preco_total += produtos[i].preco;
    }

    printf("\nPreço Total: %.2f\n", preco_total);

    return 0;
}

