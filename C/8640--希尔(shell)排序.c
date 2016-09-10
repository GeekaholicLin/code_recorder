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
void shellSort(int *p,int n) {
	int d = n / 2;//增量
	//相对于直接插入而言，增加了
	//1.d!=0的循环
	//2.将增量是1的地方改为d
	//比如i=2-->i=d+1
	//比如p[0]<p[j-1]-->p[0]<p[j-d]（此时要增加j-d>0的判断，防止越界）
	//移动量j = j-1;-->j = j-d
	while (d!=0)
	{
		for (int i = d+1 ; i <=n; i++)
		{
			int j = i;
			p[0] = p[i];
			while (p[0]<p[j-d]&&j-d>0)
			{
				p[j] = p[j - d];
				j = j - d;
			}
			p[j] = p[0];
		}
		printArray(p, n);
		d = d / 2;
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

	shellSort(p,n);
	return 0;
}