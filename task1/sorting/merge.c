#include"sign.h"
#include<stdio.h>
void merge(int *arr, int beg, int mid, int end, int *temp)
{
	int i=beg, j=mid+1, index=beg,k;
	while((i<=mid) && (j<=end))
		{
 			if(arr[i] < arr[j])
				{
					temp[index] = arr[i];
					i++;
				}
			 else
 				{
					temp[index] = arr[j];
					j++;
				 }
		index++;
		}
if(i>mid)
	{
		 while(j<=end)
		 {
			temp[index] = arr[j];
			j++;
			index++;
		 }
	}
else
	{
 		while(i<=mid)
 		{
			temp[index] = arr[i];
			i++;
			index++;
		 }
	}

for(k=beg;k<index;k++)
		arr[k] = temp[k];
}
void merge_sort(int *arr, int beg, int end, int *temp)
{
	int mid;
	if(beg<end)
	{
		mid = (beg+end)/2;
 		merge_sort(arr, beg, mid, temp);
		merge_sort(arr, mid+1, end, temp);
 		merge(arr, beg, mid, end, temp);
	}
}
void display(int n,int *temp,int *arr)
{
	int i;
	merge_sort(arr, 0, n-1,temp);
/*	printf("\n The sorted array using merge sort is: \n");
	for(i=0;i<n;i++)
		printf(" %d ", temp[i]);*/
	printf("\n");
}

