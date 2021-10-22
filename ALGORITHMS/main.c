#include <stdio.h>
#include <stdlib.h>
void MergeSort(int a[],int lb, int ub,int n);
void Merge(int a[],int lb,int mid,int ub,int n);

int main()
{
    int a[10],i,n,lb,ub;
    printf("Enter the size of Array:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter a[%d] element of the array:\t",i);
        scanf("%d",&a[i]);
    }

    printf("\nThe elements of the array are:");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=\t%d",i,a[i]);
    }

    //SORTING
    lb=0;
    ub=n-1;
    MergeSort(a,lb,ub,n);

    printf("\nThe elements of the array after sorting are:\t");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=\t%d",i,a[i]);
    }

    return 0;
}

void MergeSort(int a[],int lb, int ub,int size)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        MergeSort(a,lb,mid,size);
        MergeSort(a,mid+1,ub,size);
        Merge(a,lb,mid,ub,size);
    }
}


void Merge(int a[],int lb, int mid, int ub,int size)
{
    int b[size];
    int i=lb,j=mid+1,k=lb;

    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }

    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}
