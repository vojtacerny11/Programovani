#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	int y;
	int z;
	printf("zadejte pocet minut: \n");
	scanf("%d", &x);
	y = x % 60;
	z = x / 60;
	if (y != 0) {
		printf("vas zadany cas v hodinach je %d:", z);
		printf("%d", y);
	}
	else {
		printf("vas zadany cas v hodinach je %d", z);
	}
	
	return 0;
}