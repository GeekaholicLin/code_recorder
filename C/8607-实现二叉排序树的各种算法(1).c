#include <stdio.h>
#include <malloc.h>
#define Status int
#define OK 1
#define ERROR 0
#define STACKINITIALSIZE 100
#define STACKINCRESEMENT 10
#define QUEUEINITIALSIZE 100
#define ElementType BinaryTree
/*二叉树结构体*/
typedef struct TreeNode {
	int key;
	struct TreeNode *lchild;
	struct TreeNode *rchild;//左右孩子指针
}*BinaryTree,TreeNode;
/*栈的结构体*/
typedef struct {
	ElementType *base;
	ElementType *top;
	int stacksize;
}Stack;
/*队列的结构体*/
typedef struct {
	ElementType *base;
	int first;
	int last;
} Queue;
/*Stack 初始化*/
Status StackInitial(Stack &s) {
	s.base = (ElementType*)malloc(sizeof(ElementType)*STACKINITIALSIZE);
	if (!s.base) return ERROR;
	s.stacksize = STACKINITIALSIZE;
	s.top = s.base - 1;
	return OK;
}
/*Stack 压栈操作*/
Status Push(Stack &s, ElementType elem) {
	if (s.top - s.base + 1 == s.stacksize) {
		s.base = (ElementType*)realloc(s.base, sizeof(ElementType)*(s.stacksize + STACKINCRESEMENT));
		if (!s.base)return ERROR;//分配失败
		s.top = s.base + s.stacksize - 1;
		s.stacksize += STACKINCRESEMENT;
	}
	s.top++;
	*s.top = elem;
	return OK;
}
/*Stack 弹栈操作*/
Status Pop(Stack &s, ElementType &elem) {
	if (s.top + 1 == s.base) {
		return ERROR;
	}
	else {
		elem = *s.top;
		s.top--;
		return OK;
	}
}
/*Stack 栈长度*/
int StackLength(Stack s) {
	return s.top - s.base + 1;
}

/*Queue 队列的初始化*/
Status InitalQueue(Queue &q) {
	q.base = (BinaryTree*)malloc(sizeof(BinaryTree)*QUEUEINITIALSIZE);
	if (!q.base) return ERROR;
	q.first = 1;
	q.last = 0;
	return OK;

}
/*Queue 入队操作*/
Status EnQueue(Queue &q, ElementType elem) {
	q.last++;

	int next = q.last % QUEUEINITIALSIZE;
	if (next == 0) {
		next++;
	}
	q.base[next] = elem;
	return OK;
}
/*Queue 出队操作*/
Status DeQueue(Queue &q, ElementType &elem) {
	if (q.last + 1 == q.first) {
		q.base = NULL;
		elem = NULL;
		return ERROR;
	}
	else {
		elem = q.base[q.first];
		q.first++;
		return OK;
	}
}
/*Queue 队列长度*/
int QueueLength(Queue q) {
	if (q.last - q.first + 1 >= QUEUEINITIALSIZE - 1) {
		return QUEUEINITIALSIZE - 1;
	}
	else {
		return (q.last - q.first + 1);
	}
}

/*Binary Search Tree 打印节点操作*/
Status printNode(BinaryTree btree) {
	printf("%d ", btree->key);
	return OK;
}
/*Binary Search Tree 节点查找操作*/
Status SearchBST(BinaryTree btree, int key, BinaryTree &f, BinaryTree &p) {
	if (!btree)
	{
		p = f;//指针回溯
		return ERROR;
	}
	else
	{
		if (btree->key == key)
		{
			p = btree;
			return OK;
		}
		else if (btree->key > key)
		{
			return SearchBST(btree->lchild, key, btree, p);//要有返回值，递归
		}
		else
		{
			return SearchBST(btree->rchild, key, btree, p);//要有返回值，递归
		}
		//return OK;
	}

}

