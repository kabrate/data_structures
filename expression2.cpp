#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<stack>  
#define MAXSIZE 100  
using namespace std;
//���ȼ���  
char compare(char ch, char top)  
{  
    switch(ch){  
        case '+':  
        case '-':  
            if (top == '+' || top == '-' || top == '*' || top == '/')  
                return '<';  //ɨ���С��ջ��  
            else  
                return '>';  //ɨ��Ĵ���ջ��  
            break;  
        case '*':  
        case '/':  
            if (top == '*' || top == '/')  
                return '<';  
            else  
                return '>';  
            break;  
        case '(':  
            if(top == ')'){  
                printf("��������!\n");  exit(-1);  
            }  
            return '>';  
            break;  
        case ')':  
            if (top == '(')  
                return '=';  
            else if(top == '#'){  
                printf("��������!\n");  
                exit(-1);  
            }  
            else{  
                return '<';  
            }  
            break;  
        case '#':  
            return '<';  
    }  
}  
  
//������ʽ��������  
double CalculateExp()  
{  
    double result, tempNum1, tempNum2;  
    double data = 0, expn;  
    char ch, topSign, point = 'n', num = 'n';  
    stack<char> sign;  
    stack<double> number;   
    sign.push('#');
    printf("��������ʽ��");  
    ch = getchar();  
    topSign=sign.top();  
    if (ch=='-')//�жϸ��� 
	    {
	    	number.push(0);
	    	sign.push('-');
	    }
    while(ch != '#' || topSign != '#')
	{  
	    
         if ('0' <= ch && ch <= '9' || ch == '.')
		{  
            if (ch == '.' && point == 'y')
			{  
                printf("���ʽ��������!\n");  
                exit(-1);  
            }  
            else if (ch == '.' && point == 'n')
			{  
                point = 'y';  
                expn = 0.1;  
            }  
            else
			{  
                if (point == 'y')
				{  
                    data = data + expn * (ch - '0');  
                    expn *= 0.1;  
                }  
                else
				{  
                    data = data * 10 + (ch - '0');  
                }  
                num = 'y';  
            }  
            ch = getchar();  
        }  
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '#')
		{  
            if (num == 'y')
			{  
                number.push(data);
                num = 'n';  point = 'n';  
                data = 0;  
            }  
            topSign=sign.top();
            switch(compare(ch, topSign))
			{  
                case '<':        //ɨ����������ȼ�С��ջ��Ԫ��  
                    topSign=sign.top();
                    sign.pop();
                    //PopStack(number, &tempNum1);  
                    //PopStack(number, &tempNum2);  
                    tempNum1=number.top();
                    number.pop();
                    tempNum2=number.top();
                    number.pop();
                    switch(topSign)
					{  
                        case '+':   result = tempNum2 + tempNum1;   break;  
                        case '-':   result = tempNum2 - tempNum1;   break;  
                        case '*':   result = tempNum2 * tempNum1;   break;  
                        case '/':   result = tempNum1 / tempNum1;   break;  
                    }  
                    number.push(result);
                    break;  
                case '>':        //ɨ����������ȼ�����ջ��Ԫ��  
                    sign.push(ch);
                    ch = getchar();  
                    break;  
                case '=':       //ɨ�������Ϊ������,ƥ�䵽��������  
					topSign=sign.top();
                    sign.pop(); 
                    ch = getchar();  
                    break;  
            }  
        }  
        else if (ch == '\n')
		{  
            ch = '#';  
        }  
        else{  
            printf("����ı��ʽ����!\n");  
            exit(-1);  
        }  
        topSign=sign.top();
    }  
	result=number.top();//�������ջ��ȡ����  
    number.pop();  
    if (!number.empty()){   //���ȡ����ջ��Ϊ�����ʾ����ı��ʽ����ȷ  
        printf("���ʽ����!\n");  
        exit(-1);  
    }  
      
    return result;  
}  
  
int main()  
{  
    printf("%lf\n", CalculateExp());  
      
    return 0;  
}  
