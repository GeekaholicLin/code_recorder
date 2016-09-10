#include <stdio.h>
#include <string.h>
#include <malloc.h>



/*
用函数实现堆排序，并输出每趟排序的结果
堆调整算法应该为小根堆
*/
void printArray(int *p, int n) {
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
//最重要的函数是堆调整
void HeapAdjust(int*p,int r,int size) {
	int MaxIndex = r;//初始化为该节点
	int lchild = 2 * r;//左子节点序号
	int rchild = 2 * r + 1;//右子节点序号
	if (r<=size/2)//说明是非叶子节点，//非叶节点最大序号值为size/2 
	{
		//对于该节点而言，选出最小的minIndex
		if (p[lchild]>p[MaxIndex]&&lchild<=size)
		{
			MaxIndex = lchild;//更新
		}
		if (p[rchild] > p[MaxIndex]&&rchild<=size)
		{
			MaxIndex = rchild;
		}
		//交换父节点和minIndex节点，进行调整
		if (MaxIndex!=r)//判断在子树中是否还有更小的值(用下标是否相等来判断!!)
		{
			p[0] = p[MaxIndex];
			p[MaxIndex] = p[r];
			p[r] = p[0];
			HeapAdjust(p, MaxIndex, size);//递归调用，将打乱的子树重新堆调整，调整的根节点为MaxIndex，即原本最大的子树节点
		}
	}
}
void HeapBuild(int *p,int n) {
	for (int i = n/2; i>=1; i--)//非叶子节点。//非叶节点最大序号值为size/2 
	{
		HeapAdjust(p, i, n);
	}
}
void HeapSort(int *p,int n) {
	//先建立堆
	HeapBuild(p, n);
	printArray(p, n);
	for (int i = n; i>=2; i--)//从2开始
	{
		//第1个和最后一个交换数据（最后一个总是为i）
		p[0] = p[i];
		p[i] = p[1];
		p[1] = p[0];
		//调整堆
		HeapAdjust(p, 1,i-1);//注意这里的大小！！！
		printArray(p, n);//打印
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

	HeapSort(p, n);
	return 0;
}