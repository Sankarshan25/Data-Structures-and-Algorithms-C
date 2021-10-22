#include <stdio.h>
#include <stdlib.h>
void Heap_Sort(int a[],int n);
void Max_Heapify(int a[],int n,int i);
void swap(int *x,int *y);

int main()
{
    int a[10],i,n;
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
    Heap_Sort(a,n);

    printf("\nThe elements after sorting are:\t");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }
    return 0;
}

void Heap_Sort(int a[],int n)
{
    int i;

    //BUILDING MAX_HEAP
    for(i=(n/2)-1;i>=0;i--)
    {
        Max_Heapify(a,n,i);
    }

    //DELETING FROM MAXHEAP and PLACING AT END OF ARRAY
    for(i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        Max_Heapify(a,i,0);
    }

}


void Max_Heapify(int a[],int n, int i)
{
    int largest=i;
    int left_child=2*i +1;
    int right_child=2*i+2;

    if(left_child<n && a[left_child]>a[largest])
    {
        largest=left_child;
    }

    if(right_child<n && a[right_child]>a[largest])
    {
        largest=right_child;
    }

    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        Max_Heapify(a,n,largest);
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

