#include <stdio.h>
#define Mat  5
int main()
{
   printf("---^@^*** C Program aims at:矩阵连乘 ***^@^---\n");
   printf("______By Wangxin————qq：278810732_______\n");
   printf("^^^ Finish-time: 3/11/2011,14:00:00 ^^^\n");
   printf("The total numbers of the matrix is %d\n",Mat-1);
   void matrixChain(int p[Mat], int m[Mat][Mat], int s[Mat][Mat]);
   void display(int S[Mat][Mat]);
   int i,j;
   int p[Mat],m[Mat][Mat],s[Mat][Mat];
   for(i=1;i<=Mat-1;i++)
      for(j=1;j<=Mat-1;j++)
      {
        m[i][j]=0;
        s[i][j]=0;
      }
      for(i=0;i<Mat;i++)
      {
        printf("请输入第%d个下标: ",i+1);
        scanf("%d",&p[i]);
      }
      printf("您输入的矩阵为:\n");
      for(i=0;i<Mat-1;i++)
        printf("A%d[%d][%d] ",i+1,p[i],p[i+1]);
      printf("\n");
      matrixChain(p,m,s);
      printf("最优解如下:\n");
      printf("The m[%d][%d] 矩阵:\n",Mat-1,Mat-1);
      display(m);
      printf("The s[%d][%d] 矩阵:\n",Mat-1,Mat-1);
      display(s);
    return 0;
}
void matrixChain(int p[Mat], int m[Mat][Mat], int s[Mat][Mat])
{
   int n=Mat-1,i,j,r,k,t;
   for(i=1;i<=n;i++) m[i][i]=0;
   //r为问题规模
   for(r=2;r<=n;r++)
      //规模为r的子问题个数
      for(i=1;i<=n-r+1;i++)
      {
        j=i+r-1;
        m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
        for(k=i+1;k<j;k++)
        {
           t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
           if(t<m[i][j])
           {
              m[i][j]=t;
              s[i][j]=k;
           }
        }
      }
}
void display(int S[Mat][Mat])
{
   int i,j;
   for(i=1;i<=Mat-1;i++)
      printf("%d      ",i);
   printf("\n\n");
   for(i=1;i<=Mat-1;i++)
   {
      printf("%d      ",i);
      for(j=1;j<=Mat-1;j++)
        printf("%d      ",S[i][j]);
      printf("\n");
   }
}
