#include<stdio.h>
#include"fun.h"
void matrix_chain_order(int *p,int n)
{
	int i,j,q,k,l;
	int m[n][n],s[n][n];
	for(i=1;i<n;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<n;l++)
	{
		for(i=1;i<(n-l+1);i++)
		{
			j=i+l-1;
			m[i][j]=100000;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	print(n-1,s,1,n-1);

}
