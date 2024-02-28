#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
char hraciPlocha[3][3];
char vyherce = ' ';
int volnaMista = 9;

void BoardPrint();
void ResetGame();
void Player1move();
void Player2move();
void kontrolaVyherce();

char sloupec;
int radek;

int main()
{
	char tlacitkoKonec;
	while (1)
	{
		while (vyherce == ' ' && volnaMista > 0)
		{
			BoardPrint();
			Player1move();
			kontrolaVyherce();
			BoardPrint();
			Player2move();
			kontrolaVyherce();
		}

		ResetGame();
	}

	return 0;
}

void BoardPrint()
{
	puts("--------");
	for (int i = 0; i < 3; i++)
	{
		printf(" %c | %c | %c \n", hraciPlocha[i][0], hraciPlocha[i][1], hraciPlocha[i][2]);
		puts("--------");
	}
	putchar('\n');
}

void ResetGame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			hraciPlocha[i][j] = ' ';
		}
	}
}

void Player1move()
{
	printf("Na rade je hrac se znakem X: \n");
	scanf(" %c%d", &sloupec, &radek);
	volnaMista--;
}

void Player2move()
{
	printf("Na rade je hrac se znakem O: \n");
	scanf(" %c%d", &sloupec, &radek);
	volnaMista--;
}

void kontrolaVyherce()
{
	for (int i = 0; i < 3; i++)
	{
		if (hraciPlocha[i][0] == hraciPlocha[i][1] && hraciPlocha[i][0] == hraciPlocha[i][2])
			vyherce = hraciPlocha[i][0];
	}
	for (int i = 0; i < 3; i++)
	{
		if (hraciPlocha[0][i] == hraciPlocha[0][i] && hraciPlocha[0][i] == hraciPlocha[0][i])
			vyherce = hraciPlocha[i][0];
	}
}