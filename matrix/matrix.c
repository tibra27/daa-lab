#include<stdio.h>
#include"fun.h"
int main()
{
	int i=0,j,n;
	FILE *f=fopen("in.txt","r+");
	fscanf(f,"%d\n",&n);
	int p[n];
	printf("%d\n",n);
	while(!feof(f))
	{
		fscanf(f,"%d\n",&p[i]);
		i++;
	}
	fclose(f);
	for(j=0;j<n;j++)
	{
		printf("%d ",p[j]);
	}
	matrix_chain_order(p,n);
    return 0;
}
