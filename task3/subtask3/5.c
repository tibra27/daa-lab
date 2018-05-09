#include<stdio.h>
char straight(int *a1,int *a2)
{
    int c1=0,c2=0;
    if((a1[0]==a1[1]-1 && a1[1]==a1[2]-1 && a1[2]==a1[3]-1 && a1[3]==a1[4]-1) || (a1[0]==2 && a1[1]==3 && a1[2]==4 && a1[3]==5 && a1[4]==14))
    {
        c1++;
    }
    if((a2[0]==a2[1]-1 && a2[1]==a2[2]-1 && a2[2]==a2[3]-1 && a2[3]==a2[4]-1) || (a2[0]==2 && a2[1]==3 && a2[2]==4 && a2[3]==5 && a2[4]==14))
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
        if(a1[4]>a2[4])
        {
            printf("Black wins\n");
            return 1;
        }
        if(a1[4]<a2[4])
        {
            printf("White wins\n");
            return 1;
        }if(a1[4]==a2[4])
        {
            printf("Tie\n");
            return 1;
        }
    }
}
