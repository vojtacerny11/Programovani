#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int odpoved = 2;
	int typ = 0;
	int pokusyLimit = 3;
	int pokusy = 0;
	int trueLimit = 0;
	printf("TYPNETE CISLO, MATE 3 POKUSY\n");
	printf("zadejte cislo od 1 do 10: ");
	scanf("%d", &typ);
	pokusy++;

	while (typ != odpoved && trueLimit == 0) {
		if (pokusy < pokusyLimit) {
			if(typ < odpoved) {
				printf("spatne, zadejte jine vetsi cislo od 1 do 10: ");
				scanf("%d", &typ);
				pokusy++;
			} else {
				printf("spatne, zadejte jine mensi cislo od 1 do 10: ");
				scanf("%d", &typ);
				pokusy++;
			}
			
		}
		else {
			trueLimit = 1;
		}
	} if (trueLimit == 1) {
		printf("dosly Vam pokusy, spravne cislo bylo %d", odpoved);
	}
	else {
		printf("spravne");
	}

	return 0;
}