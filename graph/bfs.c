#include<stdio.h>
int main()
{
    int v,i,j;
    FILE *f=fopen("in.txt","r");
    fscanf(f,"%d\n",&v);
    int mat[v][v];
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

    //BFS OF GRAPH.................
    int st[v],que[v],rr=0,fr=0,u;
    for(i=0;i<v;i++)
    {
        st[i]=0;
    }
    st[0]=1;
    que[0]=0;
    rr++;
    printf("\nbfs for graph is::\n");
    while(rr!=fr)
    {
        u=que[fr];
        fr++;
        for(i=0;i<v;i++)
        {
            if(mat[u][i]==1 && st[i]==0)
            {
                que[rr]=i;
                rr++;
                st[i]=st[u]+1;
            }
        }
        printf("%d->level=%d\n",u,st[u]-1);
    }


    return 0;
}
