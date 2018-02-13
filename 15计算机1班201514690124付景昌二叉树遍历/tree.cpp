#include <string.h>
#include <stdio.h>    
#include <stdlib.h>   
#include <stack>
#include <io.h>  
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
using namespace std;
typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */


/* ************************************************ */

typedef char TElemType;
TElemType Nil=' '; /* �ַ����Կո��Ϊ�� */

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

typedef struct BiTNode  /* ���ṹ */
{
   TElemType data;		/* ������� */
   struct BiTNode *lchild,*rchild; /* ���Һ���ָ�� */
}BiTNode,*BiTree;


/* ����ն�����T */
Status InitBiTree(BiTNode **T)
{ 
	*T=NULL;
	return OK;
}

/* ��ʼ����: ������T���ڡ��������: ���ٶ�����T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* ������ */
			DestroyBiTree(&(*T)->lchild); /* ������������ */
		if((*T)->rchild) /* ���Һ��� */
			DestroyBiTree(&(*T)->rchild); /* �����Һ������� */
		free(*T); /* �ͷŸ���� */
		*T=NULL; /* ��ָ�븳0 */
	}
}

/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������T�� */
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;	
	 scanf("%c",&ch); 
	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; /* ���ɸ���� */
		CreateBiTree(&(*T)->lchild); /* ���������� */
		CreateBiTree(&(*T)->rchild); /* ���������� */
	}
 }

/* ��ʼ����: ������T���� */
/* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* ��ʼ����: ������T���ڡ��������: ����T����� */
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}

/* ��ʼ����: ������T���ڡ��������: ����T�ĸ� */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* ��ʼ����: ������T���ڣ�pָ��T��ĳ����� */
/* �������: ����p��ָ����ֵ */
TElemType Value(BiTree p)
{
	return p->data;
}

/* ��p��ָ��㸳ֵΪvalue */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}
//�ڵ���Ŀ 
int NodeNum(BiTree T)
{
	int i=0;
	if(T==NULL)
		return 0;
    else
    {
    	i = 1+ NodeNum(T->lchild)+NodeNum(T->rchild); 
    }
	return i;
}
/* ��ʼ����: ������T���� */
/* �������: ǰ��ݹ����T */
int PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return 0;
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild); /* ��������������� */
	PreOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
int InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return 0;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
int PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return 0;
	PostOrderTraverse(T->lchild); /* �Ⱥ������������  */
	PostOrderTraverse(T->rchild); /* �ٺ������������  */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
}
//������������ĳ�� 
int Level(BiTree T, int level) 
{  
    if (!T || level < 0)  
        return 0;
	else if (level ==0)
	{
		printf("%c",T->data); 
		return 1;
	}  
	else 
        return Level(T->lchild, level - 1)+Level(T->rchild, level - 1); 
	
}
void InOrderTraverse_2(BiTree T)//�ǵݹ��������  
{       
    stack<BiTree> Stack;  
    if(!T)  
    {  
        printf("������\n");  
        return;  
    }  
      
    while(T || !Stack.empty())  
    {  
//����ջ����TΪ��Ҳ��������ջʱ��ִ������ĳ�ջ����
        while(T)  
        {  
            Stack.push(T);  
            T=T->lchild;  
        }
//��ջ�����ж���ջ����  
        T=Stack.top();  
        Stack.pop();  
        printf("%c",T->data);  
//����������
        T=T->rchild;  
    }                                                                                                                                     
}  
  
  
  
void PreOrderTraverse_2(BiTree T)//�ǵݹ��������  
{  
      
    stack<BiTree> Stack;  
    if(!T)  
    {  
        printf("������\n");  
        return;  
    }  
    while(T || !Stack.empty())  
    {  
//����ջ����TΪ��Ҳ��������ջʱ��ִ������ĳ�ջ����
        while(T)  
        {  
            Stack.push(T);  
            printf("%c",T->data);  
            T=T->lchild;  
        }  
//��ջ�����ж���ջ����
        T=Stack.top();  
        Stack.pop();  
//����������        
        T=T->rchild;          
    }                                                                                                                                     
}  
  
  
void PostOrderTraverse_2(BiTree T)//�ǵݹ�������,��һ����Ǳ���������Ƿ���ʹ�  
{    
    stack<BiTree> Stack;//�����ڵ�ջ 
	stack<int> Stack_2;  //������־ջ 
	int flag;
	BiTree p =T; 
    while(p || !Stack.empty())//pָ��Ϊ����ջΪ��ʱ����Ԫ�ر������
	{
		if(p)//�����ڵ㲻Ϊ��ʱ һֱ������� 
		{
			Stack.push(p);
			Stack_2.push(0);
			p=p->lchild;
		}
		else  //�ҵ�������Ľڵ� 
		{
			p=Stack.top();
			flag=Stack_2.top();
			if(!flag)  //����Щ�������ĵ㸳��־1 
			{
				Stack_2.pop();
				Stack_2.push(1);
				p=p->rchild;
			}
			else   //�ص����ڵ� 
			{
				p=Stack.top();
				Stack.pop();
				Stack_2.pop();
				printf("%c",p->data);
				p=NULL;
			}
		}
	}                                                                                                                                    
}  

//��ӡ�����Ľ�� 
void LevelTraverse(BiTree T)
{
	int i=0;
	for (i=0;i<BiTreeDepth(T);i++)
	{
		Level(T,i);
	}
}
int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	//����ABDH#K###E##CFI###G#J##

	CreateBiTree(&T);

	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("�������ĸ�Ϊ: %c\n",e1);
	printf("\n�ݹ�ǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�ݹ��������������:");
	InOrderTraverse(T);
	printf("\n�ݹ�������������:");
	PostOrderTraverse(T);
	printf("\n�ǵݹ�ǰ�����������:");
	PreOrderTraverse_2(T);
	printf("\n�ǵݹ��������������:");
	InOrderTraverse_2(T);
	printf("\n�ǵݹ�������������:");
	PostOrderTraverse_2(T);
	printf("\n��α���������:");	
	LevelTraverse(T);
	printf("\n�������Ľڵ���ĿΪ:");
	printf("%d",NodeNum(T));
	ClearBiTree(&T);
	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
	printf("���գ��޸�\n");
	
	return 0;
}

