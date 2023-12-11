#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int list[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int polozky = 10;

void sort()
{
	for (int i = 0; i < polozky; i++)
	{
		for (int j = 0; j < polozky; j++)
		{
			if (list[j] > list[j + 1])
			{
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

int main()
{
	sort();
	for (int i = 0; i < polozky; i++)
	{
		printf("%d ", list[i]);
	}
	return 0;
}