#include <stdio.h>

typedef struct {
    char nome[100];
    float preco;
} Produto;

int main() {
    Produto produto1, produto2;

    printf("Produto 1: Nome: ");
    fgets(produto1.nome, sizeof(produto1.nome), stdin);
    printf("Preço: ");
    scanf("%f", &produto1.preco);

    getchar();

    printf("Produto 2: Nome: ");
    fgets(produto2.nome, sizeof(produto2.nome), stdin);
    printf("Preço: ");
    scanf("%f", &produto2.preco);

    float preco_total = produto1.preco + produto2.preco;

    printf("\nProduto 1: Nome: %sPreço: %.2f\n", produto1.nome, produto1.preco);
    printf("Produto 2: Nome: %sPreço: %.2f\n", produto2.nome, produto2.preco);
    printf("Preço Total: %.2f\n", preco_total);

    return 0;
}

