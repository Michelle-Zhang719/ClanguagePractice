#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////书p190页例子
//int main()
//{
//	int a[3] = { 2, 7, 8 };
//	int* p;
//	int j;
//	p = a;//数组名a存放数组的起始地址，赋值给指针p；指针p指向的是a[0]
//	j = *p++;//相当于j=*p; p++; 即j等于指针p指向的a[0]的值（2），指针p后移，指向a[1];
//	printf("a[0]=%d, j=%d, *p = %d\n", a[0], j, *p);//此时指针p指向a[1]，取值为7
//
//	return 0;
//}


////书p196例子
//char* print_malloc()
//{
//	char* c;
//	c = (char*)malloc(20);
//	strcpy(c, "i am print_malloc\n");
//	puts(c);
//	return c;
//}
//
//int main()
//{
//	char* p;
//	p = print_malloc();
//	puts(p);
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	int i;//对应大小内存
	scanf("%d", &i);
	getchar();//过滤回车


	char* c;//接收申请空间的起始地址
	c = (char*)malloc(i);
	gets(c);
	puts(c);

	return 0;
}