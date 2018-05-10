#include <sys/time.h>
#include<stdio.h>
int main(int argc,char **argv)
{ 
	FILE *f=fopen("1.txt","r");
	int mat[8][8],i,j,k,c=0,fin=0,small;
	while(!feof(f))
	{
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				fscanf(f,"%d\n",&mat[i][j]);	
	}
	for(i=0;i<8;i++)
	{
			for(j=0;j<8;j++)
				printf("%d\t",mat[i][j]);	
			printf("\n");
	}
	printf("\n");
	int set[8];	//for double the ''row''(prevent from multiple doubling)
long time_start, time_end;
struct timeval tv;
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	while(fin!=8)
	{
		fin=0;
		for(i=0;i<8;i++)	
		{
			set[i]=0;
		}
		//subtract smallest-1 from all 'column' respectively
		for(i=0;i<8;i++)
		{
			small=mat[0][i];
			c=0;
			for(j=0;j<8;j++)
			{
				if(mat[j][i]<=small)
				{
					small=mat[j][i];
				}
			}
			for(j=0;j<8;j++)
			{
				if(mat[j][i]==small)
				{
					set[j]=1;
					c++;
				}
			}
			if(small>1 && c!=8)
			{
				for(j=0;j<8;j++)
				{
					mat[j][i]=mat[j][i]-(small-1);//as we have to make it 1 not 0
				}
			}
			else if(c==8)
			{
				for(j=0;j<8;j++)
				{
					mat[j][i]=mat[j][i]-(small);//make whole column zero
				}
			}
		}
		
		//now double of rows
		for(j=0;j<8;j++)
		{
			if(set[j]==1)
			{
				for(k=0;k<8;k++)
				{
					mat[j][k]=mat[j][k]*2;
				}
			}
		}
		for(k=0;k<8;k++)
		{
			if(mat[0][k]==0)	//if first element is 0 then entire column must be zero as per condition
			{
				fin++;
			}
		}
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	for(i=0;i<8;i++)
	{
			for(j=0;j<8;j++)
				printf("%d\t",mat[i][j]);	
			printf("\n");
	}
printf("\n\nexecution time==%ld\n",time_end-time_start);
return (0);
}
