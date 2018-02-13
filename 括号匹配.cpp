#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 100
#define STACK_INCR_SIZE 10
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int SElemType;
typedef int Status;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S);
Status GetTop(SqStack S,SElemType &e);
Status Push(SqStack S,SElemType e);
Status Pop(SqStack &S,SElemType &e);
Status In(char c,char op[]);
char Precede(char a,char b);
int Operate(int a,char theta,int b);
int GetNext(int *n);
int EvaluateExpression();

Status InitStack(SqStack *S)
{
	//构造一个空栈
	S.base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base)	//存储空间分配失败
	{
		exit(OVERFLOW);
	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
	//若栈不空,则用e返回S的栈顶元素,并返回OK;否则返回ERROR
	if(S.top==S.base)
	{
		return ERROR;
	}
	e=*(S.top-1);
	return OK;
}

Status Push(SqStack S,SElemType e)
{
	//插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACK_INCR_SIZE)*sizeof(SElemType));
	}
	if(!S.base)
	{
		exit(OVERFLOW);	//存储空间分配失败
	}
	S.top=S.base+S.stacksize;
	S.stacksize+=STACK_INCR_SIZE;
	*S.top++=e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
	//若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK;否则返回ERROR
	if(S.top==S.base)
	{
		return ERROR;
	}
	e=*--S.top;
	return OK;
}

Status In(char c,char op[])
{
	//判断输入的某个字符是否是运算符,c表示输入的字符,op数组存放系统能识别的运算符
	char *p;
	p=op;
	while(*p!='\0')
	{
		if(c==*p)
			return TURE;
		p++;
	}
	return FALSE;
}

char Precede(char a,char b)
{
	int i,j;
	char pre[][7]={
		{'>','>','<','<','<','>','>'},
		{'>','>','<','<','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'<','<','<','<','<','=','0'},
		{'>','>','>','>','0','>','>'}, 
		{'<','<','<','<','<','0','='}};
	switch(a)
	{
		case '+': i=0;break;
		case '-': i=1;break;
		case '*': i=2;break;
		case '/': i=3;break;
		case '(': i=4;break;
		case ')': i=5;break;
		case '#': i=6;break;
	}
	switch(b)
	{
		case '+': j=0;break;
		case '-': j=1;break;
		case '*': j=2;break;
		case '/': j=3;break;
		case '(': j=4;break;
		case ')': j=5;break;
		case '#': j=6;break;
	}
	return pre[i][j];
}

int Operate(int a,char theta,int b)
{
	int i,j,result;
	i=a;
	j=b;
	switch(theta)
	{
		case '+': result=i+j;break;
		case '-': result=i-j;break;
		case '*': result=i*j;break;
		case '/': result=i/j;break;
	}
	return result;
}

int GetNext(int *n)
{
	char c;
	*n=0;
	while((c=getchar())==' ');
	if(!isdigit(c))
	{
		*n=c;
		return 1;
	}
	do{
		*n=*n*10+(c-'0');
		c=getchar();
	}while(isdigit(c));
	ungetc(c,stdin);
}

int EvaluateExpression()
{
	//设OPTR和OPND分别为运算符栈和运算数栈
	//OP为运算符集合
	int n;
	int flag;
	int c;
	char x,theta;
	int a,b;
	char op[]="+-*/()#";
	SqStack OPTR;
	SqStack OPND;
	InitStack(&OPTR);
	Push(&OPTR,'#');
	InitStack(&OPND);
	flag=GetNext(&c);
	GetTop(OPTR,&x);
	while(c!='#'||x!='#')
	{
		if(flag==0)
		{
			Push(&OPND,c);
			flag=GetNext(&c);
		}
		else
		{
			GetTop(OPTR,&x);
			switch(Precede(x,c))
			{
				case '<':	Push(&OPTR,c);
							flag=GetNext(&c);
							break;
				case '=':	Pop(&OPTR,&x);
							flag=GetNext(&c);
							break;
				case '>':	Pop(&OPTR,&theta);
							Pop(&OPND,&b);
							Pop(&OPND,&a);
							Push(&OPND,Operate(a,theta,b));
							break;
			}
		}
		GetTop(OPTR,&x);
	}
	GetTop(OPND,&c);
	return c;
}

int main()
{
	int c;
	printf("Please intput one expression:");
	c=EvaluateExpression();
	printf("Result=%d\n",c);
	getchar();
	return 0;
}
