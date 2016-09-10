#include "stdio.h"
#include "stdlib.h"
#include "iostream.h"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255 	//用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1];	//0号单元存放串的长度

void get_next(SString T, int next[]) {
	// 算法4.7
	// 求模式串T的next函数值并存入数组next
	// 请补全代码
	int i = 1;
	int j = 0;
	next[i] = 0;
	while (i<T[0])
	{
		if (j==0||T[i]==T[j])
		{
			j++;
			i++;
			next[i] = j;//注意这里的赋值
		}
		else
		{
			j = next[j];
		}
	}



}

int Index_KMP(SString S, SString T, int pos) {
	// 算法4.6
	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
	// KMP算法。请补全代码
	int i = pos;//i指向主串字符
	int j = 1;//j指向子串字符
	int next[MAXSTRLEN] = {0};
	get_next(T,next);
	while (i<=S[0]&&j<=T[0])
	{
		if (j==0||S[i]==T[j])
		{
			i++;
			j++;

		}//如果两个指针指向的字符相同，继续移动指针
		else
		{
			j = next[j];//滑动子串
		}
		
	}
	//比较完成之后，如果j>T[0],说明匹配的长度大于子串的长度，匹配成功
	//返回匹配的位置，即目前的i减去子串的长度-->i-T[0]
	if (j>T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;//不匹配返回0
	}

}
void main()
{
	SString T, S;
	int i, j, n;
	char ch;
	int pos;
	scanf("%d", &n);    // 指定n对需进行模式匹配的字符串
	ch = getchar();
	for (j = 1; j <= n; j++)
	{
		ch = getchar();
		for (i = 1; i <= MAXSTRLEN && (ch != '\n'); i++)    // 录入主串
		{
			S[i] = ch;
			ch = getchar();
		}
		S[0] = i - 1;    // S[0]用于存储主串中字符个数
		ch = getchar();
		for (i = 1; i <= MAXSTRLEN && (ch != '\n'); i++)    // 录入模式串
		{
			T[i] = ch;
			ch = getchar();
		}
		T[0] = i - 1;    // T[0]用于存储模式串中字符个数
		pos = Index_KMP(S,T,1);    // 请填空
		printf("%d\n", pos);
	}
}