#include<stdio.h>
#include<string.h>
#include <math.h>
#include<assert.h>
#define N 41
/*
 字符串碎片：
    输入包括一个字符串s,字符串s的长度length
	(1 ≤ length ≤ 50),s只含小写字母('a'-'z')
    输出一个整数,表示所有碎片的平均长度,四舍五入
	保留两位小数。
   例子: s = "aaabbaaac"
   所有碎片的平均长度 = (3 + 2 + 3 + 1) / 4 = 2.25
*/
void Average(char*str,float*num)
{
	assert(str!=NULL);
	if(strlen(str)<=0 || strlen(str)>50)
	{
		return ;
	}
	float count=0;
	char*p=str;
	while(*p != '\0')
	{
		if(*p!=*(p+1))
		{
			count++;
		}
		p++;
	}
	*num=strlen(str)/count;
}
/*
约瑟夫问题 :着名犹太历史学家 Josephus有过以下的故事：
在罗马人占领乔塔帕特后，39 个犹 太人与Josephus及他的
朋友躲到一个洞中，
39个犹太人决定宁愿死也不要被敌人到，于是决定了 一个
自杀方式，41个人排成一个圆圈，由第1个人 开始报数，
每报数到第3人该人就必
须自杀， 然后再由下一个重新报数，直到所有人都自杀
身亡为止。然而Josephus 和他的朋友并不想遵从，
Josephus要他的朋友先假装遵从，
他将朋友与自己安排 在第16个与第31个位置，于是逃过了
这场死亡游戏。 
   现将这个问题扩大，假设现在你与m个朋友不幸参与
   了这个游戏，你要如何保护你与你的朋友？
*/
void Die(int*arr,int m)
{
	int count=0;//死亡人数
	int die=m+2;//第die个人死亡
	int j=0;//下标
	int dienum=0;//计数器
  	while(count<(N-m-1))
	{
		if(arr[j]==0 && j<N)//活着
		{
			dienum++;
			if(dienum==die)
			{
				arr[j]=1;
				dienum=0;
				count++;
			}
			j++;
		}
		if(arr[j]==1 && j<N)
		{
			j++;
		}
		if(j==N)
		{
			j=0;
		}
	}
}
void SHOW(int*arr,int n)
{
	printf("站位");
	for(int i=0;i<N;i++)
	{
		if(arr[i]==0)
		{
			printf("%d  ",i+1);
		}
	}
	printf("\n");
}


int main()
{
	int m=4;//朋友
	int arr[N]={0};//0活着 1死了
	Die(arr,m);
	//SHOW(arr,N);


	char*str="aaabbaaac";
	char*str1="";
	char*str2=NULL;
	char*str3="abcdef";
	float num=0;
	Average(str3,&num);
	//printf("%f\n",num);
	return 0;
}