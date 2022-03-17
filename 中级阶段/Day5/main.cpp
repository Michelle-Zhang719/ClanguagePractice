//输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，
//查找第二个位置的值并输出，在2个位置插入99，输出为  3 99  4  5  6  7，
//删除第4个位置的值，打印输出为  3 99  4  5  6  7。
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//尾插法
void CreatList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));//为头节点申请空间
	L->next = NULL;//初始化头节点

	LNode* r;//永远是尾节点
	r = L;

	LNode* s;//存放新节点
	ElemType x;//存放输入
	scanf("%d", &x);

	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));//为新节点申请空间
		s->data = x;//赋值
		r->next = s;//尾部节点指向新节点
		r = s;//r依然在尾节点
		scanf("%d", &x);
	}
	r->next = NULL;
}
//查找第二个位置的值
LinkList SerchList(LinkList L, int i)
{
	//找到第i节点即可输出
	int j = 1;//用来计数
	LNode* p = L->next;//用指针p进行遍历
	if (0 == i)
	{
		return L;//只有头节点
	}
	if (i<1)//位置不合法
	{
		return NULL;
	}
	//遍历寻找
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;//返回第i个节点的指针
}

void InsertList(LinkList L, int i, ElemType e)
{
	//找到前一个位置，在其后面加入点
	LNode* p = SerchList(L, i - 1);
	LNode* s = (LinkList)malloc(sizeof(LNode));//为新节点申请空间
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
}

void DeleteList(LinkList L, int i)
{
	//找到第i-1个节点，然后删除第i个节点0
	LNode* p = SerchList(L, i - 1);
	LNode* s = p->next;//指针s指向要被删除的第i个节点
	p->next = s->next;//断链
}
int main()
{
	LinkList L;

	//尾插法创建链表
	CreatList(L);
	LinkList answer;//存储查找的返回值

	//查找第二个位置的值并输出
	answer = SerchList(L, 2);
	if (answer != NULL)
	{
		printf("%d\n", answer->data);
	}

	//在2个位置插入99
	InsertList(L, 2, 99);
	PrintList(L);
	//删除第4个位置的值
	DeleteList(L, 4);
	PrintList(L);
	return 0;
}