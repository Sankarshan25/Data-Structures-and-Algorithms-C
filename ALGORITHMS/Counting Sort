#include <stdio.h>
#include <stdlib.h>
int get_max(int a[],int n);
void Count_Sort(int a[],int n,int k);

int main()
{
    int a[10],i,n,k;
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

    k=get_max(a,n);


    //SORTING
    Count_Sort(a,n,k);

    printf("\nThe elements in the sorted array are:\t");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }

    return 0;
}

int get_max(int a[],int n)
{
    int i,max=0;
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }

    return max;
}

void Count_Sort(int a[],int n,int k)
{
    int count[20]={0},i=0; //size of count array should be k+1 but C does not allow initialization as count[k+1], hence statically initialize as count[20]
    int b[n];

    //Storing frequency of elements appearing in original array to the index of that number in count array
    for(i=0;i<n;i++)
    {
        count[a[i]]++;
    }

    //Updating count array
    for(i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }

    //inserting the elements from array 'a' to 'b' in sorted order
    for(i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
    }

    //copying elements of array 'b' to array 'a'
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}

