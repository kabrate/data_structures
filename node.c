#include<stdio.h>
#include<malloc.h>
#include<stdio.h>
struct node
{
	int num;
	struct node *next;
};
void main()
{
	int i;
	int in,del;

	struct node *head;//����ͷ��� 
	struct node *newnode;// 
	struct node *lastnode;

	struct node *p;
	struct node *p2;

	head = NULL;
	lastnode = NULL;	

	printf("�������һ����ֵ��\n");

	scanf("%d",&in);
	newnode =  (struct node *)malloc(sizeof(struct node));
	newnode->num=in;
	newnode->next=NULL;

	head = newnode;
	lastnode = newnode;

	printf("������4����ֵ��\n");
	for(i=0;i<4;i++)
	{
		scanf("%d",&in);
		newnode =  (struct node *)malloc(sizeof(struct node));//����һ����� 
		newnode->num=in;
		newnode->next=NULL;

		lastnode->next=newnode;
		lastnode = newnode;
	}

	p = head;
	while(p!=NULL)
	{
		printf("%d->",p->num);
		p = p->next;
	}


	printf("\n������ɾ�������ֵ��\n");
	scanf("%d",&del);

	p=head->next;
	p2=head;

	while(p!=NULL)
	{
		if(p->num==del)
		{
			p2->next=p->next;
			free(p);
			break;
		}
		else
		{
			p2=p;
			p=p->next;
		}
	}

	p = head;
	while(p!=NULL)
	{
		printf("%d->",p->num);
		p = p->next;
	}
}								
