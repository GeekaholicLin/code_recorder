#include <stdio.h>
#include <string.h>
#include <malloc.h>



/*
基数排序中重要的点
1.先拿到需要排序的数的最大值
2.求最大值的位数，也就是最多位数
3.循环次数为最大位数，从低位到高位取出，进行比较，对于该位的值使用count[10]数组进行计数
4.重点在于将比较的数按比较后的结果进行排序
5.一种比较奇妙的思想在于利用count数组中的计数，它的值代表的是该位数值的个数
 当把前后桶中的个数相加，赋值给后桶时，此时对应的count则是应该插入的temp[]暂存数据数组的下标
 每插入一个值，对应的count值减1，保证下次该位数值相同的插入到上一位置
 6.插入值应该从后往前进行！从后往前！从后往前！
*/
void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%03d ", p[i]);
	}
	printf("\n");
}
int getMaxBit(int*p, int n) {
	int maxData = p[1];
	int maxBit = 1;
	for (int i = 2; i <=n; i++)
	{
		if (maxData<p[i])
		{
			maxData = p[i];//获得最大的值
		}
	}
	while (maxData/=10)
	{
		maxBit++;
	}
	return maxBit;
}
void radixSort(int *p, int n) {
	int count[10] = { 0 };
	int *temp = (int *)malloc(sizeof(int)*(n + 1));
	int maxBit = getMaxBit(p, n);
	int i;
	int k;
	int radix = 1;
	//循环的位数
	for (int j = 1; j <=maxBit; j++)
	{
		for (i = 0; i <10; i++)
		{
			count[i] = 0;//计数器清0
		}
		//radix位的基数统计
		for (i = 1; i <=n; i++)
		{
			k = (p[i]/radix)%10;
			count[k]++;
		}
		//count数组的叠加，方便插入到temp
		//count数组的前一个的数值叠加到后一个
		for ( i = 1; i <10; i++)
		{
			count[i] = count[i] + count[i - 1];
		}
		//将数值插入到temp数组中
		//而该数值的基数对应的count即为插入的下标
		for ( i = n; i>=1; i--)
		{
			k = (p[i] / radix) % 10;//拿到基数
			temp[count[k]] = p[i];
			count[k]--;//更新计数器
		}
		//复制temp数组中的值到p数组中
		for (i = 1; i <=n; i++)
		{
			p[i] = temp[i];
		}
		radix *= 10;

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

	radixSort(p,n);
	return 0;
}