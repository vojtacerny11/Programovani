#include <stdio.h>
#include <stdlib.h>

// Definice rozmìrù hracího pole
#define ROWS 10
#define COLS 20

// Definice smìrù pohybu hada
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

// Funkce pro výpis hracího pole
void printBoard(char board[ROWS][COLS]) {
    system("cls");  // Vymaže konzoli
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS];  // Hrací pole
    int headRow = ROWS / 2;  // Poèáteèní pozice hlavy hada
    int headCol = COLS / 2;
    char direction = RIGHT;  // Poèáteèní smìr pohybu hada

    // Inicializace hracího pole
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // Inicializace hada na hracím poli
    board[headRow][headCol] = 'O';

    // Hlavní smyèka hry
    while (1) {
        printBoard(board);  // Výpis hracího pole

        // Ètení vstupu pro zmìnu smìru hada
        char input = getchar();
        if (input == 'q') {
            break;  // Konec hry
        }

        // Aktualizace pozice hada podle smìru
        switch (input) {
        case UP:
            headRow--;
            break;
        case DOWN:
            headRow++;
            break;
        case LEFT:
            headCol--;
            break;
        case RIGHT:
            headCol++;
            break;
        }

        // Kontrola kolize s okrajem hracího pole
        if (headRow < 0 || headRow >= ROWS || headCol < 0 || headCol >= COLS) {
            printf("Game Over - Hra skoncila! Narazil jsi do zdi.\n");
            break;
        }

        // Aktualizace pozice hlavy hada na hracím poli
        board[headRow][headCol] = 'O';

        // Pauza pro lepší sledování hry
        // Sleep(100);
    }

    return 0;
}