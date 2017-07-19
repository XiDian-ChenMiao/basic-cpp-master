#include <stdio.h>
#include <stdlib.h>
#define max 20
int len[max][max];
//记录影响len的变化
int b[max][max];

void lcs(char x[],char y[],int lx,int ly)
{
      for(int i=0;i<=lx;i++)
      {
          len[i][0]=0;
      }
      for(int j=0;j<=ly;j++)
      {
         len[0][j]=0;
      }
      for(int i=0;i<lx;i++)
      {
          for(int j=0;j<ly;j++)
          {
               if(x[i]==y[j])
               {
                    len[i][j]=len[i-1][j-1]+1;
                    //改变b[][],记录b的变化为1
                    b[i][j]=1;
               }
               else if(len[i-1][j]>=len[i][j-1])
               {
                    len[i][j]=len[i-1][j];
                    //  改变b[][],记录b的变化为2
                    b[i][j]=2;
               }
               else
               {
                    len[i][j]=len[i][j-1];
                    //  改变b[][],记录b的变化为3
                    b[i][j]=3;
               }
          }
      }

}

void getB(char x[],int i,int j)
{
     if((i+1)==0 || (j+1)==0)
     {
          return ;
     }
     if(b[i][j]==1)
     {
          getB(x,i-1,j-1);
          printf("%c",x[i]);
     }
     else if(b[i][j]==2)
     {
          getB(x,i-1,j);
     }
     else  if(b[i][j]==3)
     {
           getB(x,i,j-1);
     }

}

int main()
{
    int masterStringLength;
	printf("输入主串长度:");
	scanf("%d",&masterStringLength);
	int slavesStringLength;
	printf("输入从串长度:");
	scanf("%d",&slavesStringLength);
	char HostString[masterStringLength],SlaveString[slavesStringLength];
	printf("输入主串:");
	scanf("%s",&HostString);
	printf("输入从串:");
	scanf("%s",&SlaveString);
	int i,j;
     lcs(HostString,SlaveString,masterStringLength,slavesStringLength);
     for(i = 0;i < masterStringLength;i++)
	{
		for(j = 0;j < slavesStringLength;j++)
			printf("%3d",len[i][j]);
		printf("\n");
	}
     printf("最长公共子序列:");
     getB(HostString,masterStringLength-1,slavesStringLength-1);
     system("pause");
     return 0;
}
