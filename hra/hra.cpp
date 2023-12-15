#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int a;
void cislo()
{
	printf("napiste cislo a ja ho uhadnu: \n");
	scanf("%d", &a);
}

void proces()
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j < 500000000; j++)
		{
			int x = j;
		} 
		printf(". ");
		printf(". ");
	}
}

void cislo2()
{
	printf("myslis si cislo %d", a);
}

int main()
{
	cislo();

	proces();

	printf("\n");

	cislo2();


	return 0;
}