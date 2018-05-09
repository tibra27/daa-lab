#include<stdio.h>
char two_pairs(int *a1,int *a2)
{
    int c1=0,c2=0,max1,max2,min1,min2,up1,up2;
    if(a1[0]==a1[1] && a1[2]==a1[3])
    {
        max1=(a1[1]>a1[3]?a1[1]:a1[3]);
        min1=(a1[1]<a1[3]?a1[1]:a1[3]);
        up1=a1[4];
        c1++;
    }
    else if(a1[1]==a1[2] && a1[3]==a1[4])
    {
        max1=(a1[1]>a1[3]?a1[1]:a1[3]);
        min1=(a1[1]<a1[3]?a1[1]:a1[3]);
        up1=a1[0];
        c1++;
    }
    else if(a1[0]==a1[1] && a1[3]==a1[4])
    {
        max1=(a1[1]>a1[3]?a1[1]:a1[3]);
        min1=(a1[1]<a1[3]?a1[1]:a1[3]);
        up1=a1[2];
        c1++;
    }
    if(a2[0]==a2[1] && a2[2]==a2[3])
    {
        max2=(a2[1]>a2[3]?a2[1]:a2[3]);
        min2=(a2[1]<a2[3]?a2[1]:a2[3]);
        up2=a2[4];
        c2++;
    }
    else if(a2[1]==a2[2] && a2[3]==a2[4])
    {
        max2=(a2[1]>a2[3]?a2[1]:a2[3]);
        min2=(a2[1]<a2[3]?a2[1]:a2[3]);
        up2=a2[0];
        c2++;
    }
    else if(a2[0]==a2[1] && a2[3]==a2[4])
    {
        max2=(a2[1]>a2[3]?a2[1]:a2[3]);
        min2=(a2[1]<a2[3]?a2[1]:a2[3]);
        up2=a2[2];
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
        if(max1>max2)
        {
             printf("Black wins\n");
             return 1;
        }
        if(max1<max2)
        {
             printf("White wins\n");
             return 1;
        }
        if(max1==max2)
        {
             if(min1>min2)
             {
                  printf("Black wins\n");
                  return 1;
             }
             if(min1<min2)
             {
                  printf("White wins\n");
                  return 1;
             }
             if(min1==min2)
             {
                  if(up1>up2)
                  {
                      printf("Black wins\n");
                      return 1;
                  }
                  if(up1<up2)
                  {
                      printf("White wins\n");
                      return 1;
                  }
                  if(up1==up2)
                  {
                      printf("Tie\n");
                      return 1;
                  }
             }
        }
    }
}
