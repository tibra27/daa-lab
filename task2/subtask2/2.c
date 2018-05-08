#include<stdio.h>
#include"3.h"
int createnumber(char *ch,int l,int base,char *a)
{
	int i,j=0,k=1;
	for(i=0;i<l;i++)
	{
		j=j+((lookup(a,ch[l-1-i]))*k);
		k=k*base;
	}
	return j;
}
void convert(int r,int b1,int b2,char *ch)
{
	char re[50];
	int i=0,j;
	if(b1>b2)
	{
		while(r!=0)
		{
			re[i]=ch[r%b1];
			i++;
			r=r/b1;	
		}
		for(j=i-1;j>=0;j--)
		{
			printf("%c",re[j]);
		}
		printf("(%d)\n",b1);
	}
	else
	{
		while(r!=0)
		{
			re[i]=ch[r%b2];
			i++;
			r=r/b2;	
		}
		for(j=i-1;j>=0;j--)
		{
			printf("%c",re[j]);
		}
		printf("(%d)\n",b2);
	}
}
void add(int a1,int a2,int b1,int b2,char *ch)
{
	int res;
	res=a1+a2;
	convert(res,b1,b2,ch);
}
void subtract(int a1,int a2,int b1,int b2,char *ch)
{
	int res;
	res=a1-a2;
	convert(res,b1,b2,ch);
}

