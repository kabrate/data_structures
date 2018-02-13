#include"stdlib.h"  
#include"stdio.h"  
  
typedef char StackEntry;  
typedef struct node {    //��ջ�Ľ��ṹ  
    StackEntry item;  //ջ������Ԫ������  
    struct node *next;  //ָ���̽���ָ��  
}NODE;   
typedef struct stack{  
    NODE *top;  
}STACK;   
//��ʼ��ջ  
void InitStack(STACK *S)  
{  
    S->top=NULL;  
}  
//��ջ  
void Push(STACK *S,StackEntry item)  
{   
    NODE* p;  
  
    p=(NODE*)malloc(sizeof(NODE));  
    if (!p)   
        exit(0);  
    else {   
        p->item=item;  
        p->next=S->top;  
        S->top=p;  
    }  
}  
//�Ƿ�Ϊ��ջ  
int StackEmpty(STACK S)  
{  
    if (S.top==NULL) return true;  
    else return false;  
}  
  
//��ջ   
void Pop(STACK*S, StackEntry *item)  
{  
    NODE *p;  
  
    if (StackEmpty(*S))   
        exit(0);  
    else {   
        *item=S->top->item;  
        p=S->top;  
        S->top=p->next; free(p);  
    }  
}  
  
void ReverseRead( )  
{    
    STACK S;                //����һ��ջ�ṹS  
    char ch;  
    InitStack(&S);             //��ʼ��ջ  
    while ((ch=getchar())!='\n')     
        //�Ӽ��������ַ���ֱ�����뻻�з�Ϊֹ  
        Push(&S ,ch);              
    //�������ÿ���ַ���ջ  
    while (!StackEmpty(S)) {       
        //������ջ������˳����ַ�  
        Pop(&S,&ch);  
        putchar(ch);  
    }  
    putchar('\n');  
}  
int main()
{  
    ReverseRead();
	return 0;  
}  
