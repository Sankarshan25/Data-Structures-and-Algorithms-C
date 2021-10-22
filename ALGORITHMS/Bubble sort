#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i,n,j,temp=0;
    printf("Enter size of array:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter a[%d] element of the array:\t",i);
        scanf("%d",&a[i]);
    }
    printf("\nThe elements of the array are:");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }
    //Sorting array elements
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
            }
        }
    }
    printf("\nThe sorted array is:\t");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }


    return 0;
}
