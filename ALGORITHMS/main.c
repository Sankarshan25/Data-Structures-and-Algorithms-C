#include <stdio.h>
#include <stdlib.h>
void QuickSort(int a[],int lb,int ub);
int Partition(int a[],int lb,int ub);
void swap();

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
    QuickSort(a,lb,ub);

    printf("\nThe elements of the array after sorting are:\t");

    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }
}

void QuickSort(int a[],int lb,int ub)
{

    int loc;
    if(lb<ub)
    {
        loc=Partition(a,lb,ub);
        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);
    }
}

int Partition(int a[],int lb,int ub)
{
    int pivot=a[lb];
    int start=lb, end=ub;

    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }

        while(a[end]>pivot)
        {
            end--;
        }

        if(start<end)
        {
            swap(&a[start],&a[end]);
        }

    }

    swap(&a[lb],&a[end]);

    return end;

}

void swap(int *x,int *y)
{

    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}
