#include<malloc.h> 
#include<stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
/*
	二位数的加减乘除
*/
typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base) return ERROR;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S, SElemType e)
{
	// 在栈S中插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base) return ERROR;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

Status GetTop(SqStack S, SElemType &e)
{
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

int StackLength(SqStack S)
{
	// 返回栈S的元素个数
	int i;
	i = S.top - S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
	// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType));
	p = S.top;
	if (S.top == S.base)printf("The Stack is Empty!");
	else
	{
		printf("The Stack is: ");
		p--;
		while (p >= S.base)
		{
			printf("%d ", *p);
			p--;
		}
	}
	printf("\n");
	return OK;
}
//编写比较函数
/*
拿栈顶操作符和即将入栈操作符进行比较
返回值：int--1，0，-1
*/

int compare(SElemType first, SElemType next) {
	//int result;
	switch (first)
	{
	case '+':
	case '-':
		if (next == '+' || next == '-' || next == ')' || next == '=')
		{
			return 1;
		}
		else return -1;
		break;
	case '*':
	case '/':
		if (next == '(')
		{
			return -1;
		}
		else return 1;
		break;
	case '(':
		if (next == ')')
		{
			return 0;
		}
		else return -1;
		break;
	case ')':
		return 1;
		break;
	case '#':
		if (next == '=')
		{
			return 0;
		}
		else return -1;
		break;
	}
}

//编写计算函数
int canculate(SElemType first, SElemType second, SElemType op) {
	int result = -1;
	switch (op)
	{

	case '+':result = first + second; break;
	case '-':result = first - second; break;
	case '*':result = first * second; break;
	case '/':result = first / second; break;
	default:break;
	}
	return result;
}
//编写main函数
//维护两个栈，一个为op，用来保存操作符号，一个为num，用来保存操作数
int main() {
	SqStack opStack, numStack;
	InitStack(opStack);
	InitStack(numStack);//初始化两个栈
	Push(opStack, '#');
	SElemType op, nextop;//获取弹出的操作符
	SElemType first = -1, second = -1, result = -1;//获取弹出的操作数
	SElemType ch;
	
	ch = getchar();
	GetTop(opStack, op);
	while (ch != '=' || op != '#')//如果不结束，一直获取字符
	{
		/*
			这里很关键，对数字进行移动
		*/
		if (ch >= '0'&&ch <= '9')
		{
			SElemType temp = 0;//清0
			while (ch >= '0'&&ch <= '9')
			{
				temp = temp * 10 + (ch-'0');
				ch = getchar();
			}
			Push(numStack, temp);
		}
		else
		{
			switch (compare(op, ch))
			{
				//当下一个操作字符特权高于栈顶时,直接压栈
			case -1:
				Push(opStack, ch);
				ch = getchar();//获取下一个字符
				break;
				//当特权相等时，弹栈
			case 0:
				Pop(opStack, op);
				ch = getchar();//获取下一个字符
				break;
				//当下一个操作符特权小于栈顶时，计算并压栈
			case 1:
				Pop(numStack, second);//首先获取的是第二个操作数
				Pop(numStack, first);//获取第一个操作数
				Pop(opStack, op);//获取操作符
				result = canculate(first, second, op);
				Push(numStack, result);
				//不能将操作数压栈，要进行新一轮比较
				//Push(opStack, ch);
				break;
			}
		}

		GetTop(opStack, op);
	}
	GetTop(numStack, result);//获取栈中的第一个元素
	printf("%d\n", result);
	return 0;
}