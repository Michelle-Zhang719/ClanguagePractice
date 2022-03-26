//读取10个整型数据12 63 58 95 41 35 65  0 38 44，
//然后通过选择排序，堆排序，分别对该组数据进行排序，输出2次有序结果，每个数的输出占3个空格

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

//打印函数
void PrintInt(int a[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

//交换函数
void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//选择排序
//思想：每一趟找到最小的元素，放到前面的位置，每一次确定一个元素的位置，n-1次后，序列确定
void SelectSort(int a[], int len)
{
	int i;//外层循环，记录找到第几趟
	int min;//记录当前最小元素位置
	int j;//内层循环，在未排序的序列中，找最小值的位置
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)//在i+1-n中找小值的位置
		{
			if (a[j] < a[min])
			{
				min = j;//更新最小值位置
			}
		}
		if (min != i)//若最小值位置被更新
		{
			swap(a[i], a[min]);
		}
	}
}

//堆排序
//思想：构建大堆树，将顶的元素与数组最后一位进行交换，下次构建len-1的大堆树。。。
void AdjustDown(int data[], int root, int len)
{
	int dad = root;
	int son = 2 * dad + 1; //左孩子下标
	while (son <= len)
	{
		//自上向下，看每个小树里，是否有比根大的元素，若有，则交换父亲和孩子。直至每个小树都查看过。
		if (son + 1 <= len && data[son] < data[son + 1])//看下有没有右孩子，比较左右孩子选大的
		{
			son++;
		}
		if (data[son] > data[dad])//比较孩子和父亲，孩子比父亲大
		{
			swap(data[son], data[dad]);//交换
			//继续往下找小树，进行遍历
			dad = son;
			son = 2 * dad + 1;//结束条件
		}
		else {
			break;
		}
	}
}

void HeapSort(int data[], int len)
{
	//复习！！！数组0-9存入元素，i位置的左孩子为2i+1,右孩子2i+2，i位置的父亲节点（i-1）/2，数组谁有叶子节点，i<=(n-1)/2
	int i;
	//创建大堆,[10个元素，0，1，2，3，4位置为根节点,len=9]
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown(data, i, len);
	}
	//交换顶部和数组最后一个元素,
	swap(data[0], data[len]);


	//再次构建len-1的大堆树
	for (i = len - 1; i > 0; i--)
	{
		AdjustDown(data, 0, i);//剩下元素调整为大根堆
		swap(data[0], data[i]);
	}
}


int main()
{
	int a[10] = { 0 };//选择排序的元素

	int i;//用于计数输入数据
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	int b[10] = { 0 };//推排序元素
	memcpy(b, a, sizeof(a));

	//选择排序
	SelectSort(a, 10);
	PrintInt(a);//打印元素

	//堆排序
	HeapSort(b, 9);
	PrintInt(b);//打印元素
	return 0;
}