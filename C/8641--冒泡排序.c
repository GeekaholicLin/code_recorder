#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
	在循环的时候犯错！
	应该是总长度在减少，而不是i在增加，因为是要不比较后面排序好的
	还有一个坑处在于flag的设置
*/
void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
void BubbleSort(int *p,int n) {
	int flag = 0;//循环是否结束的标准
	int length = n;
	for (int i = 1; i <=n-1&&flag==0; length--)//这里是n--!!!!而不是i++
	{
		flag = 1;//假设修改
		for (int j = i; j <=n-1; j++)
		{
			
			if (p[j]>p[j+1])
			{
				flag = 0;//说明有循环
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
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

	BubbleSort(p,n);
	return 0;
}