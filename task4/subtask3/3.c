#include<stdio.h>
#include<stdlib.h>
void generate(int V)
{
	int E,i=1,j;
	E=((V*(V-1))/2);// maximum edges for confirmed
	int set[E+1][2];
	while(i<=E)
	{
		set[i][0] = rand()%(V+1);
		set[i][1] = rand()%(V+1);
		if((set[i][0]==0||set[i][1]==0))
		{
			set[i][0] = rand()%(V+1);
			set[i][1] = rand()%(V+1);	
		}
        if(set[i][0] == set[i][1])
	    	continue;
		for(j=0;j<i;j++)
			if((set[i][0]==set[j][0]&&set[i][1]==set[j][1])||(set[i][0]==set[j][1]&&set[i][1]==set[j][0]))
				i--;
		i++;
	}
	printf("connected graph:\n");
	for(i=1;i<=V;i++)
	{
		printf("%d",i);
		for(j=1;j<=E;j++)
		{
		 	if(set[j][0]==i)
		 	{
		 	printf("->%d",set[j][1]);  	
			}
	    }
	    printf("\n");
	}
}	
int main()
{
	int V;
	printf("enter the no. of vertices:\n");
	scanf("%d",&V);
	generate(V);
	return 0;
}

