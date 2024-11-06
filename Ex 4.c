#include <stdio.h>

typedef struct {
    char modelo[100];
    int ano_fabricacao;
    int quilometragem;
} Carro;

int main() {
    Carro carro;
    int ano_atual = 2024;

    printf("Modelo: ");
    fgets(carro.modelo, sizeof(carro.modelo), stdin);
    printf("Ano de Fabricação: ");
    scanf("%d", &carro.ano_fabricacao);
    printf("Quilometragem: ");
    scanf("%d", &carro.quilometragem);

    int idade_carro = ano_atual - carro.ano_fabricacao;

    printf("\nModelo: %s", carro.modelo);
    printf("Ano de Fabricação: %d\n", carro.ano_fabricacao);
    printf("Quilometragem: %d\n", carro.quilometragem);
    printf("Idade do Carro: %d anos\n", idade_carro);

    return 0;
}

