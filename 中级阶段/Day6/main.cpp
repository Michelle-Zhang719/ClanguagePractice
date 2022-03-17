//新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，
//新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，入队7时，
//队满，打印false，然后依次出队，输出 3 4 5 6

#define _CRT_SECURE_NO_WARNINGS
#define SMaxsize 4//顺序栈的最大存储数量
#define Maxsize 5//循环队列最多可以存储4个数，浪费一个位置用以判断队满

#include<stdio.h>

typedef int ElemType;
//顺序栈的结构体
typedef struct
{
	ElemType data[SMaxsize];//栈的数据
	int top;//栈的指针
}SqStack;

//循环队列的结构体
typedef struct
{
	ElemType data[Maxsize];//数据
	int front, rear;//队头指针，队尾指针
}CQueue;

void InintStack(SqStack &S)
{
	S.top = -1;//栈顶指针指向－1
}

bool PushStack(SqStack& S, ElemType x)
{
	//判断栈是否有位置
	if ( SMaxsize - 1 == S.top)
	{
		return false;
	}
	//入栈，指针先往上走，再赋值
	S.top++;
	S.data[S.top] = x;
	return true;
}

bool PopStack(SqStack& S, ElemType &e)
{
	//判断栈是否为空
	if (- 1 == S.top)
	{
		return false;
	}
	//出栈，先赋值，指针再往下走
	e = S.data[S.top];
	S.top--;
	return true;
}

//以下为循环队列
void InintQueue(CQueue& Q)
{
	//因为Maxsize=5，所以存储下标为0，1，2，3，4
	Q.front = Q.rear = 0;
}

bool EnQueue(CQueue& Q, ElemType y)
{
	//判断队列满
	if ((Q.rear + 1) % Maxsize == Q.front)
	{
		return false;
	}
	//0，1，2，3，4位置还没有数，所以先赋值，指针之后加一
	Q.data[Q.rear] = y;
	Q.rear++;
	return true;
}

bool DeQueue(CQueue& Q, ElemType &z)
{
	//判断队列空
	if (Q.rear == Q.front)
	{
		return false;
	}
	//0，1，2，3，4位置都有数，所以先赋值，指针之后加一
	z = Q.data[Q.front];
	Q.front++;
	return true;
}

int main()
{
	SqStack S;//新建顺序栈
	InintStack(S);//初始化顺序栈

	int i = 0;//用来记输入几个数
	ElemType x;//用来接收输入数据
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &x);
		PushStack(S, x);
	}
	//出栈
	ElemType e ;//用来接收出栈数据
	for (i = 0; i < 3; i++)
	{
		PopStack(S,e);
		printf("%2d", e);
	}
	printf("\n", e);

	//以下为循环队列
	CQueue Q;//新建顺序栈
	InintQueue(Q);//初始化顺序栈
	int j = 0;//用来记输入几个数
	ElemType y;//用来接收输入数据
	int ret;//判断返回值，看操作是否成功
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &y);
		ret = EnQueue(Q, y);
		if (ret == 0)
		{
			printf("false\n");
		}
	}
	//出队
	ElemType z;//用来接收出队数据
	for (j = 0; j < Maxsize-1; j++)
	{
		DeQueue(Q, z);
		printf("%2d", z);
	}

}