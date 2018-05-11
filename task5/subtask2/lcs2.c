#include<stdio.h>
void print(int len1,int len2,int len3,int sym[len1+1][len2+1][len3+1],char *p)
{
    int i,j,k,x=0;
    i=len1;
    j=len2;
    k=len3;
    char ans[len1+1];
    while(1)
    {
        if(i==0 || j==0 || k==0)
        {
            break;
        }
        else if(sym[i][j][k]==4)
        {
            ans[x]=p[i-1];
            x++;
            i--;
            j--;
            k--;
        }
        else if(sym[i][j][k]=1)
        {
           i--;
        }
        else if(sym[i][j][k]==2)
        {
            j--;
        }
        else if(sym[i][j][k]==3)
        {
            k--;
        }
    }
    for(i=x-1;i>=0;i--)
    {
        printf("%c ",ans[i]);
    }
}#include<stdio.h>
void print(int len1,int len2,int len3,int sym[len1+1][len2+1][len3+1],char *p)
{
    int i,j,k,x=0;
    i=len1;
    j=len2;
    k=len3;
    char ans[len1+1];
    while(1)
    {
        if(i==0 || j==0 || k==0)
        {
            break;
        }
        else if(sym[i][j][k]==4)
        {
            ans[x]=p[i-1];
            x++;
            i--;
            j--;
            k--;
        }
        else if(sym[i][j][k]=1)
        {
           i--;
        }
        else if(sym[i][j][k]==2)
        {
            j--;
        }
        else if(sym[i][j][k]==3)
        {
            k--;
        }
    }
    for(i=x-1;i>=0;i--)
    {
        printf("%c ",ans[i]);
    }
}
