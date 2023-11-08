#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("Zadejte delku hrany osmistenu: \n");
	float A;
	scanf("%f", &A);
	float V = sqrt(2.0) / 3 * A * A * A;
	printf("\nObjem osmistenu je %.3f\n", V);

	
	float S = 2 * sqrt(3.0) * A * A;
	printf("Obsah osmistenu je %.3f\n", S);

	float O = 12 * A;
	printf("Obvod vsech hran osmistenu je %.3f", O);
	return 0;
}