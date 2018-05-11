#include<stdio.h>
#include"fun.h"
int main()
{
	int n,w,i;
	float weight[100],profit[100];
	FILE *f=fopen("t1.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%d\n",&n);
		fscanf(f,"%d\n",&w);
		for(i=0;i<n;i++)
		{
			fscanf(f,"%f\n",&weight[i]);
		}
		for(i=0;i<n;i++)
		{
			fscanf(f,"%f\n",&profit[i]);
		}
    }
	printf("%d\n",n);
	printf("%d\n",w);
	for(i=0;i<n;i++)
	{
		printf("%f,%f\n",weight[i],profit[i]);
	}
	float rat[n],ans[n];
	for(i=0;i<n;i++)
	{
		rat[i]=profit[i]/weight[i];
	}
	for(i=0;i<n;i++)
	{
		ans[i]=0;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%f \n",rat[i]);
	}*/
	knapsack(rat,ans,weight,n,w);
	display(ans,profit,n);
	fclose(f);
	return 0;
}

