#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include"sign.h"
#include"vari.h"
int main(int argc,char **argv)
{
    long time_start, time_end;
    struct timeval tv;
// Write all the initialization code here
    int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n],b[n],temp[n];
	for(i=0;i<n;i++)
	{
		a[i]=rand();
		b[i]=a[i];
	}
//start
    gettimeofday(&tv,NULL);
    time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here
    selection_sort(b,n);
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
    gettimeofday (&tv, NULL);
    time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
    printf("time for selection sort is=%ld micro sec.\n\n",time_end-time_start);
//end
//start
    gettimeofday(&tv,NULL);
    time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here
    bubble_sort(b,n);
    for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
    gettimeofday (&tv, NULL);
    time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
    printf("time for bubble sort is=%ld micro sec.\n\n",time_end-time_start);
//end
//start
    gettimeofday(&tv,NULL);
    time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here
    insertion_sort(b,n);
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
    gettimeofday (&tv, NULL);
    time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
    printf("time for insertion sort is=%ld micro sec.\n\n",time_end-time_start);
//end
//start
    gettimeofday(&tv,NULL);
    time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here
    display(n,temp,b);
    for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
    gettimeofday (&tv, NULL);
    time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
    printf("time for merge sort is=%ld micro sec.\n\n",time_end-time_start);
//end
//start
    gettimeofday(&tv,NULL);
    time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here
    show(n,b);
    for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
    gettimeofday (&tv, NULL);
    time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
    printf("time for quick sort is=%ld micro sec.\n\n",time_end-time_start);
//end
    return (0);
}
