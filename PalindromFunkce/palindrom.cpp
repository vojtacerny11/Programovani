#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[100];
bool Pravda = 1;
int Length;

int DelkaRetezce(const char* s)
{
	int ret = 0;
	while (s[ret] != '\n')
	{
		ret++;
	}
	return ret;
}

void KontrolaPalindromu();

int main()
{
	fgets(str, 100, stdin);
	Length = DelkaRetezce(str);
	KontrolaPalindromu();
	str[Length] = '\0';
	if (Pravda)
	{
		printf("retezec %s je palindrom", str);
	}
	else
	{
		printf("retezec %s neni palindrom", str);
	}
	return 0;
}

void KontrolaPalindromu()
{
	for (int i = 0; i < Length / 2; i++)
	{
		if (str[i] != str[Length - 1 - i])
		{
			Pravda = 0;
		}
	}
}