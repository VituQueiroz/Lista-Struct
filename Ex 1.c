#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    float altura;
} Pessoa;

int main() {

    Pessoa pessoa;

    printf("Nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

    printf("Idade: ");
    scanf("%d", &pessoa.idade);

    printf("Altura: ");
    scanf("%f", &pessoa.altura);

    printf("\nNome: %s", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Altura: %.2f\n", pessoa.altura);

    if (pessoa.idade >= 18) {
        printf("Maior de idade: Sim\n");
    } else {
        printf("Maior de idade: Não\n");
    }

    return 0;
}
