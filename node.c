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

	struct node *head;//定义头结点 
	struct node *newnode;// 
	struct node *lastnode;

	struct node *p;
	struct node *p2;

	head = NULL;
	lastnode = NULL;	

	printf("请输入第一个数值：\n");

	scanf("%d",&in);
	newnode =  (struct node *)malloc(sizeof(struct node));
	newnode->num=in;
	newnode->next=NULL;

	head = newnode;
	lastnode = newnode;

	printf("请输入4个数值：\n");
	for(i=0;i<4;i++)
	{
		scanf("%d",&in);
		newnode =  (struct node *)malloc(sizeof(struct node));//创建一个结点 
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


	printf("\n请输入删除结点数值：\n");
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
