#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define NUM 20
typedef struct node

{

    char data[20]; 
    struct node *next;

} node;

node *create(node *head)//创建链表

{
    char input[20];//接收输入的数据
    node *newnode, *prenode;

    printf("请输入一系列的数据，*结束输入：\n");
    scanf("%s",input);
    if(strcmp(input,"#")!=0)
    {

        newnode = (node *)malloc(sizeof(node));//开辟一个结点
        strcpy(newnode->data,input);       
        newnode->next=NULL;
        
        head = newnode;
        prenode=newnode;
        

        
        scanf("%s",input);
        while(strcmp(input,"#")!=0)

        {
            newnode = (node *)malloc(sizeof(node));//开辟一个结点
            strcpy(newnode->data,input);
            newnode->next=NULL;
            
            prenode->next=newnode;
            prenode=newnode;
            scanf("%s",input);
        }

    }

    return head;//返回头指针

}

void print(node *head)//输出链表中结点的值

{

    node *p = head;

    while(p)

    {

        puts(p->data);

        p=p->next;

    }

}

int main()

{

    node *head;

    head = create(head);

    print(head);

    return 0;

}