/*Binary Search Tree 节点插入操作*/
Status InsertBST(BinaryTree &btree, int data) {
	BinaryTree p = NULL, node = NULL, f = NULL;
	//没有找到节点才可以插入
	if (!SearchBST(btree, data, f, p))
	{
		node = (BinaryTree)malloc(sizeof(TreeNode));
		node->key = data;
		node->lchild = NULL;
		node->rchild = NULL;
		if (!p)
		{
			btree = node;
		}
		else if (p->key>data)
		{
			p->lchild = node;
		}
		else
		{
			p->rchild = node;
		}
		return OK;
	}
	else return ERROR;
}
/*Bianry Search Tree 节点删除操作*/
/*1.若*p结点为叶子结点，即PL(左子树)和PR(右子树)均为空树。
由于删去叶子结点不破坏整棵树的结构，则只需修改其双亲结点的指针即可。

2.若*p结点只有左子树PL或右子树PR，此时只要令PL或PR直接成为其双亲结点*f的左子树
（当*p是左子树）或右子树（当*p是右子树）即可，作此修改也不破坏二叉排序树的特性。

3.若*p结点的左子树和右子树均不空。在删去*p之后，为保持其它元素之间的相对位置不变，
可按中序遍历保持有序进行调整。比较好的做法是，找到*p的直接前驱（或直接后继）*s，
用*s来替换结点*p，然后再删除结点*s。*/
void deleteNode(BinaryTree &btree, BinaryTree f) {
	BinaryTree point;
	if (!btree->lchild)//左子树为空
	{
		f->rchild = btree->rchild;
		free(btree);
	}
	else if (!btree->rchild)//右子树为空
	{
		f->lchild = btree->lchild;
		free(btree);
	}
	else//左右子树都不为空
	{
		point = btree->lchild;//左转
		f = btree;
		while (point->rchild)//一直到右，找到左子树最大的值
		{
			f = point;
			point = point->rchild;
		}
		//复制
		btree->key = point->key;
		deleteNode(point, f);//删除左子树最大的值的节点
	}
}
Status deleteBST(BinaryTree btree, int key) {
	BinaryTree p, f;
	if (!SearchBST(btree, key, f, p))
	{
		return ERROR;//无法找到关键字，删除失败
	}
	else
	{
		deleteNode(p, f);
	}
}
/*Bianry Search Tree 前序遍历递归实现*/
void preOrder(BinaryTree btree, Status(*visit)(BinaryTree)) {
	if (btree != NULL)
	{
		visit(btree);
		preOrder(btree->lchild, visit);
		preOrder(btree->rchild, visit);
	}

}
/*Bianry Search Tree 中序遍历递归实现*/
void InOrder(BinaryTree btree, Status(*visit)(BinaryTree)) {
	if (btree != NULL)
	{
		InOrder(btree->lchild, visit);
		visit(btree);
		InOrder(btree->rchild, visit);
	}
}
/*Bianry Search Tree 前序遍历非递归实现*/
void InOrderSecond(BinaryTree btree) {
	Stack bStack;
	//BinaryTree p =NULL;
	StackInitial(bStack);//初始化栈
	while (btree || StackLength(bStack)!=0) {
		while (btree != NULL) {
			Push(bStack, btree);
			btree = btree->lchild;
		}
		if (StackLength(bStack) != 0) {
			Pop(bStack, btree);
			printf("%d ", btree->key);
			btree = btree->rchild;
		}

	}
	printf("\n");
}
/*Bianry Search Tree 后序遍历递归实现*/
void PostOrder(BinaryTree btree, Status(*visit)(BinaryTree)) {
	if (btree != NULL)
	{
		PostOrder(btree->lchild, visit);
		PostOrder(btree->rchild, visit);
		visit(btree);
	}
}
/*Bianry Search Tree 层次遍历操作*/
void LevelOrder(BinaryTree btree) {
	Queue bQueue;
	if (btree) {
		InitalQueue(bQueue);
		EnQueue(bQueue, btree);
		//不需要再判断btree是否为空
		while (QueueLength(bQueue)!=0) {	
			DeQueue(bQueue, btree);
			printf("%d ", btree->key);
			if (btree->lchild!=NULL) EnQueue(bQueue, btree->lchild);
			if (btree->rchild!=NULL) EnQueue(bQueue, btree->rchild);
		}
		printf("\n");
	}

}

/*主函数*/
int main() {
	int n;
	int data;
	int key;
	BinaryTree btree = NULL;
	BinaryTree f = NULL, p = NULL;
	scanf("%d", &n);
	//btree = (BinaryTree)malloc(sizeof(BinaryTree)*n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &data);
		InsertBST(btree, data);
	}
	preOrder(btree, printNode);//前序遍历递归实现
	printf("\n");
	InOrder(btree, printNode);//中序遍历递归实现
	printf("\n");
	PostOrder(btree, printNode);//后序遍历递归实现
	printf("\n");
	scanf("%d", &key);
	printf("%d\n", SearchBST(btree, key, f, p));//查找操作
	scanf("%d", &key);
	printf("%d\n", SearchBST(btree, key, f, p));//查找操作
	scanf("%d", &data);
	InsertBST(btree, data);
	preOrder(btree, printNode);//前序遍历递归实现
	printf("\n");
	InOrder(btree, printNode);//中序遍历递归实现
	printf("\n");
	PostOrder(btree, printNode);//后序遍历递归实现
	printf("\n");
	InOrderSecond(btree);//中序遍历非递归实现
	LevelOrder(btree);//层次遍历
	return 0;
}
