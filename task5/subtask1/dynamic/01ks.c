#include<stdio.h>
#include"sign.h"
int main()
{
	int n,w,i,c=0,k,j;
	int weight[100],profit[100],max,p=0;
	FILE *f=fopen("t1.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%d\n",&n);
		fscanf(f,"%d\n",&w);
		for(i=0;i<n;i++)
		{
			fscanf(f,"%d\n",&weight[i]);
		}
		for(i=0;i<n;i++)
		{
			fscanf(f,"%d\n",&profit[i]);
		}
    }
	printf("%d\n",n);
	printf("%d\n",w);
	for(i=0;i<n;i++)
	{
		printf("%d,%d\n",weight[i],profit[i]);
	}

	knap(weight,profit,n,w);
	fclose(f);
	return 0;
}

