#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int X;
	int Y;
	printf("zadejte cele cislo:\n");
	scanf("%d", &X);
	if (X % 2 != 0)
	{
		printf("cislo je liche");
	}
	else 
	{
		int Z = X / 2;
		if (Z % 2 != 0)
		{
			printf("cislo je sudo-liche");
		}
		else
		{
			printf("cislo je sudo-sude");
		}
	}
	return 0;
}