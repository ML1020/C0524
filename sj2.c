#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define FALSE 0
#define TRUE 1

typedef int SElementType;        //宏定义栈
typedef int QElementType;        //宏定义队列

typedef struct node              //定义一个结构体结点
{
	SElementType data;           //定义栈的数据域
	struct node* next;           //定义栈的指针域
}LinkStackNode, *LinkStack;

typedef struct
{
	SElementType elem[MAXSIZE];  //定义栈的大小
	int top;                     //栈顶
}SeqStack;

typedef struct Node               //定义一个结构体结点
{
	QElementType data;            //定义队列的数据域
	struct Node* next;            //定义队列的指针域
}LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;           //头指针
	LinkQueueNode *rear;            //尾指针
}LinkQueue;

void InitLink(LinkStack top)         //初始化一个栈
{
	top->data = 0;
	top->next = NULL;
}

void PushLink(LinkStack top, SElementType x)      //入栈
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));    //动态申请空间
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
}

void PopLink(LinkStack top, SElementType *x)      //出栈
{
	LinkStackNode* temp;
	temp = top->next;
	top->next = temp->next;
	*x = temp->data;
	free(temp);           //将temp释放
}
void DisplayLink(LinkStack top)
{
	LinkStackNode *temp;
	temp = top;
	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("%d", temp->data);
		printf("->");
	}
	printf("NULL\n");
}

int InitSeq(SeqStack* S)           //初始化顺序栈
{
	S->top = -1;                    //-1代表为空
	return TRUE;
}

void PushSeq(SeqStack* S, SElementType x)     //入栈
{
	if (S->top == MAXSIZE - 1)
	{
		printf("栈已满！\n");
		return;
	}
	S->top++;                                 //移动栈顶位置
	S->elem[S->top] = x;                      //定义栈的大小

}

int PopSeq(SeqStack* S, SElementType* x)         //出栈
{
	if (S->top == -1)                             //为空
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];                 //栈的大小
		S->top--;                            //移动栈顶位置
		return(TRUE);
	}
}
int GetTop(SeqStack* S, SElementType* x)        //获取栈顶
{
	if (S->top == -1)
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];
		printf("出栈后栈顶元素为 %d\n", *x);
		return(TRUE);
	}
}

int InitQueue(LinkQueue *Q)                     //初始化一个队列，先进先出
{
	Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));  //为头指针申请一个动态空间
	if (Q->front != NULL)
	{
		Q->rear = Q->front;                  
		Q->front->next = NULL;             //清空原有的元素
		return (TRUE);
	}
	else
		return (FALSE);
}

int	EnterQueue(LinkQueue *Q, QElementType x)           //入队
{
	LinkQueueNode *NewNode;          //新的数据
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		return (TRUE);
	}
	else
		return (FALSE);
}

int DeleteQueue(LinkQueue *Q, QElementType *x)   //出队
{
	LinkQueueNode *p;
	if (Q->front == Q->rear)
	{
		return (FALSE);
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	*x = p->data;
	free(p);
	return (TRUE);
}

typedef struct Queue
{
	QElementType data[MAXSIZE];
	int size;
}QueueSq;
void Init(QueueSq *S)           //顺序队列
{
	S->size = -1;
}
void PushQueue(QueueSq* S, QElementType d)
{
	if ((S->size + 1) >= MAXSIZE)
		return;
	S->data[S->size + 1] = d;
	S->size++;
}
void PopQueue(QueueSq*S, QElementType *d)
{
	if (S->size == -1)
		return;
	*d = S->data[0];
	for (int i = 0; i < S->size; ++i)
	{
		S->data[i] = S->data[i + 1];
	}
	S->size--;
}

void menu()
{
	printf("**  1.链式存储入栈、出栈  **\n");
	printf("**  2.顺序存储入栈、出栈  **\n");
	printf("**  3.链式存储入队、出队  **\n");
	printf("**  4.顺序存储入队、出队  **\n");
}
void test1()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b = 0;
	printf("请输入要入栈元素个数：");
	scanf("%d", &i);
	LinkStack S = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	InitLink(S);
	printf("请输入要入栈元素：");
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		PushLink(S, d);
		DisplayLink(S);
	}
	printf("请输入要出栈元素个数：");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		PopLink(S, &b);
		DisplayLink(S);
	}
}
void test2()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b = 0;
	printf("请输入要入栈元素个数：");
	scanf("%d", &i);
	SeqStack S;
	InitSeq(&S);
	printf("\n请输入要入栈元素：");		
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		PushSeq(&S, d);
	}
	printf("\n请输入要出栈元素个数：");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		PopSeq(&S, &b);
		GetTop(&S, &b);
	}
}
void test3()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b;
	printf("请输入要入队元素个数：");
	scanf("%d", &i);
	LinkQueue S;
	InitQueue(&S);
	printf("\n请输入要入队元素：");
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		EnterQueue(&S, d);
	}
	printf("\n请输入要出队元素个数：");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		DeleteQueue(&S, &b);
		printf("%d\n", b);
	}
}
void test4()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b;
	printf("请输入要入队元素个数：");
	scanf("%d", &i);
	QueueSq S;
	Init(&S);
	printf("\n请输入要入队元素：");
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		PushQueue(&S, d);
	}
	printf("\n请输入要出队元素个数：");
	scanf("%d", &j);
	for (; j > 0; j--)
	{
		PopQueue(&S, &b);
		printf("%d\n", b);
	}
}

void test()
{
	int input = 1;
	do{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (1);
}
int main()
{
	test();
	system("pause");
	return 0;
}
