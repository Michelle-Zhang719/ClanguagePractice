//读取10个元素 87  7 60 80 59 34 86 99 21  3，然后建立二叉查找树，
//中序遍历输出3  7 21 34 59 60 80 86 87 99，针对有序后的元素，
//存入一个长度为10的数组中，通过折半查找找到21的下标（下标为2），然后输出2

#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 10
#include<stdio.h>
#include<stdlib.h>

//树的结构体
typedef int Elemtype;
typedef struct BiNode
{
	Elemtype data;//数据域
	struct BiNode* lchild;//树的左指针
	struct BiNode* rchild;//树的右指针
}BiNode, * Bitree;//树的节点 ， 结构体指针类型

typedef struct SeqList
{
	Elemtype elm[MaxSize];//数据域
	int length;//顺序表的长度
}SeqList;//顺序表

bool BST_Insert(Bitree& tree, Elemtype e)
{
	//思想：原树为空，新插入的点为根节点（相较于每一个小树来说）
	//若树中节点与插入节点相同，则插入失败
	//若插入节点大于该节点，插入至右子树，否则插入左子树
	if (NULL == tree)//原来的树为空（传进来的树为空）
	{
		tree = (Bitree)malloc(sizeof(BiNode));//为新树申请空间
		tree->data = e;//给该节点赋值并初始化左右指针
		tree->lchild = NULL;
		tree->rchild = NULL;
		return true;//插入成功
	}
	else if (tree->data == e)
	{
		return false;//插入失败
	}
	else if (e > tree->data)
	{
		return BST_Insert(tree->rchild, e);
	}
	else
	{
		return BST_Insert(tree->lchild, e);
	}
}

void Crest_BST(Bitree& tree, Elemtype x[])
{
	tree = NULL;

	int i = 0;//用来计数
	//将10个元素插入
	while (i < 10)
	{
		BST_Insert(tree, x[i]);
		i++;
	}
}

//将排好序的元素存入数组，也可以这么做，注意pos加引用
//void MidOrder_Array(Bitree tree,Elemtype key[],int &pos)
//{
//
//	if (NULL != tree)
//	{
//		MidOrder_Array(tree->lchild, key, pos);
//		printf("%3d", tree->data);
//		key[pos] = tree->data;
//		pos++;
//		MidOrder_Array(tree->rchild, key, pos);
//	}
//}
void MidOrder(Bitree tree)
{

	if (NULL != tree)
	{
		MidOrder(tree->lchild);
		printf("%3d", tree->data);
		MidOrder(tree->rchild);
	}
}

int toArrayIn(Bitree tree, SeqList &L, int pos)
{
	if (tree == NULL)
		return pos;
	pos = toArrayIn(tree->lchild, L, pos);
	L.elm[pos] = tree->data;
	return toArrayIn(tree->rchild, L, pos + 1);
}

int Binary_Search(SeqList& L, Elemtype tag)
{
	int low = 0;
	int high = L.length - 1;
	int mid;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (L.elm[mid] == tag)
		{
			return mid;//找到则返回数组下标
		}
		else if (L.elm[mid] > tag)
		{
			high = mid - 1;//往左找
		}
		else 
		{
			low = mid + 1;
		}
	}
	return -1;//遍历结束，则未找到，返回-1
}

int main()
{
	Bitree tree = NULL;//树为空

	int i;//用以计数输入10个元素
	Elemtype x[MaxSize];
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &x[i]);
	}
	Crest_BST(tree, x);
	int pos = 0;
	//中序遍历
	//Elemtype key[MaxSize];
	//MidOrder_Array(tree, key, pos);
	MidOrder(tree);

	//将排好序的元素存入数组中
	SeqList L;
	L.length = 10;
	toArrayIn(tree, L, pos);
	printf("\n");

	//折半查找
	printf("%d", Binary_Search(L, 21));
	return 0;
}