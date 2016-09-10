#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

Status InitialList(LinkList &L,int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	LinkList q;
	p = L;
	int i;
	ElemType elem;
	for ( i = 0; i < n; i++)
	{
		scanf("%d",&elem);
		q = (LinkList)malloc(sizeof(LNode));
		q->data = elem;
		p->next = q;
		q->next = NULL;
		p = q;
	}
	return OK;
}
void LoadList(LinkList L) {
	L = L->next; //指向第一个元素
	while (L!=NULL)
	{
		printf("%d ",L->data);
		L = L->next;
	}
	printf("\n");
}
Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
													   // 在带头结点的单链线性表L的第i个元素之前插入元素e
	LinkList p, s;
	p = L;
	int j = 0;
	while (p && j < i - 1) {  // 寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;      // i小于1或者大于表长
	s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
	s->data = e;  s->next = p->next;      // 插入L中
	p->next = s;
	return OK;
} // LinstInsert_L
void Convert(LinkList first,LinkList &result) {
	ElemType elem;
	first = first->next;
	while (first!=NULL)
	{
		elem = first->data;
		ListInsert_L(result,1,elem);
		first = first->next;//总是插入第一个
	}
}
Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
														// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1) {  // 寻找第i个结点，并令p指向其前趋
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;  // 删除位置不合理
	q = p->next;
	p->next = q->next;           // 删除并释放结点
	e = q->data;
	free(q);
	return OK;
} // ListDelete_L
int main() {
	int n;
	LinkList list=NULL,result=NULL;
	scanf("%d",&n);
	InitialList(list,n);
	InitialList(result,0);
	Convert(list,result);
	printf("The List is:");
	LoadList(list);
	printf("The turned List is:");
	LoadList(result);
	return 0;
}