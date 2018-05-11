#include<stdio.h>
#include"sign.h"
int main()
{
	char st1[1000],st2[1000],st3[1000];
	FILE *f=fopen("2.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%s\n",st1);
		fscanf(f,"%s\n",st2);
		fscanf(f,"%s\n",st3);
		printf("%s\n",st1);
		printf("%s\n",st2);
		printf("%s\n",st3);
    }
    fclose(f);
    lcs(st1,st2,st3);
    return 0;
}
