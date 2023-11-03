#include <stdio.h>

int main()
{
	float X;
	float Y;

	printf("VYPOCTETE OBSAH OBDELNIKU\n");
	printf("Zadejte sirku:\n");
	scanf_s("%f", &X);
	printf("Zadejte vysku:\n");
	scanf_s("%f", &Y);

	float Z = X * Y;
	printf("Obsah obdelniku je: ");
	printf("%f \n", Z);
	float A = 2 * (X + Y);
	printf("Obvod obdelniku je: ");
	printf("%f", A);

	return 0;

}