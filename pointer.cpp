#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define NUM 20
int main()
{
	char *p;
	char *t;
	p = (char *)malloc(NUM*sizeof(char));
	scanf("%s",p);
    t = (char *)malloc(NUM*sizeof(char));
    strcpy(t,p);
    printf("%s",t);
	return 0;
	
} 
