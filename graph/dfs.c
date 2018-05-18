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
    return 0;
}
