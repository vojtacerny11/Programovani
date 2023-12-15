#include <stdio.h>
#include <stdlib.h>

// Definice rozm�r� hrac�ho pole
#define ROWS 10
#define COLS 20

// Definice sm�r� pohybu hada
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

// Funkce pro v�pis hrac�ho pole
void printBoard(char board[ROWS][COLS]) {
    system("cls");  // Vyma�e konzoli
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS];  // Hrac� pole
    int headRow = ROWS / 2;  // Po��te�n� pozice hlavy hada
    int headCol = COLS / 2;
    char direction = RIGHT;  // Po��te�n� sm�r pohybu hada

    // Inicializace hrac�ho pole
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // Inicializace hada na hrac�m poli
    board[headRow][headCol] = 'O';

    // Hlavn� smy�ka hry
    while (1) {
        printBoard(board);  // V�pis hrac�ho pole

        // �ten� vstupu pro zm�nu sm�ru hada
        char input = getchar();
        if (input == 'q') {
            break;  // Konec hry
        }

        // Aktualizace pozice hada podle sm�ru
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

        // Kontrola kolize s okrajem hrac�ho pole
        if (headRow < 0 || headRow >= ROWS || headCol < 0 || headCol >= COLS) {
            printf("Game Over - Hra skoncila! Narazil jsi do zdi.\n");
            break;
        }

        // Aktualizace pozice hlavy hada na hrac�m poli
        board[headRow][headCol] = 'O';

        // Pauza pro lep�� sledov�n� hry
        // Sleep(100);
    }

    return 0;
}