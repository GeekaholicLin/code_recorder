#include <stdio.h>
#include <string.h>
#include <malloc.h>



/*
归并排序非递归实现-
关键是步长成倍增加，如果步长大于或等于总数组长度说明合并结束！
合并Merge函数与非递归的一样，不需要改动
重要的几个参数是first,mid,high,int *p ,int *temp
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
	//将temp中的结果放在p中的相应位置，p中的相应位置，p中的相应位置
	for (int i = 1; i < k; i++)
	{
		p[i+first-1] = temp[i];//要计算出每个的第一个元素！否则数组越界
	}
}
/*
二、.两路归并排序非递归实现
1.把 n 个记录看成 n 个长度为 l 的有序子序列；
2.进行两两归并使记录关键字有序，得到 n/2 个长度为 2 的有序子序列；
3.重复第2步直到所有记录归并成一个长度为 n 的有序子序列为止。
*/
void MergeSort(int*p,int n,int *temp) {
	int first, mid, last;
	int step = 1;
	for ( step = 1; step < n; step*=2)
	{
		for (int i = 1; i <=n; i+=2*step)//i=i+2*step表示跳到下一个步长为step的需要合并的区间
		{
			first = i;
			last = i + 2 * step - 1;
			mid = (first + last) / 2;
			
			if (last>n)
			{
				last = n;//最多为n，肯定不能越界，用于防止步长不足的区间
						//所以last应该为n和加上步长的最小值，Min(j+2*i-1,h)
			}
			Merge(p, first, mid, last, temp, n);
		}
		printArray(p, n);
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

	MergeSort(p,n,temp);
	return 0;
}