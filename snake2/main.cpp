#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

int spawnCol;
int spawnRow;
int nRadek = 12;
int nSloupec = 12;
int score = 0;
char Had = '#';
char Jablko = 'o';
char Move = ' ';
char volnePole = ' ';
char hraciPlocha[15][15];
bool Konec = 0;
void resetPole();
void printBoard();
void moveHad();
void GameOver();
void jablkoSpawn();

int main()
{
	srand(time(0));
	while (1)
	{
		resetPole();
		jablkoSpawn();
		while (Konec != 1)
		{
			printBoard();
			moveHad();
		}
		if (Konec == 1)
			return 0;
	}
	return 0;
}

void resetPole()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			hraciPlocha[i][j] = volnePole;
			if (j == 0 || j == 14)
				hraciPlocha[i][j] = '|';
			if (i == 0 ||i == 14)
				hraciPlocha[i][j] = '-';
		}
	}
}

void  printBoard()
{
	system("cls");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			hraciPlocha[nRadek][nSloupec] = Had;
			printf("%c ", hraciPlocha[i][j]);
		}
		printf("\n");
	}
}

void moveHad()
{
		Move = getchar();
		switch (Move)
		{
		case 'a':
			nSloupec--;
			if (hraciPlocha[nRadek][nSloupec] == '#' || hraciPlocha[nRadek][nSloupec] == '|')
				GameOver();
			if (hraciPlocha[nRadek][nSloupec] == 'o') {
				hraciPlocha[nRadek][nSloupec] = '#';
				score++;
				jablkoSpawn();
			}
			break;
		case 'd':
			nSloupec++;
			if (hraciPlocha[nRadek][nSloupec] == '#' || hraciPlocha[nRadek][nSloupec] == '|')
				GameOver();
			if (hraciPlocha[nRadek][nSloupec] == 'o') {
				hraciPlocha[nRadek][nSloupec] = '#';
				score++;
				jablkoSpawn();
			}
			break;
		case 'w':
			nRadek--;
			if (hraciPlocha[nRadek][nSloupec] == '#' || hraciPlocha[nRadek][nSloupec] == '-')
				GameOver();
			if (hraciPlocha[nRadek][nSloupec] == 'o') {
				hraciPlocha[nRadek][nSloupec] = '#';
				score++;
				jablkoSpawn();
			}
			break;
		case 's':
			nRadek++;
			if (hraciPlocha[nRadek][nSloupec] == '#' || hraciPlocha[nRadek][nSloupec] == '-')
				GameOver();
			if (hraciPlocha[nRadek][nSloupec] == 'o') {
				hraciPlocha[nRadek][nSloupec] = '#';
				score++;
				jablkoSpawn();
			}
			break;
		default:
			break;
		}
}

void GameOver()
{
	printf("\nGameOver, Score: %d", score);
	Konec = 1;
}

void jablkoSpawn()
{
	while (hraciPlocha[spawnRow][spawnCol] != Jablko) {
		spawnCol = rand() % 13 + 1;
		spawnRow = rand() % 13 + 1;
		if (hraciPlocha[spawnRow][spawnCol] == ' ')
		{
			hraciPlocha[spawnRow][spawnCol] = Jablko;
		}
	}
}