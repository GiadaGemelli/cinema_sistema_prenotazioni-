#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10
#define MOVIES 5

// Struttura per memorizzare informazioni su uno spettacolo
typedef struct {
    char title[50];
    int seats[ROWS][COLS]; // 0 = libero, 1 = prenotato
} Movie;

Movie cinema[MOVIES];

// Funzione per inizializzare i film e i posti a sedere
void initializeCinema() {
    strcpy(cinema[0].title, "Inception");
    strcpy(cinema[1].title, "The Matrix");
    strcpy(cinema[2].title, "Interstellar");
    strcpy(cinema[3].title, "Avatar");
    strcpy(cinema[4].title, "Titanic");

    for (int m = 0; m < MOVIES; m++) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cinema[m].seats[i][j] = 0; // Tutti i posti liberi
            }
        }
    }
}

// Funzione per mostrare lo stato dei posti a sedere
void displaySeats(int movieIndex) {
    printf("\nPosti per '%s':\n", cinema[movieIndex].title);
    printf("   ");
    for (int i = 0; i < COLS; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (cinema[movieIndex].seats[i][j] == 0)
                printf("[ ] ");
            else
                printf("[X] ");
        }
        printf("\n");
    }
}

// Funzione per prenotare un posto
void bookSeat(int movieIndex) {
    int row, col;
    displaySeats(movieIndex);

    printf("\nInserisci riga e colonna (es. 3 4): ");
    scanf("%d %d", &row, &col);

    if (row >= 1 && row <= ROWS &&
        col >= 1 && col <= COLS &&
        cinema[movieIndex].seats[row - 1][col - 1] == 0) {

        cinema[movieIndex].seats[row - 1][col - 1] = 1;
        printf("Posto prenotato con successo!\n");
    } else {
        printf("Posto non valido o già prenotato!\n");
    }
}

// Funzione per cancellare una prenotazione
void cancelBooking(int movieIndex) {
    int row, col;
    displaySeats(movieIndex);

    printf("\nInserisci riga e colonna da cancellare (es. 3 4): ");
    scanf("%d %d", &row, &col);

    if (row >= 1 && row <= ROWS &&
        col >= 1 && col <= COLS &&
        cinema[movieIndex].seats[row - 1][col - 1] == 1) {

        cinema[movieIndex].seats[row - 1][col - 1] = 0;
        printf("Prenotazione cancellata con successo!\n");
    } else {
        printf("Posto non valido o già libero!\n");
    }
}

int main() {
    int choice, movieIndex;

    initializeCinema();

    do {
        printf("\n--- Sistema di Prenotazione Cinema ---\n");
        printf("Scegli uno spettacolo:\n");

        for (int i = 0; i < MOVIES; i++) {
            printf("%d. %s\n", i + 1, cinema[i].title);
        }
        printf("%d. Esci\n", MOVIES + 1);

        printf("Scelta: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= MOVIES) {
            movieIndex = choice - 1;

            printf("\n1. Visualizza posti\n");
            printf("2. Prenota un posto\n");
            printf("3. Cancella prenotazione\n");
            printf("4. Torna al menu principale\n");
            printf("Scelta: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    displaySeats(movieIndex);
                    break;
                case 2:
                    bookSeat(movieIndex);
                    break;
                case 3:
                    cancelBooking(movieIndex);
                    break;
                case 4:
                    break;
                default:
                    printf("Scelta non valida!\n");
            }
        } else if (choice != MOVIES + 1) {
            printf("Scelta non valida!\n");
        }

    } while (choice != MOVIES + 1);

    printf("\nGrazie per aver utilizzato il sistema di prenotazione!\n");
    return 0;
}
