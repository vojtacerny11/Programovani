#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char list[] = {1, 2 , 3, 4, 5, 6, 7, 8, 9};


	for (int i = 0; i < 9; i++) {
		printf("list[polozka %d] = %d ", (i + 1), list[i]);
	}


	return 0;
}