//输入一个整型数，存入变量i，通过子函数change把主函数的变量i除2，然后打印i，例如如果输入的为10，打印出5，如果输入的为7，打印出3

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void change(int* p)
{
	*p = *p / 2;
}

int main()
{
	int i;
	scanf("%d", &i);

	change(&i);//指针的传值
	printf("%d", i);
	return 0;
}