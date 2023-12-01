#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	char otazky[][100] = {"1. kdy mam narozeniny?: ",
						  "2. kdy mam svatek?: " };
	char moznosti[][100] = {"A. 27.3", "B. 8.3",
							"A. 23.4", "B. 24.3" };
	char odpovedi[2] = { 'B', 'A' };

	int pocetotazek = 2;

	char typ;
	char typ2 = ' ';
	int score = 0;

	printf("hra kvizu\n");
	printf("************\n");


	for (int i = 0; i < pocetotazek; i++)
	{
		printf("************\n");
		printf("%s\n", otazky[i]);
		printf("************\n");
		for (int j = (2 * i); j < (i * 2) + 2; j++)
		{
			printf("%s\n", moznosti[j]);
		}
		printf("typ: ");
		scanf("%c", &typ);
		typ = toupper(typ);

		while (typ2 == ' ')
		{
			printf("typ: ");
			scanf("%c", &typ2);
			typ2 = toupper(typ2);
		}

		if (typ == odpovedi[i])
		{
			printf("spravne!\n");
			score++;
		}
		else {
			printf("spatne!\n");
		}
	}

	printf("Score: %d/%d", score, pocetotazek);

	return 0;
}