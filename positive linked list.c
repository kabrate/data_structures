#include <stdio.h>
#include <malloc.h>
typedef struct ln

{

    int data;

    struct ln *next;

} link;

link *create(link *head)//��������

{

    int data;//�������������

    link *p, *q;

    printf("������һϵ�е����ݣ�-1�������룺\n");

    scanf("%d", &data);//��һ�����������⴦��

    if(data!=-1)

    {

        p = (link *)malloc(sizeof(link));//����һ�����

        head = p;

        p->next=NULL;

        q=p;

        p->data = data;

        while(scanf("%d", &data) && data!=-1)

        {

            p = (link *)malloc(sizeof(link));//����һ�����

            head = p;//ǰ�����

            p->next=q;

            q=p;

            p->data = data;

        }

    }

    return head;//����ͷָ��

}

void print(link *head)//��������н���ֵ

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
