#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAXSIZE 100  

void trans(char str[],char exp[])//中缀转后缀
{
	struct Stack
	{
		char data[MAXSIZE];
		int top; 
	}op;//操作符栈
	char ch;
	int i=0,j=0,tempi=0;
	op.top=-1;
	while(ch!='\0')
	{
		ch=str[i];
		if((ch>='0'||ch<='9')||ch=='.')
		{
			tempi=i;
			while((ch>='0'||ch<='9')||ch=='.')
		   {
		    tempi++;
			exp[j]=ch;
			j++;
			ch=str[tempi];
		   }
		 exp[j]='#';
		 j++;
		 i=tempi;
		}
	    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
		{
			int level(char op);
			if(ch=='(')
			{
				op.top++;
				op.data[op.top]=ch;
			}
			else if (ch==')')
			{
				while(level(op.data[op.top])!=-1)
				{
					exp[i]=op.data[op.top];
					op.top--;
					j++;
					if(op.top==-1)break;
				}
				op.top--;
			}
			else if(op.top==-1)
			{
				op.top++;
				op.data[op.top]=ch;
			}
			else if(level(ch)>level(op.data[op.top]))
			{
				op.top++;
				op.data[op.top]=ch;
			}
			else
			{
				while(level(ch)<=level(op.data[op.top]))
				{
					exp[j]=op.data[op.top];
					op.top--;
					j++;
					if(op.top==-1)break;
				}
				op.top++;
				op.data[op.top]==ch;
			}
			i++;
		}	
		
	}
	while(op.top!=-1)
	{
		exp[j]==op.data[op.top];
		op.top--;
		j++;
	}
	exp[j]=='\0';
	
	 
} 
int level(char op)
{
	if(op=='+'||op||'-')
	    return 1;
	else if(op=='*'||op=='/'||op=='%')
	    return 2;
	if(op=='(')
	    return -1;
	else 
	    return -3;	
}
double calvalue(double od1,double od2,char tempop)
{
	switch(tempop)
	{
		case'+':
			return od1+od2;
		case'-':
			return od1-od2;
		case'*':
			return od1*od2;
	    case'/':
			return od1/od2;
		case'%':
			return fmod(od1,od2);			
	}
	return 0;
}
double calculate(char exp[])
{
	struct 
	{
		double data[MAXSIZE];
		int top;
	}od;
	double d;
	double od1,od2;
	char ch;
	char tempch[20];
	int j=0,t;
	int length=strlen(exp);
	od.top=-1;
	while(j<length)
	{
		ch=exp[j];
		if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='%')
		{
			d=0;
			t=0;
			while((ch>='0'&&ch<='9')||ch=='.')
			{
				tempch[t]=ch;t++;
				j++;ch=exp[j];
			}
			tempch[t]='\0';
			d=atof(tempch);
			od.top++;
			od.data[od.top]=d;
		}
		else 
		{
			od2=od.data[od.top];od.top--;
			od1=od.data[od.top];
			od.data[od.top]=calvalue(od1,od2,ch);
		}
		j++;
	}
	return od.data[od.top];
}
int main()
{
	char str[MAXSIZE],exps[MAXSIZE];
	printf("please input expression: \n");
	gets(str);
	printf("expression is %s\n",str);
	trans(str,exps);


	return 0;
}

