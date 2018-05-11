#include<stdio.h>
int main()
{	
	int n,w,i,c=0,k;
	float weight[100],profit[100],max,p=0;
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
	printf("fraction of each item is::< ");
	for(i=0;i<n;i++)
	{
		printf("%f ",ans[i]);
	}
	printf(">\n");
	for(i=0;i<n;i++)
	{
		p=p+(ans[i]*profit[i]);	
	}
	printf("total profitable value=%f\n",p);
}

