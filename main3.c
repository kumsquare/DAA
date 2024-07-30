#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
void SelectionSort(int A[size],int n)
{
    int i,j,temp,min;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            count++;
            if(A[j]<A[min])
                min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}
int main()
{
    int i,A[size],n;
    printf("\nRead array size\n");
    scanf("%d",&n);
    printf("\nRead elements\n");
    for(i=0;i<n;
    i++)
        scanf("%d",&A[i]);
    SelectionSort(A,n);
    printf("\nSorted elements are\n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\nNumber of comparison is %d\n",count);
    return 0;
}

