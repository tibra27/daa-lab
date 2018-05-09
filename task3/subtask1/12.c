#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,c1=0,c2=0,c=0;
	char text[50];
	int arr[50];
	printf("enter the string\n");
	scanf("%[^\n]s",text);
    int len=strlen(text);
    for(i=0;i<len;i++)
    {
    	if(text[i]=='X')
    	{
    		c1++;
    	}
    	if(text[i]=='Y')
    	{
    		c=c+c1;
    	}
    }
    printf("no. of substring=%d",c);
	return 0;
}
