//读取10个整型数据12 63 58 95 41 35 65  0 38 44，然后通过归并排序，
//对该组数据进行排序，输出有序结果，每个数的输出占3个空格
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void PrintInt(int data[])
{
	int i;//计数输出
	for (i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

void Merge(int data[], int low, int mid, int high)
{
	//将元素复制到新的数组中，将值暂存
	int temp[10] = { 0 };
	int k;//用以复制计数
	for (k = low; k <= high; k++)
	{
		temp[k] = data[k];
	}

	int i = low;//指向前半数组的第一个值
	int j = mid + 1;//指向后半数组的第一个值
	for (k = i; i <= mid && j <= high; k++)//合并两个有序数组
	{
		if (temp[i] > temp[j])//前半数组中的元素＞后半数组中的元素
		{
			data[k] = temp[j];//将小的填入有序序列中
			j++;//往后扫描后半数组,也是循环结束条件
		}
		else//前半数组中的元素<后半数组中的元素
		{
			data[k] = temp[i];//将小的填入有序序列中
			i++;//往后扫描前半数组，也是循环结束条件
		}
	}//for循环

	//前半数组未检测完（会出现后半数组全比前半数组某个元素小的情况），将剩余元素复制到有序数组中
	while (i <= mid)
	{
		data[k] = temp[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		data[k] = temp[j];
		j++;
		k++;
	}
}

//归并排序
//思想：将两个有序表，合成一个新的有序表，有序表内元素个数[1,2,4,8...]
void MergeSort(int data[], int low, int high)
{
	//共10个元素，下标从0-9
	if (low < high)//有两个元素，0，1时，不会进入递归，将直接合并
	{
		int mid = (low + high) / 2;//将表分为两部分，mid=4 每次都要划分
		MergeSort(data, low, mid);//将前半部分变为有序表
		MergeSort(data, mid + 1, high);//将后半部分变为有序表
		Merge(data, low, mid, high);//合并两个有序表
	}
}

int main()
{
	int data[10] = { 0 };//接收输入数据
	int i;//计数输入

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}
	//归并排序
	MergeSort(data, 0, 9);
	PrintInt(data);
	return 0;
}