#include<stdio.h>
int main()
{
	int t,i,x,max;
	printf("enter no. of elements in array\n");
	scanf("%d",&t);
	int arrx[t];
	for(i=0;i<t;i++)
	{
		scanf("%d",&arrx[i]);
	}
	for(i=1;i<t;i++)
	{
		if(arrx[i]<(arrx[i-1]+arrx[i]))
		{
			arrx[i]=arrx[i-1]+arrx[i];
		}
	}
	max=arrx[0];
	for(i=1;i<t;i++)
	{
		if(arrx[i]>max)
		{
			max=arrx[i];
		}
	}
	printf("subseuences of max. sum are::");
	if(arrx[0]==max)
	{
		printf("[0:0]  ");
	}
	x=0;
	for(i=1;i<t;i++)
	{
		if(arrx[i]<0)
		{
			x=i+1;
		}
		if(arrx[i]==max)
		{
			printf("[%d:%d]  ",x,i);
		}
	}
	return 0;
}
