#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组
	int top;
}SqStack;

void InitStack(SqStack &S)
{
	S.top = -1;//代表栈为空
}

bool StackEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)
	{
		return false;//栈满了
	}
	S.data[++S.top] = x;
	return true;//返回true就是入栈成功
}
//获取栈顶元素
bool GetTop(SqStack S, ElemType &x)
{
	if (StackEmpty(S))//栈为空
	{
		return false;
	}
	x = S.data[S.top];
	return true;
}
bool Pop(SqStack& S, ElemType& x)
{
	if (StackEmpty(S))//栈为空
	{
		return false;
	}
	x = S.data[S.top--];//等价于x = S.data[S.top]；再做	S.top--;
	return true;
}
int main()
{
	SqStack S;
	bool flag;
	ElemType m;//存储拿出来的栈顶元素的
	InitStack(S);//初始化
	flag = StackEmpty(S);
	if (flag)
	{
		printf("栈是空的\n");
	}
	Push(S, 3);//入栈元素3
	Push(S, 4);//入栈元素4
	Push(S, 5);
	flag = GetTop(S, m);//获取栈顶元素,但是S.top值不变
	if (flag)
	{
		printf("获取栈顶元素为 %d\n", m);
	}
	flag = Pop(S, m);//弹出栈顶元素
	if (flag)
	{
		printf("弹出元素为 %d\n", m);
	}
	return 0;
}