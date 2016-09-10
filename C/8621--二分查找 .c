#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int Search_Bin(int* &ST,int n,int key) {
	int low, mid, height;
	low = 0;
	height = n - 1;
	while (low <= height)
	{
		mid = (height + low) / 2;//这里是相加除以2
		if (ST[mid] == key)
		{
			return mid;
		}
		else if (ST[mid]<key)
		{
			low = mid + 1;
		}
		else
		{
			height = mid - 1;
		}

	}
	
	return -1;
}
int main() {
	
	int n;
	int key;
	int *ST;
	scanf("%d",&n);
	ST = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&ST[i]);//保存数组
	}
	scanf("%d",&key);//获取key数值
	int result = Search_Bin(ST,n,key);
	if (result>=0)
	{
		printf("The element position is %d.", result);
	}
	else
	{
		printf("The element is not exist.");
	}
	return 0;
}