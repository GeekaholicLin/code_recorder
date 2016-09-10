#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
难点在于循环位置的移动
还有插入点应该为low处，当然high处也是可以的
还有一点容易出错，就是low到high的范围是[1...(i-1)]
*/
void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
void BInsertSort(int *p, int n) {
	int low, mid, high, i;
	
	for ( i = 2; i <=n; i++)
	{
		low = 1; high = i-1;//坑！在[1..i-1]中查找位置
		while (low<=high)
		{
			mid = (low + high) / 2;
			p[0] = p[i];
			if (p[0] >= p[mid])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		//执行到这说明已经拿到该位置
		//该位置为low或者high+1
		//移动位置
		for (int j = i-1; j >= low; j--)
		{
			p[j+1] = p[j];
		}
		p[low] = p[0];
		printArray(p, n);
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

	BInsertSort(p,n);
	return 0;
}