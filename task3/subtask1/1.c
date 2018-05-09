#include <sys/time.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{ 
	long time_start, time_end;
	struct timeval tv;
	int i,j,c1=0,c2=0,c=0,d=0,e=0;
	char text[50],arr[50];
	printf("enter the string\n");
	scanf("%[^\n]s",text);
    int len=strlen(text);
// Time measurement begins here
	gettimeofday(&tv,NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here

 	for(i=0;i<len;i++)      
    {                                 
    	if(text[i]=='X')              
    	{                              
    		c1++;
    	}
    	if(text[i]=='Y')
    	{
    		c=c+c1;
    	}
    }
    printf("no. of substring=%d\n",c);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("executing time in method2(using single loop)=%ld\n",time_end-time_start);
	gettimeofday(&tv,NULL); 
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here

 	for(i=0;i<len;i++)
    {
    	if(text[i]=='X')
    	{
    		for(j=i+1;j<len;j++)
    		{
    			if(text[j]=='Y')
    			{
    				c2++;
    			}
    		}
    	}
    }
    printf("no. of substring=%d\n",c2);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("executing time in method2(using 2 loops)=%ld\n",time_end-time_start);
		gettimeofday(&tv,NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// Write the code to be analyzed here
 	 for(i=0;i<len;i++)
    {
    	if(text[i]=='X' || text[i]=='Y')
    	{
    		arr[d]=text[i];
    		d++;
		}
	}
    for(i=0;i<d+1;i++)
    {
    	if(arr[i]=='X')
    	{
    		for(j=i+1;j<d+1;j++)
    		{
    			if(arr[j]=='Y')
    			{
    				e++;
    			}
    		}
    	}
    }
    printf("no. of substring=%d\n",e);
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("executing time in method3(using 2 loop)=%ld\n",time_end-time_start);
	return 0;
}
