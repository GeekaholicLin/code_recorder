#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

int CreateLink_L(LinkList &L, int n) {
	// 创建含有n个元素的单链表
	LinkList p, q;
	int i;
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;              // 先建立一个带头结点的单链表
	q = (LinkList)malloc(sizeof(LNode));
	q = L;
	for (i = 0; i<n; i++) {
		scanf("%d", &e);
		p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
		p->data = e;
		p->next = NULL;
		q->next = p;									  // 请补全代码
		q = p;
	}
	return OK;
}

int LoadLink_L(LinkList &L) {
	// 单链表遍历
	LinkList p = L->next;
	if (p==NULL)printf("The List is empty!"); // 请填空
	else
	{
		printf("The LinkList is:");
		while (p!=NULL)    // 请填空
		{
			printf("%d ", p->data);
			//___________________________    // 请填空
			p = p->next;
		}
	}
	printf("\n");
	return OK;
}

int LinkInsert_L(LinkList &L, int i, ElemType e) {
	// 算法2.9
	// 在带头结点的单链线性表L中第i个位置之前插入元素e
	// 请补全代码
	int j=0;
	LNode *s;
	LinkList p = L;//p指向头节点
	//难在循环和判断条件
	while (p&&j<i-1)
	{
		p = p->next;
		j++;
	}
				   //定位到第i-1个结点
	if (!p || j>i-1) return ERROR;//i小于1或者大于表长

	s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;


}

int LinkDelete_L(LinkList &L, int i, ElemType &e) {
	// 算法2.10
	// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
	// 请补全代码
	LinkList p = L;
	LinkList q;
	int j=0;
	//难在循环和判断条件
	while (p->next&&j<i-1)
	{
		p = p->next;
		j++;
	}//寻找第i个结点,并令p指向其前趋
	if (!p->next || j>i-1) return ERROR;//删除位置不合理，注意这里是next
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

int main()
{
	LinkList T;
	int a, n, i;
	ElemType x, e;
	printf("Please input the init size of the linklist:\n");
	scanf("%d", &n);
	printf("Please input the %d element of the linklist:\n", n);
	if (CreateLink_L(T, n))     // 判断链表是否创建成功，请填空
	{
		printf("A Link List Has Created.\n");
		LoadLink_L(T);
	}
	while (1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1: scanf("%d%d", &i, &x);
			if (!LinkInsert_L(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
			else printf("The Element %d is Successfully Inserted!\n", x);
			break;
		case 2: scanf("%d", &i);
			if (!LinkDelete_L(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
			else printf("The Element %d is Successfully Deleted!\n", e);
			break;
		case 3: LoadLink_L(T);
			break;
		case 0: return 1;
		}
	}
}

