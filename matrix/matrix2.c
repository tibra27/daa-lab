#include<stdio.h>
#include"fun.h"
void print(int n,int s[n+1][n+1],int i,int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		print(n,s,i,s[i][j]);
		print(n,s,s[i][j]+1,j);
		printf(")");
	}
}


