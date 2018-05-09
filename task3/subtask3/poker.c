#include<stdio.h>
#include"fun.h"
void selection_sort(int *a,char *b)         
{
	int i,j,min,t;
	char p;
	for(i=0;i<5;i++)
	{
		min=i;
		for(j=i;j<5;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		t=a[i];
		p=b[i];
		a[i]=a[min];
		b[i]=b[min];
		a[min]=t;
		b[min]=p;
	}
}
int main()
{
	char suit1[5],suit2[5],arr[2],s1;
	int card1[5],card2[5],i,j,k;
	FILE *f=fopen("input.txt","r");
	while(!feof(f))
	{
		s1='Y';
		for(i=0;i<5;i++)                                //to convert all card values in int.
		{
			fscanf(f,"%s\n",arr);
			if(arr[0]=='A')
				card1[i]=14;
			else if(arr[0]=='K')
				card1[i]=13;
			else if(arr[0]=='Q')
				card1[i]=12;
			else if(arr[0]=='J')
				card1[i]=11;
			else if(arr[0]=='T')
				card1[i]=10;
			else
				card1[i]=arr[0]-'0';
			suit1[i]=arr[1];
			//printf("%d%c ",card1[i],suit1[i]);
		}
		printf("\n");
		for(i=0;i<5;i++)
		{
			fscanf(f,"%s\n",arr);
			if(arr[0]=='A')
				card2[i]=14;
			else if(arr[0]=='K')
				card2[i]=13;
			else if(arr[0]=='Q')
				card2[i]=12;
			else if(arr[0]=='J')
				card2[i]=11;
			else if(arr[0]=='T')
				card2[i]=10;
			else
				card2[i]=arr[0]-'0';
			suit2[i]=arr[1];
			//printf("%d  ",card2[i]);
		}
		selection_sort(card1,suit1);                    //sort all cards.
		selection_sort(card2,suit2);
		s1=straight_flush(card1,suit1,card2,suit2);
		if(s1!='N')
			continue;
		s1=four_of_kind(card1,card2);
		if(s1!='N')
			continue;
		s1=full_house(card1,card2);
		if(s1!='N')
			continue;
		s1=flush(card1,suit1,card2,suit2);
		if(s1!='N')
			continue;
		s1=straight(card1,card2);
		if(s1!='N')
			continue;
		s1=three_of_kind(card1,card2);
		if(s1!='N')
			continue;
		s1=two_pairs(card1,card2);
		if(s1!='N')
			continue;
		s1=pair(card1,card2);
		if(s1!='N')
			continue;
		s1=high_card(card1,card2);
		if(s1!='N')
			continue;

	}
	fclose(f);
	return 0;
}
