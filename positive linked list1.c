#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define NUM 20
typedef struct node

{

    char data[20]; 
    struct node *next;

} node;

node *create(node *head)//��������

{
    char input[20];//�������������
    node *newnode, *prenode;

    printf("������һϵ�е����ݣ�*�������룺\n");
    scanf("%s",input);
    if(strcmp(input,"#")!=0)
    {

        newnode = (node *)malloc(sizeof(node));//����һ�����
        strcpy(newnode->data,input);       
        newnode->next=NULL;
        
        head = newnode;
        prenode=newnode;
        

        
        scanf("%s",input);
        while(strcmp(input,"#")!=0)

        {
            newnode = (node *)malloc(sizeof(node));//����һ�����
            strcpy(newnode->data,input);
            newnode->next=NULL;
            
            prenode->next=newnode;
            prenode=newnode;
            scanf("%s",input);
        }

    }

    return head;//����ͷָ��

}

void print(node *head)//��������н���ֵ

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
