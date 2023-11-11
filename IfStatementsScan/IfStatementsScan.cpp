#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*int A;
	int B;
	printf("zadejte 1. cislo: ");
	scanf("%d", &A);
	printf("zadejte 2. cislo: ");
	scanf("%d", &B);
	printf("definoval jsem cisla: %d, %d\n", A, B);
	if (A > B) {
		printf("maximum je %d", A);
	}
	else if (A < B) {
		printf("Maximum je %d", B);
	}
	else {
		printf("Obe cisla jsou stejna");
	}
	*/
	float A;
	float B;
	printf("zadejte 1. cislo: ");
	scanf("%f", &A);
	printf("zadejte 2. cislo: ");
	scanf("%f", &B);
	printf("definoval jsem cisla: %.3f, %.3f\n", A, B);
	if (A > B) {
		printf("maximum je %.3f", A);
	}
	else if (A < B) {
		printf("Maximum je %.3f", B);
	}
	else {
		printf("Obe cisla jsou stejna");
	}

	return 0;
}