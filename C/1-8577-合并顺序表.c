#include<stdio.h>
#include<malloc.h>
#define OK 1 
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
/*
ADT SqList{
	//结构
	typedef struct{
		ElemType *elem;//线性表元素
		int length;//线性表的个数
		int listsize;//线性表的空间长度
	}SqList
	//操作方法
	//初始化--Status InitList_Sq(SqList &L)
	//遍历(读取)--int Load_Sq(SqList &L)
	//增加(插入)元素--Status ListInsert_Sq(SqList &L, int position, ElemType ele)
	//删除--ElemType ListDelete_Sq(SqList &L, int position, ElemType &e)
	
}
*/
typedef struct {
	ElemType *elem;//线性表元素集合
	int length;//线性表的个数
	int listsize;//线性表的空间长度
} SqList;

int InitList_Sq(SqList &L) {
	// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
	// 请补全代码
	L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (!L.elem) return ERROR;//申请失败，返回错误
	L.length = 0; //线性表个数为0
	L.listsize = LIST_INIT_SIZE;//线性表的初始空间
	return OK;
}

int Load_Sq(SqList &L) {
	// 输出顺序表中的所有元素
	int i;
	if (L.length == 0) printf("The List is empty!"); // 请填空
	else {
		//printf("The List is: ");
		for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]); // 请填空
	}
	printf("\n");
	return OK;
}

//添加是先右移，再插入
int ListInsert_Sq(SqList &L, int i, int e) {
	// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
	// i的合法值为1≤i≤L.length +1
	// 请补全代码
	ElemType *p, *q;
	//判断是否合法
	if (i < 1 || i > L.length + 1) return ERROR;
	//判断是否超出，超出动态分配空间
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) return ERROR;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]); //q为插入的位置
	//p为最后的位置
	for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p; //插入位置及以后的元素右移
	*q = e; //插入e
	++L.length;
	return OK;
}
//删除是先删除，再左移
int ListDelete_Sq(SqList &L, int i, int &e) {
	// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
	// i的合法值为1≤i≤L.length
	// 请补全代码
	if (i < 1 || i > L.length) {
		return ERROR;
	}//超出
	ElemType *p = &(L.elem[i - 1]);//P为删除元素的位置
	e = *p;//被删除的值付给e
	ElemType *q = &(L.elem [L.length - 1]);
	for (p++; p <= q; ++p) *(p - 1) = *p;
	L.length--;
	return e;
}
void MergeList(SqList sq_First,SqList sq_Second,SqList &sq_Result) {
	ElemType *ptr = NULL;
	ElemType elem;
	int i, j, r, loop, loopLength, num;
	i = 1;//sq_First的第一个元素
	j = 1;//sq_Second的第一个元素
	r = 1;//初始化sq_Result的位置，插入位置
	while (i <= sq_First.length&&j <= sq_Second.length) {
		if (sq_First.elem[i - 1] >= sq_Second.elem[j - 1]) {
			elem = sq_Second.elem[j - 1];//拿到小元素
			j++;
		}
		else {
			elem = sq_First.elem[i - 1];//拿到小元素的地址
			i++;
		}
		ListInsert_Sq(sq_Result, r, elem);
		r++;
	}
	//判断是哪一个结束
	//第一个结束
	if (i > sq_First.length) {
		loop = j;
		loopLength = sq_Second.length;
		ptr = &sq_Second.elem[j - 1];//获取1结束时的2开头元素的地址，记得减一
	}
	//第二个结束
	else {
		loop = i;
		loopLength = sq_First.length;
		ptr = &sq_First.elem[i - 1];//获取2结束时的1开头元素的地址，记得减一
	}
	//将未结束的插入sq_Result
	for (; loop <= loopLength; loop++) {
		elem = *ptr;
		ListInsert_Sq(sq_Result, r, elem);
		r++;
		ptr++;
	}
}




int main() {
	SqList sq_First,sq_Second,sq_Result;
	ElemType *ptr = NULL;
	ElemType elem;
	InitList_Sq(sq_First);
	InitList_Sq(sq_Second);
	InitList_Sq(sq_Result);
	int i,j,r,loop,loopLength,num;
	scanf("%d",&num);
	for (i = 1; i < (num+1); i++) {
		scanf("%d",&elem);
		ListInsert_Sq(sq_First,i,elem);
	}
	scanf("%d", &num);
	for (i = 1; i < (num + 1); i++) {
		scanf("%d", &elem);
		ListInsert_Sq(sq_Second, i, elem);
	}
	MergeList(sq_First,sq_Second,sq_Result);
	printf("List A:");
	Load_Sq(sq_First);
	printf("List B:");
	Load_Sq(sq_Second);
	printf("List C:");
	Load_Sq(sq_Result);
	return 0;
}