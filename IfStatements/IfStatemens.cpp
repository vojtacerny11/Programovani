#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float A = 5.0;
	float B = 5.0;

		if (A > B) {
		printf("maximum je %f", A);
		}
		else if(A < B){
			printf("Maximum je %f", B);
		}
		else {
			printf("Obe cisla jsou stejna");
		}
		
	return 0;
}