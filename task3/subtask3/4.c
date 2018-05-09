#include<stdio.h>
char flush(int *a1,char *b1,int *a2,char *b2)
{
    int c1=0,c2=0,i;
    if(b1[0]==b1[1] && b1[1]==b1[2] && b1[2]==b1[3] && b1[3]==b1[4])
    {
        c1++;
    }
    if(b2[0]==b2[1] && b2[1]==b2[2] && b2[2]==b2[3] && b2[3]==b2[4])
    {
        c2++;
    }
    if(c1==0 && c2==0)
    {
        return('N');
    }
    if(c1!=0 && c2==0)
    {
        printf("Black wins\n");
        return 1;
    }
    if(c1==0 && c2!=0)
    {
        printf("White wins\n");
        return 1;
    }
    if(c1!=0 && c2!=0)
    {
        for(i=0;i<5;i++)
        {
            if(a1[i]==a2[i])
            {
                continue;
            }
            else if(a1[i]>a2[i])
            {
                printf("Black wins\n");
                return 1;
            }
            else if(a1[i]<a2[i])
            {
                printf("White wins\n");
                return 1;
            }
        }
        printf("Tie\n");
    }
}
