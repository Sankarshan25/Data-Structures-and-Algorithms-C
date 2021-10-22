#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a[10],i,n,x,found=0;
    printf("Enter size of array:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter a[%d] element of the array:",i);
        scanf("%d",&a[i]);
    }
    printf("\nThe elements of the array are:");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }
    printf("\nEnter element to search for:");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
                found=1;
                printf("\nThe element %d exists at location %d.",a[i],i);


        }

    }

    if(found==0)
        printf("\nThe element does not exist in the array.");

    return 0;
}
