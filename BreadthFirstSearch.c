#include <stdio.h>
#include <stdlib.h>
void bfs(int a[10][10],int n, int visited[10],int source)
{
    int q[10],rear=-1,front=0,i,delnode;
    visited[source]=1;
    q[++rear]=source;
    while(front<=rear)
    {
        delnode= q[front++];
        for(i=1;i<=n;i++)
        {
            if(a[delnode][i]==1&&visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n, a[10][10],i,j,visited[10],count=0;
    printf("\nEnter the number of nodes:\n");
    scanf("%d",&n);
    printf("\nEnter adjacent matrix:\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            bfs(a,n,visited,i);
            count++;
        }
    }
    if(count==1)
        printf("graph is connected 1 components");
    else
        printf("Graph is not connected %d component",count);
    return 0;
}
