#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
int partition(int a[size],int l,int r)
{
    int i,j,pivot,temp;
    pivot=a[l];
    i=l+1;
    j=r;
    while(1)
    {
        while(pivot>=a[i]&&i<=r)
        {
            count++;
            i++;
        }
        while(pivot<a[j])
        {
            count++;
            j--;
        }
        count++;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[j];
            a[j]=a[l];
            a[l]=temp;
            return j;
        }
    }
}
void QuickSort(int a[size],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        QuickSort(a,l,s-1);
        QuickSort(a,s+1,r);
    }
}
int main()
{
    int i,j,n,a[size];
    printf("\nEnter size of array\n");
    scanf("%d",&n);
    printf("\nEnter the elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    QuickSort(a,0,n-1);
    printf("\nSorted array is \n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nThe total number of comparison:%d\n",count);
    return 0;
}
