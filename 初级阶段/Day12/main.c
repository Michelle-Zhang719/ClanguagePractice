//经典走台阶，视频讲解在中级阶段Day1的23min左右

//思路：使用递归函数，第一步写公式，第二步，写结束条件
//找公式：数学上的归纳演绎

//台阶   方法
//1       1
//2       2
//3       3
//4       5
//5       8

//说明是前两个之和 step（n）=step（n-1）+step（n-2）
//考虑结束条件，1阶和2阶时为特殊情况，写为结束条件

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int step(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	return step(n - 1) + step(n - 2);
}

int main()
{
	int n;//有n个台阶

	scanf("%d", &n);

	printf("%d", step(n));

	return 0;
}