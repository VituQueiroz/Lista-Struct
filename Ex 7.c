#include <stdio.h>

typedef struct {
    char nome[100];
    float notas[3];
} Aluno;

void lerAluno(Aluno *aluno) {
    printf("Nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    printf("Nota 1: ");
    scanf("%f", &aluno->notas[0]);
    printf("Nota 2: ");
    scanf("%f", &aluno->notas[1]);
    printf("Nota 3: ");
    scanf("%f", &aluno->notas[2]);
    getchar();
}

float calcularMedia(Aluno *aluno) {
    return (aluno->notas[0] + aluno->notas[1] + aluno->notas[2]) / 3;
}

void imprimirAluno(Aluno aluno) {
    float media = calcularMedia(&aluno);
    printf("Nome: %sMedia: %.2f\n", aluno.nome, media);
}

int main() {
    Aluno alunos[3];

    for (int i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        lerAluno(&alunos[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: ", i + 1);
        imprimirAluno(alunos[i]);
    }

    return 0;
}

