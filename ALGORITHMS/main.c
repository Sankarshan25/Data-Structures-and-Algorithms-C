#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i,j,n,temp,min;
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

    //Sorting

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;

    }

    //Displaying Sorted Array
    printf("\nThe elements of the sorted array are:");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }
    return 0;
}
