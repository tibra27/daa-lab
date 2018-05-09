#include<stdio.h>
char full_house(int *a1,int *a2)
{
    int c1=0,c2=0;
    if(((a1[0]==a1[1] && a1[1]==a1[2]) && (a1[3]==a1[4])) || ((a1[2]==a1[3] && a1[3]==a1[4]) && (a1[0]==a1[1])))
    {
        c1++;
    }
    if(((a2[0]==a2[1] && a2[1]==a2[2]) && (a2[3]==a2[4])) || ((a2[2]==a2[3] && a2[3]==a2[4]) && (a2[0]==a2[1])))
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
        if(a1[2]>a2[2])
        {
            printf("Black wins\n");
            return 1;
        }
        if(a1[2]<a2[2])
        {
            printf("White wins\n");
            return 1;
        }
        if(a1[2]==a2[2])
        {
            printf("Tie\n");
            return 1;
        }
    }
}
