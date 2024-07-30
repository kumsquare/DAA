#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
void BubbleSort(int A[size],int n)
{
    int i,j,temp;
    for(int i =0;i<=n;i++)
    {
        for(j=0;j<=n-i-2;j++)
        {
            count++;
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
    }
}
int main()
{
    int i,A[size],n;
    printf("\nRead array size:\n");
    scanf("%d",&n);
    printf("\nRead elements\n");
    for(i=0;i<=n;i++){
        scanf("%d",&A[i]);
    }
    BubbleSort(A,n);
    printf("\nSorted elements are\n");
    for(i=0;i<=n;i++){
        printf("%d\t",A[i]);
    }
    printf("\nNumber of comparision is %d\n",count);
    return 0;
}
