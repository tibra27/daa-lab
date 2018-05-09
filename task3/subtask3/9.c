#include<stdio.h>
char high_card(int *a1,int *a2)
{
    int i;
    for(i=4;i>=0;i--)
    {
        if(a1[i]>a2[i])
        {
            printf("Black wins\n");
            return 1;
        }
        if(a1[i]<a2[i])
        {
            printf("White wins\n");
            return 1;
        }
    }
    printf("Tie\n");
    return 1;
}
