#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100 // Define a capacidade máxima de pessoas na agenda

// Estruturas de dados para armazenar as informações da agenda
typedef struct {
    char rua[100];
    int numero;
    char complemento[50];
    char bairro[50];
    char cep[15];
    char cidade[50];
    char estado[50];
    char pais[50];
} Endereco;

typedef struct {
    int ddd;
    char numero[15];
} Telefone;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    char email[100];
    Endereco endereco;
    Telefone telefone;
    Data aniversario;
    char observacoes[200];
} Pessoa;

// Variáveis globais
Pessoa agenda[MAX];
int total_pessoas = 0;

// Funções do sistema
void inserir_pessoa();
void remover_pessoa();
void buscar_por_nome();
void buscar_por_mes();
void imprimir_agenda();
void menu();

int main() {
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

// Função para inserir uma nova pessoa na agenda
void inserir_pessoa() {
    if (total_pessoas >= MAX) {
        printf("Agenda cheia!\n");
        return;
    }

    Pessoa p;

    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strlen(p.nome) - 1] = '\0';

    printf("Digite o email: ");
    fgets(p.email, 100, stdin);
    p.email[strlen(p.email) - 1] = '\0';

    printf("Digite o endereço:\n");
    printf("  Rua: ");
    fgets(p.endereco.rua, 100, stdin);
    p.endereco.rua[strlen(p.endereco.rua) - 1] = '\0';

    printf("  Número: ");
    scanf("%d", &p.endereco.numero);
    getchar(); // Limpa o buffer de entrada

    printf("  Complemento: ");
    fgets(p.endereco.complemento, 50, stdin);
    p.endereco.complemento[strlen(p.endereco.complemento) - 1] = '\0';

    printf("  Bairro: ");
    fgets(p.endereco.bairro, 50, stdin);
    p.endereco.bairro[strlen(p.endereco.bairro) - 1] = '\0';

    printf("  CEP: ");
    fgets(p.endereco.cep, 15, stdin);
    p.endereco.cep[strlen(p.endereco.cep) - 1] = '\0';

    printf("  Cidade: ");
    fgets(p.endereco.cidade, 50, stdin);
    p.endereco.cidade[strlen(p.endereco.cidade) - 1] = '\0';

    printf("  Estado: ");
    fgets(p.endereco.estado, 50, stdin);
    p.endereco.estado[strlen(p.endereco.estado) - 1] = '\0';

    printf("  País: ");
    fgets(p.endereco.pais, 50, stdin);
    p.endereco.pais[strlen(p.endereco.pais) - 1] = '\0';

    printf("Digite o telefone (DDD e número separados por espaço): ");
    scanf("%d %s", &p.telefone.ddd, p.telefone.numero);
    getchar();

    printf("Digite a data de aniversário (dd mm aaaa): ");
    scanf("%d %d %d", &p.aniversario.dia, &p.aniversario.mes, &p.aniversario.ano);
    getchar();

    printf("Observações: ");
    fgets(p.observacoes, 200, stdin);
    p.observacoes[strlen(p.observacoes) - 1] = '\0';

    agenda[total_pessoas++] = p;
    printf("Pessoa inserida com sucesso!\n");
}

// Função para remover uma pessoa pelo nome
void remover_pessoa() {
    char nome[50];
    printf("Digite o nome da pessoa a ser removida: ");
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';

    int encontrado = 0;
    for (int i = 0; i < total_pessoas; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            for (int j = i; j < total_pessoas - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            total_pessoas--;
            encontrado = 1;
            printf("Pessoa removida com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Pessoa não encontrada!\n");
    }
}

// Função para buscar uma pessoa pelo primeiro nome
void buscar_por_nome() {
    char nome[50];
    printf("Digite o primeiro nome a ser buscado: ");
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';

    int encontrado = 0;
    for (int i = 0; i < total_pessoas; i++) {
        if (strstr(agenda[i].nome, nome) != NULL) {
            printf("\nNome: %s\nEmail: %s\nTelefone: (%d) %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de aniversário: %02d/%02d/%04d\nObservações: %s\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano, agenda[i].observacoes);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma pessoa encontrada com esse nome.\n");
    }
}

// Função para buscar pessoas pelo mês de aniversário
void buscar_por_mes() {
    int mes;
    printf("Digite o mês de aniversário a ser buscado: ");
    scanf("%d", &mes);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < total_pessoas; i++) {
        if (agenda[i].aniversario.mes == mes) {
            printf("\nNome: %s\nEmail: %s\nTelefone: (%d) %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de aniversário: %02d/%02d/%04d\nObservações: %s\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano, agenda[i].observacoes);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma pessoa encontrada com aniversário nesse mês.\n");
    }
}

// Função para imprimir a agenda
void imprimir_agenda() {
    if (total_pessoas == 0) {
        printf("Agenda vazia!\n");
        return;
    }
    for (int i = 0; i < total_pessoas; i++) {
        printf("\nNome: %s\nEmail: %s\nTelefone: (%d) %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone.ddd, agenda[i].telefone.numero);
        printf("Data de aniversário: %02d/%02d/%04d\nObservações: %s\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano, agenda[i].observacoes);
    }
}

// Função para exibir o menu
void menu() {
    int opcao;
    do {
        printf("\nAgenda Telefônica:\n");
        printf("1. Inserir Pessoa\n2. Remover Pessoa\n3. Buscar por Nome\n4. Buscar por Mês de Aniversário\n5. Imprimir Agenda\n6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1: inserir_pessoa(); break;
            case 2: remover_pessoa(); break;
            case 3: buscar_por_nome(); break;
            case 4: buscar_por_mes(); break;
            case 5: imprimir_agenda(); break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 6);
}
