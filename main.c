#include <stdio.h>
#include <stdlib.h>

void Prims(int cost[10][10],int n)
{
    int i,j,visited[10],mincost=0,ne=1,min,u,v;
    for(i=1;i<n;i++)
        visited[i]=0;
    visited[1]=1;
    printf("\nEdge considered are\n");
    while(ne<n)
    {
        min=99;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==1)
                        continue;
                    else{
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(visited[u]==0||visited[v]==0)
        {
            printf("\n %d edge (%d,%d)=%d\n",ne++,u,v,min);
            mincost=mincost+min;
            visited[v]=1;
        }
        cost[u][v]=cost[v][u]=999;
    }
    printf("\n cost of spanning the tree is %d\n",mincost);
}

int main()
{
    int n,cost[10][10],i,j;
    printf("\n read number of nodes::");
    scanf("%d",&n);
    printf("\n read cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    Prims(cost,n);
    return 0;
}
/*
0 3 999 999 5 6
3 0 1 999 4 999
999 1 0 6 4 999
999 999 6 0 5 3
5 4 4 5 0 2
6 999 999 3 2 0 */
