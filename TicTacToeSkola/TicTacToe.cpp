#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

void resetPole();
void VypisPole();
void Hrac1();
void Hrac2();
void urceniVyherce();

char arr[3][3] = {};
char sloupec;
int radek;
char vyherce = ' ';
int volnaMista = 9;

int main()
{
	resetPole();
	VypisPole();

	while (vyherce == ' ' && volnaMista > 0)
	{
		Hrac1();
		VypisPole();
		urceniVyherce();
		if (vyherce != ' ' || volnaMista == 0)
		{
			break;
		}
		Hrac2();
		VypisPole();
		urceniVyherce();
		if (vyherce != ' ' || volnaMista == 0)
		{
			break;
		}
	}
	if (vyherce != ' ')
	{
		printf("VYHERCE JE HRAC SE ZNAKEM %c", vyherce);
	}
	else
	{
		printf("HRA SKONCILA REMIZOU");
	}

	return 0;
}

void Hrac1()
{
	printf("Na tahu je X, zadejte pozici: \n");
	scanf(" %c%d", &sloupec, &radek);
	sloupec = tolower(sloupec);
	radek--;
	switch (sloupec)
	{
	case 'a':
		for (int i = 0; i <= radek; i++)
		{
			if (i == radek)
			{
				if (arr[i][0] == 'O')
				{
					printf("spatny vstup\n");
				}
				arr[i][0] = 'X';
			}
		}
		break;
	case 'b':
		for (int i = 0; i <= radek; i++)
		{
			if (i == radek)
			{
				if (arr[i][1] == 'O')
				{
					printf("spatny vstup\n");
				}
				arr[i][1] = 'X';
			}
		}
		break;
	case 'c':
		for (int i = 0; i <= radek; i++)
		{
			if (i == radek)
			{
				if (arr[i][2] == 'O')
				{
					printf("spatny vstup\n");
				}
				arr[i][2] = 'X';
			}
		}
		break;
	}
	volnaMista--;
}

void Hrac2()
{
	printf("Na tahu je O, zadejte pozici: \n");
	scanf(" %c%d", &sloupec, &radek);
	sloupec = tolower(sloupec);
	radek--;
	switch (sloupec)
	{
	case 'a':
		for (int i = 0; i <= radek; i++)
		{
			if (i == radek)
			{
				if (arr[i][0] == 'X')
				{
					printf("spatny vstup\n");
				}
				arr[i][0] = 'O';
			}
		} break;
	case 'b':
		for (int i = 0; i <= radek; i++)
		{
			if (i == radek)
			{
				if (arr[i][1] == 'X')
				{
					printf("spatny vstup\n");
				}
				arr[i][1] = 'O';
			}
		} break;
	case 'c':
		for (int i = 0; i <= radek; i++)
		{
			if (i == radek)
			{
				if (arr[i][2] == 'X')
				{
					printf("spatny vstup\n");

				}
				arr[i][2] = 'O';
			}
		} break;
	}
	volnaMista--;
}

void urceniVyherce()
{
	for (int i = 0; i < 3; i++)
	{
		//rady
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
		{
			vyherce = arr[i][0];
		}
		//slopupce
		for (int i = 0; i < 3; i++)
		{
			if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
			{
				vyherce = arr[0][i];
			}
		}
	}
}

void resetPole()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void VypisPole()
{
	puts("-------------");
	for (int i = 2; i >= 0; i--)
	{
		printf("| %1c | %1c | %1c |\n", arr[i][0], arr[i][1], arr[i][2]);
		puts("-------------");
	}
}