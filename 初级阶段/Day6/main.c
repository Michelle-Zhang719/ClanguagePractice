//思路：原整型数依次取余，将所得余数构造成一个新整型数，判断新整型数与原整型数是否一致。
//    若一致，则该整型数是回文数，若不一致，则该整型数不是回文数。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int start,end=0,temp;

	scanf("%d", &start);

	temp = start;
	while (start!=0)
	{
		end = end * 10 + start % 10;
		start = start / 10;
	}

	if (temp == end)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}

	return 0;
}