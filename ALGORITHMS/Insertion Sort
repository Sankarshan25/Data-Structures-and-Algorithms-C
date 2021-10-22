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
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
     //Displaying Sorted array
     printf("\nThe elements of the sorted array are: ");
     for(i=0;i<n;i++)
     {
         printf("\na[%d]=%d",i,a[i]);
     }
    return 0;
}
