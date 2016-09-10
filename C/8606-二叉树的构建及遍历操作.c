
/*
	此题的不同之处仅仅在于打印父节点的位置不同！！
	无论哪种遍历，都是先遍历左子树，然后才是右子树
	对于先序遍历而言，先打印父节点，然后把左孩子当作父节点，然后是把右孩子当作父节点
	对于中序遍历而言，先把左孩子当作父节点，然后再打印父节点，再是右孩子当作父节点
	对于后序遍历而言，先把左孩子当作父节点，然后是右孩子当作父节点，再打印父节点
*/
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;//左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
								  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
								  // 构造二叉链表表示的二叉树T。
	char ch;
	scanf("%c", &ch);
	if (ch == '#') T = NULL;
	else {
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch; // 生成根结点
		CreateBiTree(T->lchild);   // 构造左子树
		CreateBiTree(T->rchild);  // 构造右子树
	}
	return OK;
} // CreateBiTree


Status PrintElement(ElemType e) {  // 输出元素e的值
	printf("%c", e);
	return OK;
}// PrintElement


Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType)) {
	// 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
	//补全代码,可用多个语句
	if (T)
	{
			Visit(T->data);//先序遍历--先打印父节点
			PreOrderTraverse(T->lchild, Visit);//把左子树当作父节点，递归遍历
			//若该节点的左子树为空，则遍历右子树
			PreOrderTraverse(T->rchild, Visit);//把右子树当作父节点，递归遍历
			return OK;
	}
	else return ERROR;
} // PreOrderTraverse

Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType)) {
	// 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
	//补全代码,可用多个语句
	if (T)
	{	
			InOrderTraverse(T->lchild,Visit);	
			Visit(T->data);
			InOrderTraverse(T->rchild, Visit);
		    return OK;
	}
	else {
		return OK;
	}
} // InOrderTraverse

Status PostOrderTraverse(BiTree T, Status(*Visit)(ElemType)) {
	// 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
	//补全代码,可用多个语句
	if (T)
	{
		PostOrderTraverse(T->lchild,Visit);
		PostOrderTraverse(T->rchild,Visit);
		Visit(T->data);
		return OK;
	}
	else
	{
		return ERROR;
	}
} // PostOrderTraverse



int main()   //主函数
{
	//补充代码
	BiTree btree = NULL;
	CreateBiTree(btree);
	PreOrderTraverse(btree,PrintElement);
	printf("\n");
	InOrderTraverse(btree,PrintElement);
	printf("\n");
	PostOrderTraverse(btree,PrintElement);
	return 0;
}//main