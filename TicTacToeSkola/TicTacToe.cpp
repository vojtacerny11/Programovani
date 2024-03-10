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
char vyherce = ' ';
int radek;
int volnaMista = 9;
int novaHra = 0;
bool spatnyVstup = 0;

int main()
{
	while (1)
	{
		resetPole();
		VypisPole();

		while (vyherce == ' ')
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
			printf("VYHERCE JE HRAC SE ZNAKEM %c\n", vyherce);
		}
		else
		{
			printf("HRA SKONCILA REMIZOU\n");
		}
		printf("Chcete hrat znovu? Ano: 1 Ne: 0\n");
		scanf("%d", &novaHra);
		if (novaHra == 0)
		{
			return 0;
		}
		else if (novaHra == 1)
		{
			vyherce = ' ';
			volnaMista = 9;
		}
	}
}

void Hrac1()
{
	do
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
					if (arr[i][0] != ' ')
					{
						printf("spatny vstup\n");
						spatnyVstup = 1;
					}
					else
					{
						arr[i][0] = 'X';
						spatnyVstup = 0;
					}
				}
			}
			break;
		case 'b':
			for (int i = 0; i <= radek; i++)
			{
				if (i == radek)
				{
					if (arr[i][1] != ' ')
					{
						printf("spatny vstup\n");
						spatnyVstup = 1;
					}
					else
					{
						arr[i][1] = 'X';
						spatnyVstup = 0;
					}
				}
			}
			break;
		case 'c':
			for (int i = 0; i <= radek; i++)
			{
				if (i == radek)
				{
					if (arr[i][2] != ' ')
					{
						printf("spatny vstup\n");
						spatnyVstup = 1;
					}
					else
					{
						arr[i][2] = 'X';
						spatnyVstup = 0;
					}
				}
			}
			break;
		}
	} while (spatnyVstup == 1);
	volnaMista--;
}

void Hrac2()
{
	do {
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
					if (arr[i][0] != ' ')
					{
						printf("spatny vstup\n");
						spatnyVstup = 1;
					}
					else
					{
						arr[i][0] = 'O';
						spatnyVstup = 0;
					}
				}
			} break;
		case 'b':
			for (int i = 0; i <= radek; i++)
			{
				if (i == radek)
				{
					if (arr[i][1] != ' ')
					{
						printf("spatny vstup\n");
						spatnyVstup = 1;
					}
					else
					{
						arr[i][1] = 'O';
						spatnyVstup = 0;
					}
				}
			} break;
		case 'c':
			for (int i = 0; i <= radek; i++)
			{
				if (i == radek)
				{
					if (arr[i][2] != ' ')
					{
						printf("spatny vstup\n");
						spatnyVstup = 1;

					}
					else 
					{
						arr[i][2] = 'O';
						spatnyVstup = 0;
					}
				}
			} break;
		}
	} while (spatnyVstup == 1);
	volnaMista--;
}

void urceniVyherce()
{
		//rady
		for (int i = 0; i < 3; i++)
		{
			if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
			{
				vyherce = arr[i][0];
			}
		}
		//slopupce
		for (int i = 0; i < 3; i++)
		{
			if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
			{
				vyherce = arr[0][i];
			}
		}
		//diagonalni
		if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
		{
			vyherce = arr[0][0];
		}
		if (arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2])
		{
			vyherce = arr[2][0];
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
		printf("| %c | %c | %c |\n", arr[i][0], arr[i][1], arr[i][2]);
		puts("-------------");
	}
}