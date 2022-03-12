//初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），
//插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，然后scanf读取一个整型数，是删除的位置（假如输入为1），
//然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串。提醒，Language一定要选为C++。

#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 20

#include<stdio.h>

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	ElemType len;
}SqList;

bool ListInsert(SqList& L, int i, ElemType e)
{
	//判断位置是否合法,可插入的位置是 1，2，3，4
	if (i<1 || i>L.len + 1)
	{
		return false;
	}
	//顺序表中，元素已满，有20个元素在，不能在插入了！！
	if (i > MaxSize)
	{
		return false;
	}
	//后面的元素往后挪一位
	for (int j = L.len; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i - 1] = e;
	L.len++;
	return true;
}

bool ListDelete(SqList& L, int i)
{
	//判断位置是否合法,可删除的位置是 1，2，3
	if (i<1 || i>L.len)
	{
		return false;
	}
	//后面的元素往前挪一位
	for (int j = i; j <L.len; j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.len--;
	return true;
}

//用于打印
void printf_e(SqList& L)
{
	int i ;
	for (i = 0; i < L.len; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

int main()
{
	SqList L;
	L.data[0] = { 1 };
	L.data[1] = { 2 };
	L.data[2] = { 3 };
	L.len = 3;

	ElemType n;//存插入的元素
	scanf("%d", &n);

	//插入到第2个位置，打印输出顺序表，每个元素占3个空格
	int ret;
	ret=ListInsert(L, 2, n);
	if (ret)
	{
		printf_e(L);
	}
	else
	{
		return 0;//插入失败
	}

	int m;//存删除的位置
	scanf("%d", &m);

	ret = ListDelete(L,m);
	if (ret)
	{
		printf_e(L);
	}
	else
	{
		printf("false");
		return 0;//插入失败
	}
	return 0;

}