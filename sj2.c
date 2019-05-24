#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define FALSE 0
#define TRUE 1

typedef int SElementType;        //�궨��ջ
typedef int QElementType;        //�궨�����

typedef struct node              //����һ���ṹ����
{
	SElementType data;           //����ջ��������
	struct node* next;           //����ջ��ָ����
}LinkStackNode, *LinkStack;

typedef struct
{
	SElementType elem[MAXSIZE];  //����ջ�Ĵ�С
	int top;                     //ջ��
}SeqStack;

typedef struct Node               //����һ���ṹ����
{
	QElementType data;            //������е�������
	struct Node* next;            //������е�ָ����
}LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;           //ͷָ��
	LinkQueueNode *rear;            //βָ��
}LinkQueue;

void InitLink(LinkStack top)         //��ʼ��һ��ջ
{
	top->data = 0;
	top->next = NULL;
}

void PushLink(LinkStack top, SElementType x)      //��ջ
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));    //��̬����ռ�
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
}

void PopLink(LinkStack top, SElementType *x)      //��ջ
{
	LinkStackNode* temp;
	temp = top->next;
	top->next = temp->next;
	*x = temp->data;
	free(temp);           //��temp�ͷ�
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

int InitSeq(SeqStack* S)           //��ʼ��˳��ջ
{
	S->top = -1;                    //-1����Ϊ��
	return TRUE;
}

void PushSeq(SeqStack* S, SElementType x)     //��ջ
{
	if (S->top == MAXSIZE - 1)
	{
		printf("ջ������\n");
		return;
	}
	S->top++;                                 //�ƶ�ջ��λ��
	S->elem[S->top] = x;                      //����ջ�Ĵ�С

}

int PopSeq(SeqStack* S, SElementType* x)         //��ջ
{
	if (S->top == -1)                             //Ϊ��
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];                 //ջ�Ĵ�С
		S->top--;                            //�ƶ�ջ��λ��
		return(TRUE);
	}
}
int GetTop(SeqStack* S, SElementType* x)        //��ȡջ��
{
	if (S->top == -1)
	{
		return(FALSE);
	}
	else
	{
		*x = S->elem[S->top];
		printf("��ջ��ջ��Ԫ��Ϊ %d\n", *x);
		return(TRUE);
	}
}

int InitQueue(LinkQueue *Q)                     //��ʼ��һ�����У��Ƚ��ȳ�
{
	Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));  //Ϊͷָ������һ����̬�ռ�
	if (Q->front != NULL)
	{
		Q->rear = Q->front;                  
		Q->front->next = NULL;             //���ԭ�е�Ԫ��
		return (TRUE);
	}
	else
		return (FALSE);
}

int	EnterQueue(LinkQueue *Q, QElementType x)           //���
{
	LinkQueueNode *NewNode;          //�µ�����
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

int DeleteQueue(LinkQueue *Q, QElementType *x)   //����
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
void Init(QueueSq *S)           //˳�����
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
	printf("**  1.��ʽ�洢��ջ����ջ  **\n");
	printf("**  2.˳��洢��ջ����ջ  **\n");
	printf("**  3.��ʽ�洢��ӡ�����  **\n");
	printf("**  4.˳��洢��ӡ�����  **\n");
}
void test1()
{
	int i = 0;
	int d = 0;
	int j = 0;
	int b = 0;
	printf("������Ҫ��ջԪ�ظ�����");
	scanf("%d", &i);
	LinkStack S = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	InitLink(S);
	printf("������Ҫ��ջԪ�أ�");
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		PushLink(S, d);
		DisplayLink(S);
	}
	printf("������Ҫ��ջԪ�ظ�����");
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
	printf("������Ҫ��ջԪ�ظ�����");
	scanf("%d", &i);
	SeqStack S;
	InitSeq(&S);
	printf("\n������Ҫ��ջԪ�أ�");		
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		PushSeq(&S, d);
	}
	printf("\n������Ҫ��ջԪ�ظ�����");
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
	printf("������Ҫ���Ԫ�ظ�����");
	scanf("%d", &i);
	LinkQueue S;
	InitQueue(&S);
	printf("\n������Ҫ���Ԫ�أ�");
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		EnterQueue(&S, d);
	}
	printf("\n������Ҫ����Ԫ�ظ�����");
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
	printf("������Ҫ���Ԫ�ظ�����");
	scanf("%d", &i);
	QueueSq S;
	Init(&S);
	printf("\n������Ҫ���Ԫ�أ�");
	for (; i > 0; i--)
	{
		scanf("%d", &d);
		PushQueue(&S, d);
	}
	printf("\n������Ҫ����Ԫ�ظ�����");
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
		printf("��ѡ��\n");
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
			printf("ѡ�����\n");
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
