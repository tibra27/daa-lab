#include<stdio.h>
#include<stdlib.h>
int t=0;
struct para
{
    int value;
    int s_time;
    int f_time;
    int flag;
    int parent;
};


void DFS_VISIT(int v,int mat[v][v],struct para* arr[v],int u)
{
    arr[u]->flag=1;
    t=t+1;
    arr[u]->s_time=t;
    int i;
    for(i=0;i<v;i++)
    {
        if(mat[u][i]==1 && arr[i]->flag==0)
        {
            arr[i]->parent=u;
            DFS_VISIT(v,mat,arr,i);
        }
    }
    arr[u]->flag=2;
    arr[u]->f_time=(++t);

}

int main()
{
    int v,i,j;
    FILE *f=fopen("in.txt","r");
    fscanf(f,"%d\n",&v);
    int mat[v][v],mat1[v][v],mat2[v][v];
    while(!feof(f))
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                fscanf(f,"%d\n",&mat[i][j]);
            }
        }
    }
    printf("matrix representation of graph is::\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    //DFS OF GRAPH.................
    struct para* arr[v];


    for(i=0;i<v;i++)
    {
        arr[i]=(struct para*)malloc(sizeof(struct para));
        arr[i]->flag=0;
        arr[i]->parent=-1;
        arr[i]->s_time=0;
        arr[i]->f_time=0;
        arr[i]->value=i;
    }

    printf("\ndfs of given graph is::\n");
    for(i=0;i<v;i++)
    {
        if(arr[i]->flag==0)
        {
            DFS_VISIT(v,mat,arr,i);
        }
    }
    for(i=0;i<v;i++)
    {
        printf("%d %d %d %d\n",arr[i]->value,arr[i]->s_time,arr[i]->f_time,arr[i]->parent);
    }

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            mat1[i][j]=mat[i][j];
            mat2[i][j]=0;
        }
    }
    int sarr[2][v],farr[2][v],x,a,b,k;
    for(i=0;i<v;i++)
    {
        sarr[0][i]=arr[i]->value;
        sarr[1][i]=arr[i]->s_time;
        farr[0][i]=arr[i]->value;
        farr[1][i]=arr[i]->f_time;
    }
    ///sort a/c to starting time
    for(i=0;i<v;i++)
    {
        for(j=0;j<v-i-1;j++)
        {
            if(sarr[1][j+1]<sarr[1][j])
            {
               x=sarr[1][j+1];
               sarr[1][j+1]=sarr[1][j];
               sarr[1][j]=x;
               x=sarr[0][j+1];
               sarr[0][j+1]=sarr[0][j];
               sarr[0][j]=x;
            }
        }
    }
    ///sort a/c to finish time
    for(i=0;i<v;i++)
    {
        for(j=0;j<v-i-1;j++)
        {
            if(farr[1][j+1]>farr[1][j])
            {
               x=farr[1][j+1];
               farr[1][j+1]=farr[1][j];
               farr[1][j]=x;
               x=farr[0][j+1];
               farr[0][j+1]=farr[0][j];
               farr[0][j]=x;
            }
        }
    }
    //////////for forward edges
    for(i=0;i<v-1;i++)
    {
        if(sarr[1][i]==sarr[1][i+1]-1)
        {
            a=sarr[0][i];
            b=sarr[0][i+1];
            mat1[a][b]=mat1[b][a]=0;
            mat2[a][b]=1;
        }
        if(farr[1][i]==farr[1][i+1]+1)
        {
            a=farr[0][i];
            b=farr[0][i+1];
            mat1[a][b]=mat1[b][a]=0;
            mat2[a][b]=1;
        }
    }

    //////for dfs_num value
    int num[v][2];
    for(i=0;i<v;i++)
    {
        num[i][1]=i+1;
        num[i][0]=sarr[0][i];
    }
    int low[v][2];
    for(i=0;i<v;i++)
    {
        low[i][1]=num[i][1];
        low[i][0]=num[i][0];
    }
    int min,bedge[v][2],z=0;
    ///for backward edges
    for(i=0;i<v;i++)
    {
        min=100;
        for(j=0;j<v;j++)
        {
            if(mat1[i][j]==1)
            {
                a=i;
                b=j;
                mat1[i][j]=0;
                mat1[j][i]=0;
                if(sarr[1][i]>sarr[1][j])
                {
                    mat2[i][j]=1;
                    if(num[j][1]<min)
                    {
                       min=num[j][1];
                       low[i][1]=min;
                       bedge[z][0]=i;
                       bedge[z][1]=j;
                       z++;
                    }
                }
                else
                {
                    mat2[j][1]=1;
                    if(num[i][1]<min)
                    {
                       min=num[i][1];
                       low[j][1]=min;
                       bedge[z][0]=j;
                       bedge[z][1]=i;
                       z++;
                    }

                }
            }
        }
    }
    for(i=0;i<z;i++)                                //updating low values for in b/w nodes of backedge
    {
        int r,s,r1,s1;
        r=bedge[i][0];
        s=bedge[i][1];
        for(j=0;j<v;j++)
        {
            if(num[j][0]==r)
            {
                r1=num[j][1];
            }
            else if(num[j][0]==s)
            {
                s1=num[j][1];
            }
        }
        for(j=s1+1;j<r1;j++)
        {
            if(num[j-1][1]>num[s1-1][1])
            {
                if(low[j-1][1]>num[s1-1][1])
                    low[j-1][1]=num[s1-1][1];
            }
        }
    }
    printf("\n vertex dfs_num dfs_low\n");
    for(i=0;i<v;i++)
    {
        printf("%5d %5d %5d\n",num[i][0],num[i][1],low[i][1]);
    }


    ///finding articulation point......
    int c=0,c1=0,c2=0;
    for(i=0;i<v;i++)           //for root node
    {
        if(mat2[0][i]==1)
        {
            c++;
        }
    }
    if(c>=2)
    {
        printf("\nthe articulation point is::%d\n",0);
    }
    c=0;
    for(i=1;i<v;i++)
    {
        c=0;
        c1=0;
        c2=0;
        for(j=0;j<v;j++)
        {
            if(mat2[i][j]==1)
            {
                for(k=0;k<z;k++)
                {
                    if(i==bedge[k][0] && j==bedge[k][1])
                    {
                        c++;
                    }
                }
                c1++;
            }
        }
        if(c>=0 && c<=z && c1==c)
        {
                    //for leaf node
        }
        else
        {
            for(j=0;j<v;j++)
            {
                if(mat2[i][j]==1)
                {
                    for(k=0;k<z;k++)
                    {
                        if(i==bedge[i][0] && j==bedge[i][1])
                        {

                        }
                        else
                        {
                            if(low[j][1]>=num[i][1])
                            {
                                printf("\nthe articulation point is::%d\n",i);
                                c2++;
                                break;
                            }
                        }
                    }
                    if(c2>0)
                    {
                        break;
                    }
                }
            }
        }
    }

    return 0;
}






























