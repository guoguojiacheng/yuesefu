#include<stdio.h>
#include<string.h>
#include <math.h>
#include<assert.h>
#define N 41
/*
 �ַ�����Ƭ��
    �������һ���ַ���s,�ַ���s�ĳ���length
	(1 �� length �� 50),sֻ��Сд��ĸ('a'-'z')
    ���һ������,��ʾ������Ƭ��ƽ������,��������
	������λС����
   ����: s = "aaabbaaac"
   ������Ƭ��ƽ������ = (3 + 2 + 3 + 1) / 4 = 2.25
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
Լɪ������ :������̫��ʷѧ�� Josephus�й����µĹ��£�
��������ռ���������غ�39 ���� ̫����Josephus������
���Ѷ㵽һ�����У�
39����̫�˾�����Ը��Ҳ��Ҫ�����˵������Ǿ����� һ��
��ɱ��ʽ��41�����ų�һ��ԲȦ���ɵ�1���� ��ʼ������
ÿ��������3�˸��˾ͱ�
����ɱ�� Ȼ��������һ�����±�����ֱ�������˶���ɱ
����Ϊֹ��Ȼ��Josephus ���������Ѳ�������ӣ�
JosephusҪ���������ȼ�װ��ӣ�
�����������Լ����� �ڵ�16�����31��λ�ã������ӹ���
�ⳡ������Ϸ�� 
   �ֽ�����������󣬼�����������m�����Ѳ��Ҳ���
   �������Ϸ����Ҫ��α�������������ѣ�
*/
void Die(int*arr,int m)
{
	int count=0;//��������
	int die=m+2;//��die��������
	int j=0;//�±�
	int dienum=0;//������
  	while(count<(N-m-1))
	{
		if(arr[j]==0 && j<N)//����
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
	printf("վλ");
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
	int m=4;//����
	int arr[N]={0};//0���� 1����
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