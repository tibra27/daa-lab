#include<stdio.h>
void knap(int *weight,int *profit,int n,int w)
{
    int i,j;
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
	printf("max. profit=%d\n",ans[n][w]);
}
