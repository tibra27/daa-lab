#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int i,j,len1,len2;
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
    int q=101,d=256;                         //take a prime no.
    int h=1;
    int p=0;            //hash value of pattern
    int t=0;            //hash value of text
	for(i=0;i<len2-1;i++)         //mod q is for avoiding integer overflow
	{
		h=(h*d)%q;
	}
    for(i=0;i<len2;i++)
    {
    	p=(d*p+pat[i])%q;
    	t=(d*t+text[i])%q;
	}
	for(i=0;i<=len1-len2;i++)
	{
		if(p==t)
		{
			for(j=0;j<len2;j++)
			{
				if(text[i+j]!=pat[j])
				{	
					printf("spurious hit at %d shift\n",i);
					break;
				}
			}
			if(j==len2)
			{
				printf("pattern is in text at %d shifts\n",i);
			}
		}
		if(i<len1-len2)
		{
			t=(d*(t-text[i]*h)+text[i+len2])%q;
			if(t<0)
			{
				t=t+q;
			}
		}
	}
    
	return 0;
}
