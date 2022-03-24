#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* SString;
//暴力比对
//S  abcabaaabaabcac
//T  abaabcac
//为什么从1位置开始比较，因为0号位置存储了字符串的长度
int Index(SString S,SString T)
{
	int i=1,j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(S[i]==T[j])
		{
			++i,++j;//继续比较后续字符
		}else{
			i=i-j+2;j=1;//指针后退重新开始匹配
		}
	}
	if(j>T[0]) return i-T[0];//匹配成功
	else return 0;
}
//i游标，遍历T
void get_next(char T[],int next[])
{
	int i=1;
	next[1]=0;//恒为零
	int j=0;
	//abaabcac
	while(i<T[0])//T[0]中记录了字符串的长度
	{
		if(j==0||T[i]==T[j])//j==0，说明再次回到了开头
		{
			++i;++j;
			next[i]=j;//记录出现重复的位置
		}else{
			j=next[j];//不相同，找个位置重新比较
		}
	}
}
//S  abcabaaabaabcac
//T  abaabcac
int KMP(char S[],char T[],int next[],int pos)
{
	int i=pos;//开始查找的起始位置
	int j=1;
	while(i<=S[0]&&j<=T[0])
	{
		if(j==0||S[i]==T[j]){//相等各自加加，往后走
			++i;
			++j;
		}
		else//不等，就回退next[j]的位置
			j=next[j];
	}
	if(j>T[0])//说明比对成功
		return i-T[0];
	else
		return 0;
}
//《王道C督学营》课程
//简单模式匹配 与  KMP（KMP考的概率极低）
int main()
{
	//字符串进行初始化
	char S[256];
	char T[10];
	int next[10];
	int pos;
	S[0]=strlen("abcabaaabaabcac");//strlen里有多少个字符
	strcpy(S+1,"abcabaaabaabcac");
	T[0]=strlen("abaabcac");
	strcpy(T+1,"abaabcac");
	pos=Index(S,T);
	if(pos)
	{
		printf("匹配成功，位置为%d\n",pos);
	}else{
		printf("未匹配\n");
	}
	get_next(T,next);
	pos=KMP(S,T,next,1);
	if(pos)
	{
		printf("匹配成功，位置为%d\n",pos);
	}else{
		printf("未匹配\n");
	}
	system("pause");
}
