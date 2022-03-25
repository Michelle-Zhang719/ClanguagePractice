//读取10个整型数据12 63 58 95 41 35 65  0 38 44，
//然后通过冒泡排序，快速排序，插入排序，分别对该组数据进行排序(从小到大），输出3次有序结果，每个数的输出占3个空格

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//交换两个元素
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void Printf_Int(int data[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

//冒泡排序
void BubbleSort(int data[], int len)
{
	int i;//计算外层循环，最多n-1次
	int j;//计算内层循环，从序列尾往前进行交换，从n-1开始（9）
	for (i = 0; i < len - 1; i++)
	{
		int flag = 0;//确定序列是否交换，1为交换
		for (j = len - 1; j = j; j--)
		{
			//第一次循环到此时，j=9，在序列尾
			if (data[j - 1] > data[j])
			{
				swap(data[j - 1], data[j]);//交换元素，使小的在前面
				flag = 1;//表示已经交换
			}
		}
		if (0 == flag)
		{
			return ;//代表已经排好顺序，函数结束
		}
	}
}

//快排中交换
int change(int kuai[], int left, int right)
{
	int k;//指向要被交换的元素（被交换前>data[right])
	int i;//用以遍历元素

	for (i = k = left; i < right; i++)
	{
		if (kuai[i] < kuai[right])
		{
			swap(kuai[i], kuai[k]);
			k++;
		}
	}
	swap(kuai[right], kuai[k]);//将最后一位与当前k交换
	return k;
}

//快速排序
void QuickSort(int kuai[], int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = change(kuai, low, high);
		QuickSort(kuai, pos+1, high);//后半部分排序
		QuickSort(kuai, low, pos-1);//前半部分排序
	}
}

void InsertSort(int elem[], int n)
{
	int i;//外层循环，指向要插入有序序列的元素
	int j;//内层循环，指向要插入的位置

	//从1-10个元素，需要插入的有2-10
	for (i = 2; i <= n; i++)
	{
		if (elem[i - 1] > elem[i])//elem[1]>elem[2]
		{
			elem[0] = elem[i];//用来暂存
			//查找插入位置，在排好的序列中，所以长度慢慢变大
			for (j = i - 1; elem[0] < elem[j]; j--)
			{
				elem[j + 1] = elem[j];//往后移
			}
			elem[j + 1] = elem[0];//插入该元素
		}
	}
}

int main()
{
	int data[10] = { 0 };
	int kuai[10] = { 0 };//用于快排
	int elem[11] = { 0 };//用于插入

	int i;//用以计数输入
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}


	memcpy(kuai, data, sizeof(data));
	for (i = 9; i > -1; i--)
	{
		elem[i + 1] = data[i];//elem[10]=data[9],elem[1]=data[0]
	}
	elem[0] = 0;//作为哨兵

	//冒泡排序
	//思想：分内外层循环，
	BubbleSort(data, 10);
	Printf_Int(data);//打印元素

	//快速排序
	//思想：分治，k始终指向被交换的元素，i往后遍历，i[last]是每次比较的对象
	QuickSort(kuai, 0, 9);
	Printf_Int(kuai);//打印元素

	//插入排序
	//思想：将每次入序列的元素，按照顺序插入已经拍好的序列中
	InsertSort(elem, 10);
	Printf_Int(kuai);//打印元素


	return 0;
}