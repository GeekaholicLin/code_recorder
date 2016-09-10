#include <stdio.h>
#include <string.h>
#include <malloc.h>


void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
int parting(int*p,int low,int high,int n) {
	int keyIndex = low;//默认支点为第一个元素
	p[0] = p[keyIndex];//保存支点在0元素
	while (low<high)
	{
		while (p[high]>=p[0]&&low<high)
		{
			high--;
		}//从后往前找，找到一个小于支点的值的下标
		p[low] = p[high];//赋值

		while (p[low]<=p[0]&&low<high)
		{
			low++;
		}//从前玩后找，找到一个大于支点的值的下标
		p[high] = p[low];//赋值
	}//当low = high时退出
	p[low] = p[0];//哨兵赋值
	printArray(p, n);
	return low;//返回支点所在位置，low和high都是指向这个位置
}
void QuickSort(int *p,int low,int high,int n) {
	if (low<high)
	{
		int keyIndex = parting(p, low, high, n);//一次快速二分后的支点下标
		QuickSort(p, low, keyIndex - 1, n);//左部遍历
		QuickSort(p, keyIndex + 1, high, n);//右部遍历
	}
	
}
int main() {

	int n;
	scanf("%d",&n);
	int *p = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 1; i <=n; i++)
	{
		scanf("%d", &p[i]);
	}

	QuickSort(p,1,n,n);
	return 0;
}