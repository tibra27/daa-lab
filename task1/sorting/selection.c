#include"sign.h"
#include"vari.h"
#include<stdio.h>
void selection_sort(int *a,int n)
{
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
/*	printf("the sorted array using selection sort is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}*/
	printf("\n");
}
