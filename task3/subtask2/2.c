#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter the total elements in set\n");
	scanf("%d",&n);
	int set[n],arr[n];
	printf("enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&set[i]);
	}
	for(i=0;i<n;i++)
	{
		arr[i]=1;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]<(arr[j]+1) && set[i]>set[j])
			{
				arr[i]=arr[j]+1;
			}
		}
	}
	int m=arr[1];
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			m=arr[i];
		}
	}
	printf("max length=%d\n",m);
	return 0;
}
