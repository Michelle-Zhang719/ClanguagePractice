//读取字符串abcdefghij，然后层次建树建立一颗二叉树，然后前序遍历输出abdhiejcfg，注意不要打印前序遍历几个汉字
//思路：层次遍历创建二叉树，用队列记录节点（该节点是否有左右孩子）

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
//二叉数的结构体，用链表实现
typedef  char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;//二叉树的节点，二叉树本树

//记录节点的链队，若节点的左右孩子不为空，则出队
typedef struct label
{
	BiTree p;//树的某一个结点的地址值
	struct label* pnext;
}label, * Label;//链队节点，链队

void preOrder(BiTree tree)
{
	if (tree != NULL)
	{
		putchar(tree->data);
		preOrder(tree->lchild);
		preOrder(tree->rchild);
	}
}

int main()
{
	BiTree pnew;//树的新节点
	BiTree tree = NULL;//树根为空

	//层次遍历的辅助队列
	Label phead = NULL, ptail = NULL;//phead就是队列头，ptail就是队列尾
	Label listpnew;//链队的新节点
	Label pcur = NULL;//listpnew是队列的新节点 pcur是树的当前节点

	ElemType c;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc申请空间并对空间进行初始化
		pnew->data = c;//数据放进去

		listpnew = (Label)calloc(1, sizeof(Label));//给队列结点申请空间
		listpnew->p = pnew;//赋值

		if (NULL == tree)//树根为空
		{
			tree = pnew;//树的根
			phead = listpnew;//队列头
			ptail = listpnew;//队列尾
			pcur = listpnew;
			continue;//跳出本次循环
		}
		else {
			ptail->pnext = listpnew;//新结点放入链表，通过尾插法//尾插法入队
			ptail = listpnew;//ptail指向队列尾部
		}

		//pcur始终指向要插入的结点的位置
		if (NULL == pcur->p->lchild)//如何把新结点放入树
		{
			pcur->p->lchild = pnew;//把新结点放到要插入结点的左边
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//把新结点放到要插入结点的右边
			pcur = pcur->pnext;//左右都放了结点后，pcur指向队列的下一个
		}
	}
	preOrder(tree);
}
