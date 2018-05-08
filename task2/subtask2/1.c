#include<stdio.h>
#include<string.h>
#include"3.h"
#include"2.h"
int main(int argc,char **argv)
{
	char *f1,*f2;
	f1=argv[1];
	f2=argv[2];
	FILE *po1,*po2;
	po1=fopen(f1,"r");
	int i,j,MaxD;
	char di[50];
	MaxD=initializebase(po1,di);
	fclose(po1);
	char opr[50],op1[50],op2[50];
	po2=fopen(f2,"r");
	while(!feof(po2))
	{
		fscanf(po2,"%s\n",opr);
		int b1,b2,n1,n2,l1,l2;
		fscanf(po2,"%d",&b1);
		fscanf(po2,"%s\n",op1);
		fscanf(po2,"%d",&b2);
		fscanf(po2,"%s\n",op2);
		l1=strlen(op1);
		l2=strlen(op2);
		n1=createnumber(op1,l1,b1,di);
		n2=createnumber(op2,l2,b2,di);
		if(opr[0]=='a' && opr[1]=='d' && opr[2]=='d')
		{
			add(n1,n2,b1,b2,di);
		}
		else
		{
			subtract(n1,n2,b1,b2,di);
		}
		printf("\n");
	}
	fclose(po2);
	return 0;
}
