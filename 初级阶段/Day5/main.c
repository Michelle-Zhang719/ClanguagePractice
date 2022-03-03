//内存地址原理解释

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i;
	char j;
	float k, count;

	scanf("%d %c%f", &i, &j, &k);//混合输入时，字符型变量前加空格
	count = (float)i + (float)j + k;
	printf("%.2f", count);
	return 0;
}