#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,len1,len2,c=0,k;
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
    int pre[len2];
    pre[0]=0;
    j=0;
    i=1;
    while(i<len2)
    {
    	if(pat[j]==pat[i])
    	{
			pre[i]=j+1;
			i++;    		
			j++;
		}
		else
		{
			if(j==0)
			{
				pre[i]=0;
				i++;
			}
			else
			{
				j=pre[j-1];
			}
		}
	}
/*	for(i=0;i<len2;i++)
	{
		printf("%d  ",pre[i]);
	}*/
	i=0;
	j=0;
	while(j<len1)
	{
		if(pat[i]==text[j])
		{
			i++;
			j++;
		}
		else if(j<len1 && pat[i]!=text[j])
		{
			if(i!=0)
			{
				i=pre[i-1];
			}
			else
			{
				j=j+1;
			}
		}
		if(i==len2)
		{
			printf("%d\n",j-i);
			i=pre[i-1];
		}
	}
    return 0;
}
    
