#include<stdio.h>
char pair(int *a1,int *a2)
{
    int c1=0,c2=0,arr1[4],arr2[4],i;
    if(a1[0]==a1[1])
    {
        arr1[0]=a1[0];
        arr1[1]=a1[2];
        arr1[2]=a1[3];
        arr1[3]=a1[4];
        c1++;
    }
    else if(a1[1]==a1[2])
    {
        arr1[0]=a1[1];
        arr1[1]=a1[0];
        arr1[2]=a1[3];
        arr1[3]=a1[4];
        c1++;
    }
    else if(a1[2]==a1[3])
    {
        arr1[0]=a1[2];
        arr1[1]=a1[0];
        arr1[2]=a1[1];
        arr1[3]=a1[4];
        c1++;
    }
    else if(a1[3]==a1[4])
    {
        arr1[0]=a1[3];
        arr1[1]=a1[0];
        arr1[2]=a1[1];
        arr1[3]=a1[2];
        c1++;
    }
    if(a2[0]==a2[1])
    {
        arr2[0]=a2[0];
        arr2[1]=a2[2];
        arr2[2]=a2[3];
        arr2[3]=a2[4];
        c2++;
    }
    else if(a2[1]==a2[2])
    {
        arr2[0]=a2[1];
        arr2[1]=a2[0];
        arr2[2]=a2[3];
        arr2[3]=a2[4];
        c2++;
    }
    else if(a2[2]==a2[3])
    {
        arr2[0]=a2[2];
        arr2[1]=a2[0];
        arr2[2]=a2[1];
        arr2[3]=a2[4];
        c2++;
    }
    else if(a2[3]==a2[4])
    {
        arr2[0]=a2[3];
        arr2[1]=a2[0];
        arr2[2]=a2[1];
        arr2[3]=a2[2];
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
   // for(i=0;i<4;i++)
    //{
      //  printf("%d,%d\n",arr1[i],arr2[i]);
    //}
    if(c1!=0 && c2!=0)
    {
        if(arr1[0]>arr2[0])
        {
             printf("Black wins\n");
             return 1;
        }
        if(arr1[0]<arr2[0])
        {
             printf("White wins\n");
             return 1;
        }
        for(i=3;i>=1;i--)
        {
            if(arr1[i]>arr2[i])
            {
                printf("Black wins\n");
                return 1;
            }
            if(arr1[i]<arr2[i])
            {
                printf("White wins\n");
                return 1;
            }
        }
        printf("Tie\n");
        return 1;
    }
}
