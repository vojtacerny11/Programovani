#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));

	int odpoved = rand() % 10 + 1;
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
				printf("spatne, zadejte jine vetsi cislo od %d do 10: ", typ);
				scanf("%d", &typ);
				pokusy++;
			} else {
				printf("spatne, zadejte jine mensi cislo od 1 do %d: ", typ);
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