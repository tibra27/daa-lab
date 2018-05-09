#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,c1=0,c2=0,d=0;
	char text[50],arr[50];
	printf("enter the string\n");
	scanf("%[^\n]s",text);
    int len=strlen(text);
    for(i=0;i<len;i++)
    {
    	if(text[i]=='X' || text[i]=='Y')
    	{
    		arr[d]=text[i];
    		d++;
		}
	}
    for(i=0;i<d+1;i++)
    {
    	if(arr[i]=='X')
    	{
    		for(j=i+1;j<d+1;j++)
    		{
    			if(arr[j]=='Y')
    			{
    				c1++;
    			}
    		}
    	}
    }
    printf("no. of substring=%d",c1);
	return 0;
}
