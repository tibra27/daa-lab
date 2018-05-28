#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j,len1,len2,c=0,k;
	char text[1000],pat[100];
	FILE *f=fopen("2.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%s\n",text);
		fscanf(f,"%s\n",pat);
		len1=strlen(text);
		len2=strlen(pat);
		printf("%s\n",text);
		printf("%s\n",pat);
    }
	printf("valid shifts are:: ");
	while(i<len1)
	{
		if(text[i]==pat[0])
		{
			c=0;
			int x=i,q=i;
			for(k=1;k<len2;k++)
			{
				if(pat[k]==text[q+1])
				{
					c++;
					q++;
				}
			}
			if(c==len2-1)
			{
				printf("%d   ",x);
			}
		}
		i++;
	}
	return 0;
}
