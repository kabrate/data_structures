#include"stdlib.h"  
#include"stdio.h"  
  
typedef char StackEntry;  
typedef struct node {    //链栈的结点结构  
    StackEntry item;  //栈的数据元素类型  
    struct node *next;  //指向后继结点的指针  
}NODE;   
typedef struct stack{  
    NODE *top;  
}STACK;   
//初始化栈  
void InitStack(STACK *S)  
{  
    S->top=NULL;  
}  
//入栈  
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
//是否为空栈  
int StackEmpty(STACK S)  
{  
    if (S.top==NULL) return true;  
    else return false;  
}  
  
//出栈   
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
    STACK S;                //定义一个栈结构S  
    char ch;  
    InitStack(&S);             //初始化栈  
    while ((ch=getchar())!='\n')     
        //从键盘输入字符，直到输入换行符为止  
        Push(&S ,ch);              
    //将输入的每个字符入栈  
    while (!StackEmpty(S)) {       
        //依次退栈并输出退出的字符  
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
