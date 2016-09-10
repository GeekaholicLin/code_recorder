#include <stdio.h>
#include <string.h>
#include <malloc.h>



/*
归并排序递归实现
*/
void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
//将有两个有序序列a[first...mid]和a[mid+1...last]合并。借助一个跟a大小一样的temp数组
void Merge(int*p,int first,int mid,int last,int * temp,int n) {
	int i = first;
	int j = mid + 1;
	int k = 1;
	while (i<=mid&&j<=last)
	{
		if (p[i]<p[j])
		{
			temp[k] = p[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = p[j];
			k++;
			j++;
		}
	}
	//如果没有遍历结束，全部放在temp中

	while (i<=mid)
	{
		temp[k] = p[i];
		k++;
		i++;
	}
	//如果没有遍历结束，全部放在temp中

	while (j<=last)
	{
		temp[k] = p[j];
		k++;
		j++;
	}
	//将temp中的结果放在p中
	for (int i = 1; i < k; i++)
	{
		p[i+first-1] = temp[i];//要计算出每个的第一个元素！否则数组越界
	}
	printArray(p, n);
}
void MergeSort(int*p,int first,int last,int n,int *temp) {
	int mid = 0;
	if (first<last)//递归的终结条件：子区间长度为1
	{
		mid = (first + last) / 2;
		//排序左边
		MergeSort(p, first, mid,n,temp);//让左边a[first...mid]有序
		//排序右边
		MergeSort(p, mid + 1, last, n,temp);//让右边[mid+1...last]有序
		//合并左右边
		Merge(p, first, mid, last,temp,n);
		

	}
}
int main() {

	int n;
	scanf("%d",&n);
	int *p = (int*)malloc(sizeof(int)*(n+1));
	int *temp = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <=n; i++)
	{
		scanf("%d", &p[i]);
	}

	MergeSort(p, 1, n, n, temp);
	//printArray(p, n);
	return 0;
}