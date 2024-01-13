#include <stdio.h>

int main() {
    int i = 2; //toto bude jmenovatel pro testovani, timto zacnu delit a pak zvysuju
    int cislo = 0;  //toto cislo testuji
    int prvocislo = 1; //predpokladam, ze cislo je prvocislo, dokud nenajdu delitele

    while (1) {
        i = 2;
        prvocislo = 1;
        printf("Zadejte cislo: ");
        scanf_s("%d", &cislo);
        //printf("%d\n:", cislo);

        if (cislo > 1) {
            //prvocisla jsou jen prirozena cisla vetsi nez 1
            while (i < cislo) {
                //pro 2 to neprobehne, ale 2 je prvocislo
                if (cislo % i == 0) {
                    //nalezl jsem delitele, neni prvocislo
                    prvocislo = 0;
                    //printf("%d\n", i);  //muj nalezeny delitel
                    break;
                }
                i++;
            }
        }
        else {
            prvocislo = 0;
        }

        if (prvocislo == 0) {
            printf("%s %d %s\n", "Cislo", cislo, "neni prvocislo!");
        }
        else {
            printf("%s %d %s\n", "Cislo", cislo, "je prvocislo!");
        }
    }

    return 0;
}