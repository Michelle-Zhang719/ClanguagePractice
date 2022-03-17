#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];//数组,存储MaxSize-1个元素
	int front,rear;//队列头 队列尾
}SqQueue;

void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
//判空
bool isEmpty(SqQueue &Q)
{
	if(Q.rear==Q.front)//不需要为零
		return true;
	else
		return false;
}
//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
	if((Q.rear+1)%MaxSize==Q.front) //判断是否队满
		return false;
	Q.data[Q.rear]=x;//3 4 5 6
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];//先进先出
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
//《王道C督学营》课程
//王道数据结构 3.2 循环队列
int main()
{
	SqQueue Q;
	bool ret;//存储返回值
	ElemType element;//存储出队元素
	InitQueue(Q);
	ret=isEmpty(Q);
	if(ret)
	{
		printf("队列为空\n");
	}else{
		printf("队列不为空\n");
	}
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	ret=EnQueue(Q,6);
	ret=EnQueue(Q,7);
	if(ret)
	{
		printf("入队成功\n");
	}else{
		printf("入队失败\n");
	}
	ret=DeQueue(Q,element);
	if(ret)
	{
		printf("出队成功,元素值为 %d\n",element);
	}else{
		printf("出队失败\n");
	}
	ret=DeQueue(Q,element);
	if(ret)
	{
		printf("出队成功,元素值为 %d\n",element);
	}else{
		printf("出队失败\n");
	}
	ret=EnQueue(Q,8);
	if(ret)
	{
		printf("入队成功\n");
	}else{
		printf("入队失败\n");
	}
	system("pause");
}