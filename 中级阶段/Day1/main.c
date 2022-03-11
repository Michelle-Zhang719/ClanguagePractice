//输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

	//定义结构体
typedef struct student
{
	int num;
	char name[20];
	char sex;
}stu;

int main()
{
	stu eg = {0};

	//注意数组的取地址问题和%c前面加空格
	scanf("%d %s %c", &eg.num, eg.name, &eg.sex);

	printf("%d %s %c", eg.num, eg.name, eg.sex);
	return 0;
}
