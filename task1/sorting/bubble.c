#include"sign.h"
#include"vari.h"
#include<stdio.h>
void bubble_sort(int *a,int n)
{
	for(i=0;i<n;i++)
	{
		c=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				c++;
			}
		}
		if(c==0)
		break;
	}
/*	printf("the sorted array using bubble sort is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}*/
	printf("\n");
}
