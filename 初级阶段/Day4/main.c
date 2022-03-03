//字符串大小写转换P54-P55  97-a 65-A
//闰年判断方法：
//1、非整百年份：能被4整除的是闰年。（如2004年就是闰年，2001年不是闰年）
//2、整百年份：能被400整除的是闰年。（如2000年是闰年，1900年不是闰年）

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int year;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}