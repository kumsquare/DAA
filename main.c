#include <stdio.h>
#include <stdlib.h>

void Dijkstras(int cost[10][10],int n,int source)
{
    int i,u,v,count=1,dist[10],visited[10],min;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=cost[source][i];
    }
    visited[source]=1;
    dist[source]=0;
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0&&dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        count++;
        for(i=1;i<=n;i++)
        {

            if(dist[i]>dist[u]+cost[u][i])
                dist[i]=dist[u]+cost[u][i];
        }
    }
    printf("\nShortest path from %d\n",source);
    for(i=1;i<=n;i++)
    {
        printf("\n %d to %d is %d \n",source,i,dist[i]);
    }
}
int main()
{
    int n,cost[10][10],i,j,source;
    printf("\n read number of nodes\n");
    scanf("%d",&n);
    printf("\n read source vertex\n");
    scanf("%d",&source);
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
    Dijkstras(cost,n,source);
    return 0;
}
/*0 3 7 999 999
3 0 2 4 999
7 2 0 5 4
999 4 5 0 6
999 999 4 6 0*/
