#include <stdio.h>
#include <string.h>
char stack[256];
int top=0;

void push(char c)
{
    top++;stack[top]=c;
}

int pop()
{
    top--;return(stack[top+1]);
}

int main()
{
    char s[256];
    gets(s);
    int lenofs=strlen(s);
    int i;
    char c;
    for(i=0;i<=lenofs-1;i++)
    {
        if(s[i]=='(')
        {
            push('(');
        }
        if(s[i]==')')
        {
            push(')');
            c=stack[top-1];
            if(c=='(')
            {
                pop();pop();
            }
        }
        if(s[i]=='[')
        {
            push('[');
        }
        if(s[i]==']')
        {
            push(']');
            c=stack[top-1];
            if(c=='[')
            {
                pop();pop();
            }
        }
        if(top<0) break;
    }
    if(top==0) printf("OK");
    else printf("Wrong");
    return 0;
}
