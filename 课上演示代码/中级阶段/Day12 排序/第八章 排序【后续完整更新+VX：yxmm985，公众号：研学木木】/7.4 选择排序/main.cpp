#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)//申请空间，并进行随机数生成
{
	ST.TableLen=len;
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;
	}
}
void ST_print(SSTable ST)
{
	for(int i=0;i<ST.TableLen;i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
void swap(ElemType &a,ElemType &b)
{
	ElemType tmp;
	tmp=a;
	a=b;
	b=tmp;
}
void SelectSort(ElemType A[],int n)
{
	int i,j,min;//min记录最小的元素的下标
	for(i=0;i<n-1;i++)//最多可以为8
	{
		min=i;
		for(j=i+1;j<n;j++)//j最多可以为9
		{
			if(A[j]<A[min])
				min=j;
		}
		if(min!=i)
		{
			swap(A[i],A[min]);
		}
	}
}
//调整某个父亲节点
void AdjustDown(ElemType A[],int k,int len)
{
	int i;
	A[0]=A[k];
	for(i=2*k;i<=len;i*=2)
	{
		if(i<len&&A[i]<A[i+1])//左子节点与右子节点比较大小
			i++;
		if(A[0]>=A[i])
			break;
		else{
			A[k]=A[i];
			k=i;
		}
	}
	A[k]=A[0];
}
//用数组去表示树   层次建树
void BuildMaxHeap(ElemType A[],int len)
{
	for(int i=len/2;i>0;i--)
	{
		AdjustDown(A,i,len);
	}
}
void HeapSort(ElemType A[],int len)
{
	int i;
	BuildMaxHeap(A,len);//建立大顶堆
	for(i=len;i>1;i--)
	{
		swap(A[i],A[1]);
		AdjustDown(A,1,i-1);
	}
}
//----------------上为王道书，下为老师上课所写代码--------------------------------------
//调整子树
void AdjustDown1(ElemType A[], int k, int len)
{
	int dad = k;
	int son = 2 * dad + 1; //左孩子下标
	while (son<=len)
	{
		if (son + 1 <= len && A[son] < A[son + 1])//看下有没有右孩子，比较左右孩子选大的
		{
			son++;
		}
		if (A[son] > A[dad])//比较孩子和父亲
		{
			swap(A[son], A[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort1(ElemType A[], int len)
{
	int i;
	//建立大顶堆
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown1(A, i, len);
	}
	swap(A[0], A[len]);//交换顶部和数组最后一个元素
	for (i = len - 1; i > 0; i--)
	{
		AdjustDown1(A, 0, i);//剩下元素调整为大根堆
		swap(A[0], A[i]);
	}
}

//《王道C督学营》课程
//选择排序与堆排序
int main()
{
	SSTable ST;
	ElemType A[10]={ 64, 94, 95, 79, 69, 84, 18, 22, 12 ,99};
	ST_Init(ST,10);//初始化
	memcpy(ST.elem,A,sizeof(A));
	ST_print(ST);
	//SelectSort(ST.elem,10);
	//HeapSort(ST.elem, 9);//王道书零号元素不参与排序
	HeapSort1(ST.elem,9);//所有元素参与排序
	ST_print(ST);
	system("pause");
}