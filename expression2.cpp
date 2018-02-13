#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include<stack>  
#define MAXSIZE 100  
using namespace std;
//优先级表  
char compare(char ch, char top)  
{  
    switch(ch){  
        case '+':  
        case '-':  
            if (top == '+' || top == '-' || top == '*' || top == '/')  
                return '<';  //扫描的小于栈顶  
            else  
                return '>';  //扫描的大于栈顶  
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
                printf("输入有误!\n");  exit(-1);  
            }  
            return '>';  
            break;  
        case ')':  
            if (top == '(')  
                return '=';  
            else if(top == '#'){  
                printf("输入有误!\n");  
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
  
//输入表达式并计算结果  
double CalculateExp()  
{  
    double result, tempNum1, tempNum2;  
    double data = 0, expn;  
    char ch, topSign, point = 'n', num = 'n';  
    stack<char> sign;  
    stack<double> number;   
    sign.push('#');
    printf("请输入表达式：");  
    ch = getchar();  
    topSign=sign.top();  
    if (ch=='-')//判断复数 
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
                printf("表达式输入有误!\n");  
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
                case '<':        //扫描运算符优先级小于栈顶元素  
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
                case '>':        //扫描运算符优先级大于栈顶元素  
                    sign.push(ch);
                    ch = getchar();  
                    break;  
                case '=':       //扫描运算符为右括号,匹配到了左括号  
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
            printf("输入的表达式有误!\n");  
            exit(-1);  
        }  
        topSign=sign.top();
    }  
	result=number.top();//将结果从栈中取出来  
    number.pop();  
    if (!number.empty()){   //如果取出后栈不为空则表示输入的表达式不正确  
        printf("表达式有误!\n");  
        exit(-1);  
    }  
      
    return result;  
}  
  
int main()  
{  
    printf("%lf\n", CalculateExp());  
      
    return 0;  
}  
