#include<iostream>
#include<stack>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std; 
int Precedence(char op)//运算符优先级判断 
{ 
    switch(op) 
    { 
	    case '+':  
	    case '-':  
	    return 1; //定义加减运算的优先级为1  
	    case '*': 
	    case '/': 
	    return 2; //定义乘除运算的优先级为2 
	    case '!': 
	    case '^': 
	    return 3;  
	    case '(': 
	    case '\0': 
	    default: 
	    return 0; //定义在栈中的左括号和栈底字符的优先级为0  
    } 
} 
void stringJudge(char *s)//非法字符判断 其实 这样写 有点蠢 Java已经没有这样弄了 
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
		    cout<<"输入的式子含有非法字符请重新输入"<<endl;
	    } 
	    i++; 
    } 
    return; 
} 
void tonibolan(char *s1,char *s2)//中缀式转换为逆波兰式 
{ 
    stack<char> s;//开一个字符栈 
    s.push('\0');//栈底字符 
    int i=0,j=0;//i记录s1j记录s2 
    char ch=s1[i]; //取首个 
    if(ch==0)//判断字符串是否是空的 
    cout<<"输入的计算式是空的请重新输入"<<endl; 
    if(ch=='.')//判断首字符是否为小数点 
    cout<<"小数点出现错误请检查式子"<<endl;  
    if(ch=='-')//负号首位补零  
    { 
	    s2[j++]='0'; //就是在输出字符串中直接加了个0 注意 没有 让ch读下个字符 那个符号还是要处理的 
	    s2[j++]=' '; //空格为了隔开 数与数 
    } 
    stringJudge(s1); //判断 非法字符 
    while(ch!='\0') //栈底字符 over 
    { 
	    if(ch==' ') //空格 就 忽略 
	    ch=s1[++i]; //读下一个 
	    else if(ch=='(') //左括号压入栈中 
	    { 
		    s.push('('); //压栈 
		    ch=s1[++i]; 
		    if(ch=='-')//负号首位补零  
		    { 
		     s2[j++]='0';
		     s2[j++]=' '; 
		    } 
	    } 
	    else if(ch==')') //右括号 把左括号之间的全部出来 依次 写入 这个地方改的 优先级 
	    { 
		    while(s.top()!='(') //循环至 左括号处 其实 有个bug 如果没有 左括号的话 自己考了 
		    { 
		    s2[j++]=s.top(); //出栈 
		    s.pop(); //pop()是删除性出栈 
		    } 
		    s.pop(); //最后 删除 这个 括号 
		    ch=s1[++i]; 
	    } 
	    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/') //是运算符的话 
	    { 
		    char w=s.top(); //出第一个 
		    while(Precedence(w)>=Precedence(ch)) //比较优先级 
		    { 
			    s2[j++]=w; //栈里的大的话 栈那个写入  
			    s.pop(); //继续出栈 这是一个循环 
			    w=s.top(); 
		    } 
		    s.push(ch); //压入此字符 
		    ch=s1[++i];  
		    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'|| ch=='!' || ch=='^') //这个表示 符号后面又是 符号 抛出异常  
		    cout<<"输入的式子格式不正确请重新输入"<<endl;  
	    } 
	    else 
	    { 
		    while((ch>='0' && ch<='9') || ch=='.') //是数字或者小数点 
		    { 
			    s2[j++]=ch; //写入输出字符串后缀式 
			    ch=s1[++i]; 
		    } 
		    s2[j++]=' '; //空格 隔开 数 
	    } 
    } 
    ch=s.top(); 
    s.pop(); 
    while(ch!='\0') //将所有的依次取出 写入 后缀式 '\0'是栈底字符 
	{ 
	    if(ch=='(') //说明有多的( 抛异常 
	    cout<<"输入的计算式括号有误请重新输入"<<endl; 
	    else 
	    { 
		    s2[j++]=ch; //写入 
		    ch=s.top(); 
		    s.pop(); 
	    } 
    } 
    s2[j++]='\0'; //加上 尾巴 字符串尾 
} 
double nibolan(char *s) //这个函数 是 用来 运算 后缀式的 
{ 
    stack<double> sd; //double栈 
    int i=0; //循环变量 控制位置 
    double num,num2; //临时的运算的两个数 
    double n1,n2,n3; //同上 
    while(s[i]!='\0') //循环 至尾 
    { 
	    num=0; 
	    num2=1; 
	    if(s[i]>='0' && s[i]<='9') // String 换为 double 
	    { 
		    while(s[i]>='0' && s[i]<='9')  
		    { // 就是 乘10+新的数字 
			    num*=10; 
			    num+=s[i]-'0';  
			    i++; 
		    } 
		    if(s[i]=='.') //中间的小数点 只能有一个 
		    { 
		    	i++; 
			    while(s[i]>='0' && s[i]<='9') 
				    { //就是除10+新的 
					    num2/=10; 
					    num+=num2*(s[i]-'0'); 
					    i++; 
				    } 
			} 
		    if(s[i]=='.') //说明小数点多了 抛异常 
		    cout<<"小数点出现错误请检查式子"<<endl;  
		    sd.push(num); //将 形成double压入栈 
	     } 
	    else if(s[i]==' ') //忽略 空格 分隔符 
	    i++; 
	    else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') //以下都是一个意思  
	    { //遇运算符 出栈 一般是两个数 然后 运算 结果再 压栈 
		    n1=sd.top(); //出栈 
		    sd.pop(); //删除 
		    n2=sd.top(); //再出一个 
		    sd.pop(); //再删除 
		    switch (s[i])
		    {
		    	case '+':n3=n2+n1; break;//运算 
		    	case '-':n3=n2-n1; break;
		    	case '*':n3=n2*n1; break;
		    	case '/':
				    if(n1==0) 
		            cout<<"0不能作除数请检查式子"<<endl;
		            n3=n2/n1; 
		    }  
		    sd.push(n3); //结果压栈 
		    i++; //下一个 
	    }  
    } 
    if(sd.size()!=1) //如果剩下的元素 大于1个 就说明 数 多了三
    cout<<"输入的式子格式不正确请重新输入"<<endl;  
    return sd.top(); //最后的值 为 答案 
} 
int main() 
{ 
	char s1[100]; //输入的字符串 
	char s2[100]; //转换后的字符串 
	while(1) 
	{ 
		cout<<"请输入计算式"; 
		gets(s1); //字符串形式 输入 
		tonibolan(s1,s2); //转后缀式 
		puts(s2);
		cout<<nibolan(s2)<<endl; //计算 
		cout<<endl; 
	} 
	system("pause"); 
	return 0; 
} 

