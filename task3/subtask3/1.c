#include<stdio.h>
char straight_flush(int *a1,char *b1,int *a2,char *b2)
{
	int i,c1=0,c2=0,c3=0,c4=0,r1,r2;
	for(i=0;i<4;i++)
	{
	if(b1[i]==b1[i+1])
		c1++;
	if(b2[i]==b2[i+1])
		c2++;
	}
//	printf("%d,%d",c1,c2);
	if(c1!=4 && c2!=4)
	{
		//printf("ddd\n");
		return('N');
	}
	if(c1==4 && c2!=4)
	{
		c3=0;
		for(i=0;i<4;i++)
		{
			if(a1[i]==a1[i+1]-1)
			{
				c3++;
			}
			if((c3==3 && a1[4]==14 && a1[0]==2) || c3==4)
			{
				printf("Black wins\n");
				return;
			}
			else
			{
			//	printf("ccc\n");
				return('N');
			}
		}
	}
	if(c1!=4 && c2==4)
	{
		c3=0;
		for(i=0;i<4;i++)
		{
			if(a2[i]==a2[i+1]-1)
			{
				c3++;
			}
			if((c3==3 && a2[4]==14 && a2[0]==2) || c3==4)
			{
				printf("White wins\n");
				return;
			}
			else
			{
			//	printf("bbb\n");
				return('N');
			}
		}
	}
	if(c1==4 && c2==4)
	{
		c3=0;
		for(i=0;i<4;i++)
		{
			if(a1[i]==a1[i+1]-1)
			{
				c3++;
			}
			if(((c3==3) && (a1[4]==14) && (a1[0]==2)) || c3==4)
			{
				c3=4;
				r1=a1[4];
			}
		}
		c4=0;
		for(i=0;i<4;i++)
    	{
			if(a2[i]==a2[i+1]-1)
			{
				c4++;
			}
			if((c4==3 && a2[4]==14 && a2[0]==2) || c4==4)
			{
				c4=4;
				r2=a2[4];
			}
		}
		if(c3==4 && c4==4)
		{
		//	printf("%d,%d",r1,r2);
			if(r1==r2)
			{
				printf("Tie\n");
				return;
			}
			if(r1>r2)
			{
				printf("Black wins\n");
				return;
			}
			if(r1<r2)
			{
				printf("White wins\n");
				return;
			}
		}
		if(c3==4 && c4!=4)
		{
			printf("Black wins\n");
			return;
		}
		if(c3!=4 && c4==4)
		{
			//printf("%d,%d",c3,c4);
			printf("White wins\n");
			return;
		}
		if(c3!=4 && c4!=4)
		{
		//	printf("%d %d",c3,c4);
		//	printf("aaa\n");
			return('N');
		}
	}
}

