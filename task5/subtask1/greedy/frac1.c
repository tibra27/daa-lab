#include<stdio.h>
void knapsack(float *rat,float *ans,float *weight,int n,int w)
{
    int c=0,i,k;
    float max;
	while(c<n)
	{
		max=rat[0];
		k=0;
		for(i=0;i<n;i++)
		{
			if(rat[i]>max)
			{
				max=rat[i];
				k=i;
			}
		}
		rat[k]=-1;
		if(weight[k]<=w)
		{
			w=w-weight[k];
			ans[k]=1;
		}
		else if(weight[k]>w && w!=0)
		{
			ans[k]=w/weight[k];
			break;
		}
		c++;
	}
}
