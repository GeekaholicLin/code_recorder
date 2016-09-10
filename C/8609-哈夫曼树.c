#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct {
	int weight;//存储该节点的权重
	int parent;//存储该节点的父节点下标
	int lchild;//存储该节点的左孩子下标
	int rchild;//存储该节点的额右孩子下标
}TNode,*HuffTree;
typedef char** HuffCode;


//选出无父节点，无父节点，无父节点，并且权重最小的两个
//把权重小的节点下标赋值给lchild,权重大的赋值rchild
void SelectMin(HuffTree &tree,int n,int &child) {
	child = 1;
	for (int i = 1; i <=n; i++)
	{
		while (tree[child].parent!=0)
		{
			child++;
		}//找到第一个没有父级节点的，假设为最小，坑1！！！
		if (tree[i].parent==0)
		{
			if (tree[child].weight > tree[i].weight)
			{
				child = i;
			}
		}
		
	}
}
void HuffmanCodding(HuffTree &hufftree,HuffCode &huffCode,int* w,int n) {
	//建立哈夫曼树
	int lchild, rchild;
	int start;
	int m = 2 * n - 1;//总结点个数
	int i;
	//初始化n个子节点
	for (i = 1; i <=n; i++)
	{
		hufftree[i].weight = w[i];//权重赋值
		hufftree[i].parent = 0;//无父节点
		hufftree[i].lchild = 0;//无左孩子节点
		hufftree[i].rchild = 0;//无右孩子节点
	}
	//初始化非叶子节点
	for (i = n+1; i <=m; i++)
	{
		hufftree[i].weight = 0;
		hufftree[i].parent = 0;
		hufftree[i].lchild = 0;
		hufftree[i].rchild = 0;
	}
	//使用n+1至m的节点建立哈夫曼树
	for (i = n+1; i <=m; i++)
	{
		//这里从i-1开始，因为父节点也会不断地加入
		SelectMin(hufftree,i-1,lchild);//拿到权重小的左节点下标
		hufftree[lchild].parent = i;
		//printf("lchild = %d-->parent = %d\n",lchild, hufftree[lchild].parent);
		hufftree[i].lchild = lchild;
		SelectMin(hufftree,i-1,rchild);//拿到权重小的右节点下标
		//更新hufftree的各种数值
		hufftree[rchild].parent = i;
		//printf("rchild = %d-->parent = %d\n", rchild, hufftree[rchild].parent);
		hufftree[i].rchild = rchild;
		hufftree[i].weight = hufftree[lchild].weight + hufftree[rchild].weight;
		//printf("parent = %d-->lchild = %d-->rchild  = %d\n", hufftree[rchild].parent,lchild,rchild);
	}
	//逆向保存每个字符的哈夫曼编码
	char *temp;//保存
	
	//对于n个叶子节点
	for ( i = 1; i <=n; i++)
	{
		temp = (char*)malloc(sizeof(char)*n);//暂时性地保存编码，逆向保存
		temp[n - 1] = '\0';//最后保存的结束字符
		int c = i;
		int parentIndex;
		start = n-1;//从结束字符的前一位开始，start指向的是填入的那个空
		parentIndex = hufftree[i].parent;
		while (parentIndex!=0)//判断父节点是否有parent下标，是否为根节点
		{
			//printf("child = %d-->parent = %d\n", c, parentIndex);
			if (hufftree[parentIndex].lchild == c)//说明该子节点是其父节点的左孩子
			{
				temp[--start] = '0';//保存‘0’字符
			}
			if (hufftree[parentIndex].rchild == c)//说明该子节点是其父节点的右孩子
			{
				temp[--start] = '1';
			}
			c = parentIndex;//!!!!坑爹2，这个也要更新
			parentIndex = hufftree[parentIndex].parent;//迭代，更新为目前节点的父节点
		}
		//获取到总的编码后
		int length = n-start;//总长度
		huffCode[i] = (char*)malloc(sizeof(char)*length);
		
		//复制！！注意是从start开始复制
		strcpy(huffCode[i],&temp[start]);
		free(temp);
	}
}

int main() {
	HuffTree hufftree;
	HuffCode huffCode;
	int n,temp;
	int *w;//存储权重,0单元不存数据
	scanf("%d",&n);
	w = (int *)malloc(sizeof(int)*(n+1));
	hufftree = (HuffTree)malloc(sizeof(TNode)*(2*n));//2n的来自2n-1+1
	huffCode = (HuffCode)malloc(sizeof(char*)*(n+1));//这里注意是sizeof char*,先声明好一维数组的大小
	//读取权重
	for (int i = 1; i <=n; i++)
	{
		scanf("%d", &w[i]);
	}
	HuffmanCodding(hufftree,huffCode,w,n);
	for (int i = 1; i <=n; i++)
	{
		printf("%s",huffCode[i]);//输出哈夫曼编码
		printf("\n");
	}
	return 0;
}