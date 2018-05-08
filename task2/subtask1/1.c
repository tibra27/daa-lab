#include <sys/time.h>
#include<stdio.h>
int main(int argc,char **argv)
{ 
	long time_start, time_end;
	struct timeval tv;
// Write all the initialization code here
	int p,q,a,b,flag1,flag2,flag;
	p=strtol(argv[1],NULL,0);
	q=strtol(argv[2],NULL,0);
	int mat[p][q];
	flag1=((p%2==0)?p/2:(p/2)+1);
	flag2=((q%2==0)?q/2:(q/2)+1);
	flag=(flag1>flag2?flag2:flag1);

// Time measurement begins here
	gettimeofday(&tv,NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// calculating start time in seconds
	for(a=0;a<flag;a++)
	{ 	
		for(b=a;b<q-a;b++)
		{
			mat[a][b]=a;
			mat[p-a-1][b]=a;
		}
	}
	for(a=0;a<flag;a++)
	{ 	
		for(b=a;b<p-a;b++)
		{
			mat[b][a]=a;
			mat[b][q-a-1]=a;
		}
	}
// Write the code to be analyzed here
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	for(a=0;a<p;a++)
	{
		for(b=0;b<q;b++)
		{
			printf("%d   ",mat[a][b]);	
		}
		printf("\n");
	}
	printf("time of exection=%ld",time_end-time_start);
	return (0);
}
