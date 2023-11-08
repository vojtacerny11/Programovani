#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()

{
	char jmeno[10];
	printf("Zadejte sve jmeno: ");
	scanf("%s", jmeno);

	printf("Ahoj %s!", jmeno);
	return 0;
}
