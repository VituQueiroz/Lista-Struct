#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data data_nascimento;
} Pessoa;

int main() {
    Pessoa pessoa;
    int dia_atual = 5, mes_atual = 11, ano_atual = 2024;

    printf("Nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &pessoa.data_nascimento.dia, &pessoa.data_nascimento.mes, &pessoa.data_nascimento.ano);

    int idade = ano_atual - pessoa.data_nascimento.ano;

    if (mes_atual < pessoa.data_nascimento.mes || (mes_atual == pessoa.data_nascimento.mes && dia_atual < pessoa.data_nascimento.dia)) {
        idade--;
    }

    printf("\nNome: %s", pessoa.nome);
    printf("Data de Nascimento: %02d/%02d/%d\n", pessoa.data_nascimento.dia, pessoa.data_nascimento.mes, pessoa.data_nascimento.ano);
    printf("Idade: %d\n", idade);

    return 0;
}

