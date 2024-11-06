#include <stdio.h>

typedef struct {
    char nome[100];
    int numeroQuarto;
    int checkinDia;
    int checkinMes;
    int checkinAno;
    int checkoutDia;
    int checkoutMes;
    int checkoutAno;
} Reserva;

int calcularDuracao(int checkinDia, int checkinMes, int checkinAno, int checkoutDia, int checkoutMes, int checkoutAno) {

    int duracao = 0;

    duracao += (checkoutAno - checkinAno) * 31 * 12;

    duracao += (checkoutMes - checkinMes) * 31;

    duracao += checkoutDia - checkinDia;

    return duracao;
}

void lerReserva(Reserva *reserva) {
    printf("Nome: ");
    fgets(reserva->nome, sizeof(reserva->nome), stdin);
    reserva->nome[strcspn(reserva->nome, "\n")] = 0;

    printf("Número do Quarto: ");
    scanf("%d", &reserva->numeroQuarto);

    printf("Check-in (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &reserva->checkinDia, &reserva->checkinMes, &reserva->checkinAno);

    printf("Check-out (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &reserva->checkoutDia, &reserva->checkoutMes, &reserva->checkoutAno);

    getchar();
}

void imprimirReserva(Reserva reserva) {
    int duracao = calcularDuracao(reserva.checkinDia, reserva.checkinMes, reserva.checkinAno,
                                   reserva.checkoutDia, reserva.checkoutMes, reserva.checkoutAno);

    printf("Reserva: Nome: %s\n", reserva.nome);
    printf("Número do Quarto: %d\n", reserva.numeroQuarto);
    printf("Check-in: %02d/%02d/%d\n", reserva.checkinDia, reserva.checkinMes, reserva.checkinAno);
    printf("Check-out: %02d/%02d/%d\n", reserva.checkoutDia, reserva.checkoutMes, reserva.checkoutAno);
    printf("Duração: %d dias\n", duracao);
}

int main() {
    Reserva reservas[3];

    for (int i = 0; i < 3; i++) {
        printf("Reserva %d:\n", i + 1);
        lerReserva(&reservas[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("\nReserva %d:\n", i + 1);
        imprimirReserva(reservas[i]);
    }

    return 0;
}
