#include<stdio.h>
void display(float *ans,float *profit,int n)
{
    int i;
    float p=0;
	printf("fraction of each item is::< ");
	for(i=0;i<n;i++)
	{
		printf("%f ",ans[i]);
	}
	printf(">\n");
	for(i=0;i<n;i++)
	{
		p=p+(ans[i]*profit[i]);
	}
	printf("total profitable value=%f\n",p);
}
