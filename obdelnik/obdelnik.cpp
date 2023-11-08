#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float X;
	float Y;

	printf("VYPOCTETE OBSAH OBDELNIKU\n");
	printf("Zadejte sirku:\n");
	scanf("%f", &X);
	printf("Zadejte vysku:\n");
	scanf("%f", &Y);
	puts("");
	float Z = X * Y;
	printf("Obsah obdelniku je: %f\n", Z);
	
	float A = 2 * (X + Y);
	printf("Obvod obdelniku je: %f\n", A);
	

	return 0;

}