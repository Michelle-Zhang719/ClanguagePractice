#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//作者 王道训练营 龙哥
typedef char ElemType;
typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
}ThreadNode,*ThreadTree;
//手工建线索树，总计5个结点
void BulidThreadTree(ThreadTree &T)
{
	ThreadTree arr[5];
	int i;
	for(i=0;i<5;i++)
	{
		arr[i]=(ThreadTree)malloc(sizeof(ThreadNode));
		memset(arr[i],0,sizeof(ThreadNode));
		arr[i]->data='A'+i;
	}
	arr[0]->lchild=arr[1];
	arr[0]->rchild=arr[2];
	arr[1]->rchild=arr[3];
	arr[2]->lchild=arr[4];
	T=arr[0];
}
void InThread(ThreadTree &p,ThreadTree &pre)
{
	if(p!=NULL){
		InThread(p->lchild,pre);//递归找树的左孩子
		if(p->lchild==NULL){//左边为NULL
			p->lchild=pre;
			p->ltag=1;
		}
		if(pre!=NULL&&pre->rchild==NULL){
			//pre节点右孩子为NULL，就让其指向后继节点，而后继节点是p
			pre->rchild=p;
			pre->rtag=1;
		}
		pre=p;
		InThread(p->rchild,pre);
	}
}
void CreateInThread(ThreadTree T)
{
	ThreadTree pre=NULL;
	if(T!=NULL){
		InThread(T,pre);
		pre->rchild=NULL;9
		pre->rtag=1;
	}
}
//中序序列下的第一个结点
ThreadNode *Firstnode(ThreadNode *p)
{
	while(p->ltag==0)
		p=p->lchild;
	return p;
}
//p在中序序列下的后继结点
//《王道C督学营》课程，考研没考过大题，主要是实际没应用场景
int main()
{
	ThreadTree T;
	ThreadTree p;
	BulidThreadTree(T);
	CreateInThread(T);//构建线索二叉树
	p=Firstnode(T);
	printf("最左下结点值为 %c\n",p->data);
	system("pause");
}