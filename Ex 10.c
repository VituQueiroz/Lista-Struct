#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
} Livro;

void ler_livros(Livro livros[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Livro %d:\n", i + 1);

        printf("Título: ");
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

        printf("Autor: ");
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

        printf("Ano de Publicação: ");
        scanf("%d", &livros[i].ano_publicacao);
        getchar();
    }
}

void ordenar_livros_por_titulo(Livro livros[], int n) {
    Livro temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(livros[i].titulo, livros[j].titulo) > 0) {
                temp = livros[i];
                livros[i] = livros[j];
                livros[j] = temp;
            }
        }
    }
}

void imprimir_livros(Livro livros[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano de Publicação: %d\n", livros[i].ano_publicacao);
        printf("\n");
    }
}

int main() {
    int n = 3;
    Livro livros[n];

    ler_livros(livros, n);
    ordenar_livros_por_titulo(livros, n);

    printf("Livros em ordem alfabética pelo título:\n");
    imprimir_livros(livros, n);

    return 0;
}
