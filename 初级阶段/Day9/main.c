//思路：将输入的字符串，经过处理后，存储到新的数组中，再与原来的字符串进行比较

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char start[100] = { 0 }, end[100] = { 0 };
	int len, j;//用于存储字符串长度

	gets(start);
	len = strlen(start);
	j = len;
	for (int i = 0; i < len; i++)
	{
		end[j - 1] = start[i];
		j--;
	}

	int result = strcmp(start, end);//将字符串进行比较
	if (result < 0)
	{
		printf("%d\n", -1);
	}
	else if (result > 0)
	{
		printf("%d\n", 1);
	}
	else {
		printf("%d\n", 0);
	}
	return 0;
}