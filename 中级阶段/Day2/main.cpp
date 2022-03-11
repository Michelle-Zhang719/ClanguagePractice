//主要使用C++中的引用，具体作用可以规避二级指针的使用和解决c语言子函数中只传值不传地址的问题

//使用C++的引用，注意提交时把代码选为C++；在主函数定义字符指针 char *p,然后在子函数内malloc申请空间，通过fgets读取字符串，
//然后在主函数中进行输出；要求子函数使用C++的引用，注意在C++中从标准输入读取字符串，需要使用fgets(p,100,stdin)

#include<stdio.h>
#include <malloc.h>

void printf_str(char* &q)
{
	q = (char*)malloc(100);
	fgets(q, 100, stdin);

}

int main()
{
	char* p = NULL;

	//请注意指针在"引用"时的传递
	printf_str(p);
	puts(p);
	return 0;
}