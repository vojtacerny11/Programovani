/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define w 32
#define h 32
#define all 128

int main()
{
	int a;
	printf("zadejte cele cislo\n");
	scanf("%d", &a);
	int x = a % ;
	int y;
	printf("x = %d", x);

	return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define w 32
#define h 32
#define sloupec 128

int main()
{
	int a;
	printf("zadejte cele cislo\n");
	scanf("%d", &a);
	int x = a % (sloupec / w) * w;
	int y = a / (sloupec / h) * h;
	printf("x = %d, y = %d", x, y);

	return 0;
}
