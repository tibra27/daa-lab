#include<stdio.h>

int lookup(char *a,char ch)
{
	int i=0;
	while(ch!=a[i])
	{
		i++;
	}
	return i;
}
int initializebase(FILE *po,char *a)
{
	int count=0;
	char di=fgetc(po);
	while(di!=EOF)
	{
		if(di!=' ')
		{
			a[count]=di;
			count++;
		}
		di=fgetc(po);
	}
	return(count-1);	
}

