//输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，通过尾插法新建链表并输出。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;//数据域
	struct LNode* next;//指针域
}LNode, *LinkList;//结构体类型，结构体指针类型

//头插法
void CreatList_tou(LinkList& L)
{
	LNode* a;//存放新节点
	ElemType x;//存放输入的数
	L = (LinkList)malloc(sizeof(LNode));//创建头节点
	L->next = NULL;//初始化为空链表

	scanf("%d",&x );
	while (x != 9999)
	{
		a = (LinkList)malloc(sizeof(LNode));//新节点
		a->data = x;//赋值
		a->next = L->next;
		L->next = a;
		scanf("%d", &x);
	}
}

//尾插法
void CreatList_wei(LinkList& L)
{
	LNode* r;//尾指针	
	LNode* a;//新节点
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	r = L;

	scanf("%d", &x);
	while (x != 9999)
	{
		a = (LinkList)malloc(sizeof(LNode));
		a->data = x;
		r->next = a;
		r = a;//r指向新的尾节点
		scanf("%d", &x);
	}
	r->next = NULL;
}
//打印元素
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
		if (L != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	LinkList L;//头指针L
	//头插法
	CreatList_tou(L);
	PrintList(L);
	CreatList_wei(L);
	PrintList(L);
	return 0;
}