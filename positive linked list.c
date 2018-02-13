#include <stdio.h>
#include <malloc.h>
typedef struct ln

{

    int data;

    struct ln *next;

} link;

link *create(link *head)//创建链表

{

    int data;//接收输入的数据

    link *p, *q;

    printf("请输入一系列的数据，-1结束输入：\n");

    scanf("%d", &data);//第一个结点进行特殊处理

    if(data!=-1)

    {

        p = (link *)malloc(sizeof(link));//开辟一个结点

        head = p;

        p->next=NULL;

        q=p;

        p->data = data;

        while(scanf("%d", &data) && data!=-1)

        {

            p = (link *)malloc(sizeof(link));//开辟一个结点

            head = p;//前插操作

            p->next=q;

            q=p;

            p->data = data;

        }

    }

    return head;//返回头指针

}

void print(link *head)//输出链表中结点的值

{

    link *p = head;

    while(p)

    {

        printf("%-5d", p->data);

        p=p->next;

    }

}

int main()

{

    link *head;

    head = create(head);

    print(head);

    return 0;

}
