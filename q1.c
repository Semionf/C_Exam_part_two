#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

#define MAX_SIZE 100

int main1()
{
	char arr[MAX_SIZE];
	char firstPart[MAX_SIZE / 2], secondPart[MAX_SIZE / 2];
	int len, i;
	gets(arr);
	len = strlen(arr);
	strncpy(firstPart, arr, len / 2);
	firstPart[len / 2] = 0;

	if ((len / 2) % 2 != 0)
	{
		strncpy(secondPart, arr + (len / 2), len / 2 + 1);
		secondPart[len / 2 + 1] = 0;
	}
	else
	{
		strncpy(secondPart, arr + (len / 2), len / 2);
		secondPart[len / 2] = 0;
	}

	secondPart[len / 2 + 1] = 0;
	printf("first part is: %s\n", firstPart);
	printf("second part is: %s\n", secondPart);
	return 0;
}