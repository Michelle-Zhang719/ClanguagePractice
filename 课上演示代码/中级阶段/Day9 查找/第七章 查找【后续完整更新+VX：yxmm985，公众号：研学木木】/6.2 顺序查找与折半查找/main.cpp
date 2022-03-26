#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//整型指针
	int TableLen;//存储动态数组里边元素的个数
}SSTable;

int Search_Seq(SSTable ST,ElemType key)
{
	ST.elem[0]=key;//让零号元素作为哨兵
	int i;
	for(i=ST.TableLen-1;ST.elem[i]!=key;--i);
	return i;
}
//init进行了随机数生成
void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len+1;//多申请了一个位置,为了存哨兵
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));//随机数生成
	for(i=0;i<ST.TableLen;i++)//为啥这里零号位置也随机了数据，为折半查找服务
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
//时间复杂度  logn
int Binary_Search(SSTable L,ElemType key)
{
	int low=0,high=L.TableLen-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(L.elem[mid]==key)
			return mid;//等于就找到了
		else if(L.elem[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int compare(const void *left,const void *right)//left，right是任意两个元素的地址值
{
	return *(ElemType*)left-*(ElemType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//从大到小
}
//《王道C督学营》课程
//顺序查找 与  折半查找
int main()
{
	SSTable ST;
	ElemType key;
	int pos;//存储查询元素的位置
	ST_Init(ST,10);
	ST_print(ST);
	printf("请输入要搜索的key值:\n");
	scanf("%d",&key);
	pos=Search_Seq(ST,key);
	if(pos)
	{
		printf("查找成功 位置为 %d\n",pos);
	}else{
		printf("查找失败\n");
	}
	qsort(ST.elem,ST.TableLen,sizeof(ElemType),compare);//qsort实现的是快排
	ST_print(ST);
	printf("二分查找，请输入要搜索的key值:\n");
	scanf("%d",&key);
	//有序数组
	pos=Binary_Search(ST,key);//二分查找，也叫折半查找
	if(pos!=-1)
	{
		printf("查找成功 位置为 %d\n",pos);
	}else{
		printf("查找失败\n");
	}
	system("pause");
}
