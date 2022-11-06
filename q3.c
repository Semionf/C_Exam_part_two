#include <stdio.h>

#pragma warning (disable: 4996)
int Add222(int);

int main3()
{
	Add222(1);
	return 0;
}

int Add222(int num)
{
	printf("%d\n", num);
	return num == 100 ? NULL : Add222(num + 1);
}