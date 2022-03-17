#include <stdio.h>
#include <stdlib.h>
//Fib是递归函数
int Fib(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return Fib(n-1)+Fib(n-2);
}
//王道数据结构 斐波那契数列
//递归  函数调用自身
//0  1  1  2  3   5 
//f(n)=f(n-1)+f(n-2)
//考研不是很重要，了解即可
//有点类似于走楼梯
//前两个数相加等于第三个数

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("Fib(%d) = %d\n",num,Fib(num));
	}
	system("pause");
}
//题目  n个台阶，每次只能上1个台阶，或者2个台阶，n个台阶，有多少种走法