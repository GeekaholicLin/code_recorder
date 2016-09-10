#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*
	每次外部循环，假设index为当前要比较的数值下标i
	然后进行判断，如果p[j]<p[i]，则更新下标
	选出最小值的下标
	然后交换值
*/

void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
void SelectionSort(int *p,int n) {
	int index = 0;
	int temp = 0;
	int i, j;
	for (i = 1; i <=n-1; i++)
	{
		index = i;//假设最小的下标为当前本身的下标
		for (j = i+1; j <=n; j++)
		{
			if (p[j]<p[i])
			{
				if (p[j] < p[index])//进行判断！注意不能判断小于等于！
				{
					index = j;//更新最小的下标
				}
			}
		}
		if (index!=i)
		{
			temp = p[index];//最小值
			p[index] = p[i];
			p[i] = temp;
		}
		

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

	SelectionSort(p,n);
	return 0;
}