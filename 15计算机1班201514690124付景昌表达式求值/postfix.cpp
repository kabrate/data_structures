#include<iostream>
#include<stack>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std; 
int Precedence(char op)//��������ȼ��ж� 
{ 
    switch(op) 
    { 
	    case '+':  
	    case '-':  
	    return 1; //����Ӽ���������ȼ�Ϊ1  
	    case '*': 
	    case '/': 
	    return 2; //����˳���������ȼ�Ϊ2 
	    case '!': 
	    case '^': 
	    return 3;  
	    case '(': 
	    case '\0': 
	    default: 
	    return 0; //������ջ�е������ź�ջ���ַ������ȼ�Ϊ0  
    } 
} 
void stringJudge(char *s)//�Ƿ��ַ��ж� ��ʵ ����д �е�� Java�Ѿ�û������Ū�� 
{ 
    int i=0; 
    while(s[i]!=0) 
    { 
	    switch(s[i]) 
	    { 
		    case'+': 
		    case'-': 
		    case'*': 
		    case'/': 
		    case'0': 
		    case'1': 
		    case'2': 
		    case'3': 
		    case'4': 
		    case'5': 
		    case'6': 
		    case'7': 
		    case'8': 
		    case'9': 
		    case'.': 
		    case'(': 
		    case')': 
		    break; 
		    default: 
		    cout<<"�����ʽ�Ӻ��зǷ��ַ�������������"<<endl;
	    } 
	    i++; 
    } 
    return; 
} 
void tonibolan(char *s1,char *s2)//��׺ʽת��Ϊ�沨��ʽ 
{ 
    stack<char> s;//��һ���ַ�ջ 
    s.push('\0');//ջ���ַ� 
    int i=0,j=0;//i��¼s1��j��¼s2 
    char ch=s1[i]; //ȡ�׸� 
    if(ch==0)//�ж��ַ����Ƿ��ǿյ� 
    cout<<"����ļ���ʽ�ǿյĪ�����������"<<endl; 
    if(ch=='.')//�ж����ַ��Ƿ�ΪС���� 
    cout<<"С������ִ�������ʽ��"<<endl;  
    if(ch=='-')//������λ����  
    { 
	    s2[j++]='0'; //����������ַ�����ֱ�Ӽ��˸�0 ע�� û�� ��ch���¸��ַ� �Ǹ����Ż���Ҫ����� 
	    s2[j++]=' '; //�ո�Ϊ�˸��� ������ 
    } 
    stringJudge(s1); //�ж� �Ƿ��ַ� 
    while(ch!='\0') //ջ���ַ� over 
    { 
	    if(ch==' ') //�ո� �� ���� 
	    ch=s1[++i]; //����һ�� 
	    else if(ch=='(') //������ѹ��ջ�� 
	    { 
		    s.push('('); //ѹջ 
		    ch=s1[++i]; 
		    if(ch=='-')//������λ����  
		    { 
		     s2[j++]='0';
		     s2[j++]=' '; 
		    } 
	    } 
	    else if(ch==')') //������ ��������֮���ȫ������ ���� д�� ������ط��ĵ� ���ȼ��� 
	    { 
		    while(s.top()!='(') //ѭ���� �����Ŵ� ��ʵ �и�bug ���û�� �����ŵĻ� �Լ����� 
		    { 
		    s2[j++]=s.top(); //��ջ 
		    s.pop(); //pop()��ɾ���Գ�ջ 
		    } 
		    s.pop(); //��� ɾ�� ��� ���� 
		    ch=s1[++i]; 
	    } 
	    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/') //��������Ļ� 
	    { 
		    char w=s.top(); //����һ�� 
		    while(Precedence(w)>=Precedence(ch)) //�Ƚ����ȼ� 
		    { 
			    s2[j++]=w; //ջ��Ĵ�Ļ� ջ�Ǹ�д��  
			    s.pop(); //������ջ ����һ��ѭ�� 
			    w=s.top(); 
		    } 
		    s.push(ch); //ѹ����ַ� 
		    ch=s1[++i];  
		    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'|| ch=='!' || ch=='^') //�����ʾ ���ź������� ���� �׳��쳣  
		    cout<<"�����ʽ�Ӹ�ʽ����ȷ������������"<<endl;  
	    } 
	    else 
	    { 
		    while((ch>='0' && ch<='9') || ch=='.') //�����ֻ���С���� 
		    { 
			    s2[j++]=ch; //д������ַ�������׺ʽ�� 
			    ch=s1[++i]; 
		    } 
		    s2[j++]=' '; //�ո� ���� �� 
	    } 
    } 
    ch=s.top(); 
    s.pop(); 
    while(ch!='\0') //�����е�����ȡ�� д�� ��׺ʽ '\0'��ջ���ַ� 
	{ 
	    if(ch=='(') //˵���ж��( ���쳣 
	    cout<<"����ļ���ʽ������������������"<<endl; 
	    else 
	    { 
		    s2[j++]=ch; //д�� 
		    ch=s.top(); 
		    s.pop(); 
	    } 
    } 
    s2[j++]='\0'; //���� β�� �ַ���β 
} 
double nibolan(char *s) //������� �� ���� ���� ��׺ʽ�� 
{ 
    stack<double> sd; //doubleջ 
    int i=0; //ѭ������ ����λ�� 
    double num,num2; //��ʱ������������� 
    double n1,n2,n3; //ͬ�� 
    while(s[i]!='\0') //ѭ�� ��β 
    { 
	    num=0; 
	    num2=1; 
	    if(s[i]>='0' && s[i]<='9') // String ��Ϊ double 
	    { 
		    while(s[i]>='0' && s[i]<='9')  
		    { // ���� ��10+�µ����� 
			    num*=10; 
			    num+=s[i]-'0';  
			    i++; 
		    } 
		    if(s[i]=='.') //�м��С���� ֻ����һ�� 
		    { 
		    	i++; 
			    while(s[i]>='0' && s[i]<='9') 
				    { //���ǳ�10+�µ� 
					    num2/=10; 
					    num+=num2*(s[i]-'0'); 
					    i++; 
				    } 
			} 
		    if(s[i]=='.') //˵��С������� ���쳣 
		    cout<<"С������ִ�������ʽ��"<<endl;  
		    sd.push(num); //�� �γ�doubleѹ��ջ 
	     } 
	    else if(s[i]==' ') //���� �ո� �ָ��� 
	    i++; 
	    else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') //���¶���һ����˼  
	    { //������� ��ջ һ���������� Ȼ�� ���� ����� ѹջ 
		    n1=sd.top(); //��ջ 
		    sd.pop(); //ɾ�� 
		    n2=sd.top(); //�ٳ�һ�� 
		    sd.pop(); //��ɾ�� 
		    switch (s[i])
		    {
		    	case '+':n3=n2+n1; break;//���� 
		    	case '-':n3=n2-n1; break;
		    	case '*':n3=n2*n1; break;
		    	case '/':
				    if(n1==0) 
		            cout<<"0����������������ʽ��"<<endl;
		            n3=n2/n1; 
		    }  
		    sd.push(n3); //���ѹջ 
		    i++; //��һ�� 
	    }  
    } 
    if(sd.size()!=1) //���ʣ�µ�Ԫ�� ����1�� ��˵�� �� ������
    cout<<"�����ʽ�Ӹ�ʽ����ȷ������������"<<endl;  
    return sd.top(); //����ֵ Ϊ �� 
} 
int main() 
{ 
	char s1[100]; //������ַ��� 
	char s2[100]; //ת������ַ��� 
	while(1) 
	{ 
		cout<<"���������ʽ"; 
		gets(s1); //�ַ�����ʽ ���� 
		tonibolan(s1,s2); //ת��׺ʽ 
		puts(s2);
		cout<<nibolan(s2)<<endl; //���� 
		cout<<endl; 
	} 
	system("pause"); 
	return 0; 
} 

