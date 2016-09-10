#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
	QElemType *base; // 初始化的动态分配存储空间
	int front; // 头指针,若队列不空,指向队列头元素
	int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
}SqQueue;

Status InitQueue(SqQueue &Q)
{
	// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
	Q.base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if (!Q.base) exit(1);
	Q.rear = Q.front = 0;
	return OK;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
	// 插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
	// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
	// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
	if (Q.front == Q.rear) return ERROR;
	e = Q.base[Q.front];
	return OK;
}

int QueueLength(SqQueue Q)
{
	// 返回Q的元素个数
	return Q.rear%MAXQSIZE - Q.front%MAXQSIZE;
}

//编写main函数，主要是拿到到达时间arrivalTime和所需时间needTime
//但队列的每个数据元素只能存储一个数据，该如何解决？
//一个巧妙的办法就是，连续两次存储，然后在下一元素到达之前拿到所需要的数据即可
int main() {
	int n = 0;//客户数
	QElemType elem = 0;
	SqQueue sq;
	InitQueue(sq);
	//全都初始化为0
	int frontFinishTime = 0;
	int arrivalTime = 0;
	int needTime = 0;
	int waitTime = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&elem);
		EnQueue(sq,elem);//到达时间
		scanf("%d",&elem);
		EnQueue(sq,elem);//所需时间
		DeQueue(sq, arrivalTime);//到达时间arrivalTime
		DeQueue(sq, needTime);//所需时间needTime
		
			//如果上一完成时间大于等于下一达到时间，则下一个客户需要等待
			//更新等待时间和完成时间
			if (frontFinishTime>=arrivalTime)
			{
				//等待的时间从第二个人算起
				//等待的时间为前一个人完成的时间减去这个人到达的时间
				waitTime += (frontFinishTime - arrivalTime);
				//更新该人的完成时间，为下一个人做准备
				frontFinishTime += needTime;
			}
			//如果上一完成时间小于下一达到时间，需要重新计算完成时间！！！
			else
			{
				frontFinishTime = arrivalTime+ needTime;
			}
		
	}
	//循环结束后，对总的等待时间进行求平均值
	
	float result = (float)waitTime / n;
	printf("%.2f",result);
	return 0;
}