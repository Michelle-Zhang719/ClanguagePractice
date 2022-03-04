#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a10=1, b5=1, c2=1, d1=1;//面额对应张数
	int num = 0;//总值100元
	int count = 0;//张数共有40张
	int answer = 0;//共有几种解法

	for (;a10<=40;a10++)
	{
		for (; b5 <= 40; b5++)
		{
			for (; c2 <= 40; c2++)
			{
				for (; d1 <= 40; d1++) 
				{
					if (((a10 + b5 + c2 + d1) == 40) && ((a10 * 10 + b5 * 5 + c2 * 2 + d1 * 1) == 100))
					{
						answer=answer+1;
					}
				}
			}
		}
	}

	printf("%d", answer);

	return 0;
}