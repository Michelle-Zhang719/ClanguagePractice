#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a[100] = {0};//存放N个数
	int num;//存放输入几个数
	int count = 0;//出现几次2

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 2)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;

}