#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include"sign.h"
int main(int argc,char **argv)
{
// Declaration of timeval variables which will capture the system time
	long time_start, time_end;
	struct timeval tv;
// Write all the initialization code here
	int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n],b[n],c=0,d=0,e=0,f=0;
	for(i=0;i<n;i++)
	{
		a[i]=rand();
		b[i]=a[i];
	}
// Time measurement begins here
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// calculating start time in seconds
// Write the code to be analyzed here
	for(i=0;i<n;i++)
	{
		c=sum(a[i],c);
	}
	printf("sum=%d\n",c);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("time for sum=%ld\n",time_end-time_start);
// calculating end time in seconds //convert time in readable and printable precision
// (time_end-time_start) gives the total execution time measurement begins here
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// calculating start time in seconds
// Write the code to be analyzed here
	for(i=0;i<n;i++)
	{
		d=subtract(d,a[i]);
	}
	printf("subtraction=%d\n",d);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("time for subtraction=%ld\n",time_end-time_start);
// calculating end time in seconds //convert time in readable and printable precision
// (time_end-time_start) gives the total execution time measurement begins here
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// calculating start time in seconds
// Write the code to be analyzed here
	for(i=0;i<n;i++)
	{
		e=multiply(e,a[i]);
	}
	printf("multiplication=%d\n",e);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
        printf("time for multiply=%ld\n",time_end-time_start);
// calculating end time in seconds //convert time in readable and printable precision
// (time_end-time_start) gives the total execution time measurement begins here
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// calculating start time in seconds
// Write the code to be analyzed here
	for(i=0;i<n;i++)
	{
		f=division(f,a[i]);
	}
	printf("division=%d\n",f);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("time for division=%ld\n",time_end-time_start);
// calculating end time in seconds //convert time in readable and printable precision
// (time_end-time_start) gives the total execution time
	return (0);
}
