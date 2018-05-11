#include<stdio.h>
#include<string.h>
#include"sign.h"
int max(int a,int b,int c)
{
	if(a>b)
	{
		if(a>c)
			return a;
		else
			return c;
	}
	else
	{
		if(b>c)
			return b;
		else
			return c;
	}
}
void lcs(char *p,char *q,char*r)
{
	int i,j,k,len1,len2,len3;
	len1=strlen(p);
	len2=strlen(q);
	len3=strlen(r);
	int set[len1+1][len2+1][len3+1];
	int sym[len1+1][len2+1][len3+1];
	/*for(i=0;i<len1+1;i++)
	{
		set[i][0][0]=0;
	}
	for(j=0;j<len2+1;j++)
	{
		set[0][j][0]=0;
	}
	for(k=0;k<len3+1;k++)
	{
		set[0][0][k]=0;
	}*/
	for(i=0;i<len1+1;i++)
	{
		for(j=0;j<len2+1;j++)
		{
			for(k=0;k<len3+1;k++)
			{
				if(i==0 || j==0 || k==0)
				{
					set[i][j][k]=0;
				}
				else if(p[i-1]==q[j-1] && q[j-1]==r[k-1])
				{
					set[i][j][k]=set[i-1][j-1][k-1]+1;
					sym[i][j][k]=4;
				}
				else
				{
					if(max(set[i-1][j][k],set[i][j-1][k],set[i][j][k-1])==set[i-1][j][k])
					{
						set[i][j][k]=set[i-1][j][k];
						sym[i][j][k]=1;
					}
					if(max(set[i-1][j][k],set[i][j-1][k],set[i][j][k-1])==set[i][j-1][k])
					{
						set[i][j][k]=set[i][j-1][k];
						sym[i][j][k]=2;
					}
					if(max(set[i-1][j][k],set[i][j-1][k],set[i][j][k-1])==set[i][j][k-1])
					{
						set[i][j][k]=set[i][j][k-1];
						sym[i][j][k]=3;
					}
				}
			}
		}
	}
	printf("length of lcs=%d\n",set[len1][len2][len3]);
	print(len1,len2,len3,sym,p);
}
