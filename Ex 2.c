#include <stdio.h>
#include <time.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publi;
} Livro;

int main() {

    Livro livro;

    int ano_atual = 2024;

    printf("Título: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);

    printf("Autor: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);

    printf("Ano de Publicação: ");
    scanf("%d", &livro.ano_publi);

    int idade_livro = ano_atual - livro.ano_publi;

    printf("\nTítulo: %s", livro.titulo);
    printf("Autor: %s", livro.autor);
    printf("Ano de Publicação: %d\n", livro.ano_publi);
    printf("Idade do Livro: %d anos\n", idade_livro);

    return 0;
}
