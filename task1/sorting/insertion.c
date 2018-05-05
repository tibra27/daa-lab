#include"sign.h"
#include"vari.h"
#include<stdio.h>
void insertion_sort(int *a,int n)
{
	for(i=1;i<n;i++)
	{
		e=a[i];
		j=i;
		while(j>0 && a[j-1]>e)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=e;
	}
/*	printf("the sorted array using insertion sort is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}*/
	printf("\n");
}
