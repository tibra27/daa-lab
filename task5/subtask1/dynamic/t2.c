#include<stdio.h>
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
	int ans[n+1][w+1];
	
	for(i=0;i<w+1;i++)
	{
		ans[0][i]=0;
	}
	for(i=1;i<n+1;i++)
	{
		ans[i][0]=0;
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<w+1;j++)
		{
			if(j<weight[i-1])
			{
				ans[i][j]=ans[i-1][j];
			}
			else
			{
				ans[i][j]=(((ans[i-1][j-weight[i-1]]+profit[i-1])>(ans[i-1][j]))?(ans[i-1][j-weight[i-1]]+profit[i-1]):(ans[i-1][j]));
			}
		}
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<w+1;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	i=n;
	j=w;
	printf("items are:: < ");
	while(i!=0)
	{
		if(ans[i][j]==ans[i-1][j])
		{
			i--;
		}
		else
		{
			printf("%d ",i);
			i--;
			j=j-weight[i];
		}
	}
	printf(">\n");
}

