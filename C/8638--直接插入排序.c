#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
	边移动边插入，而且要一直拿0元素的值和其他值进行比较
	而不是像课本一样，先找到再移动再插入！
*/
void printArray(int *p,int n) {
	for (int i = 1; i <=n; i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}
void InsertSort(int *p,int n) {
	//从2开始
	for (int i =2; i <=n; i++)
	{
		int j = i;
		p[0] = p[j];//0单元为key值，一定要保存！！
		//拿第i个数和【1...i-1】个数相比
		while (p[0]<p[j - 1])//循环迭代！用保存的值进行比较，因为会p[j]会被覆盖
			{
				p[j] = p[j - 1];
				j--;
			}
			p[j] = p[0];//此时j指向的是当前要插入的位置，赋值插入
		printArray(p, n);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	int *p = (int *)malloc(sizeof(int)*n+1);
	for (int i = 1; i <=n; i++)
	{
		scanf("%d",&p[i]);
	}
	InsertSort(p,n);
	return 0;
}