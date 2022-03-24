//输入一个字符串abaabcdac，直接手动打印它的next数组值（也就是自己人工算，直接写死到一个数组里，for循环输出数组即可），
//每个输出的数值占两个空格（%2d），因此不能给大家输出是啥。

#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 10
#include<stdio.h>

int main()
{
	char T[MaxSize];//存放原来数组
	int s[MaxSize] = {0,1,1,2,2,3,1,1,2};//存放next数组

	int i;//用来计输入次数

	for (i = 1; i < 10; i++)
	{
		scanf("%c", &T[i]);
	}

	for (i = 0; i < 9; i++)
	{
		printf("%2d", s[i]);
	}

	return 0;
}