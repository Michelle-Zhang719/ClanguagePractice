#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a >= 65 && a <= 122)
	{
		printf("%c", a);
	}
	return 0;
}