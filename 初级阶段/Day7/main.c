
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n, i, count;

	scanf("%d", &n);

	count = 1;
	for (i = 1; i <= n; i++)
	{
		count = count * i;
	}
	printf("%d\n", count);


	return 0;
}