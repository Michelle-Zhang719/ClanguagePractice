#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>


typedef char elm;
//#define  cur  current
typedef struct tree {
	elm data;
	struct tree* leftchild;
	struct tree* rightchild;
}tree, * p_tree;
typedef struct list1 {
	p_tree pos;
	struct list1* next;
}list1, * p_list;
void putout(p_tree p)
{
	if (p != NULL)
	{
		putchar(p->data);
		putout(p->leftchild);
		putout(p->rightchild);
	}

}
int main()
{
	p_list head = NULL;
	p_list tail = NULL;
	p_list cur = NULL;
	p_list plnew = NULL;
	p_tree pnew = NULL;
	char c = 0;
	while (scanf("%c", &c) != EOF)// 不同的结束条件
	{
		if (c == '\n')
		{
			break;//不同的结束条件
		}
		plnew= (p_list)calloc(1, sizeof(list1));
		pnew= (p_tree)calloc(1, sizeof(tree));
		pnew->data = c;
		plnew->pos = pnew;
		if (head == NULL)
		{
			head = plnew;
			tail = head;
			cur = head;
			continue;
		}
		tail->next = plnew;
		tail = tail->next;
		if (cur->pos->leftchild == NULL)
		{
			cur->pos->leftchild = pnew;
		}
		else if (cur->pos->rightchild == NULL)
		{

			cur->pos->rightchild = pnew;
			cur = cur->next;
		}
	}
	//rewind;
	putout(head->pos);
	//printf("\n");
	//记得申请的空间都free掉
	//free(tree_list);
	return 0;
}
