#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],n,i,low=0,high=0,mid=0,key,found=0;
    printf("Enter the size of the array:\t");
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

    //Searching
    printf("\nEnter the element to be searched:\t");
    scanf("%d",&key);
     low=0;
     high=n-1;

     while(low<=high)
     {
         mid=(low+high)/2;

         if(key<a[mid])
         {
             high=mid-1;
         }

         else if(key>a[mid])
         {
             low=mid+1;
         }

         else if(key==a[mid])
         {
             found=1;
             printf("\nThe searched element %d exists at location %d.",key,mid);
             break;
         }
     }

     if(found==0)
        printf("\nThe searched element does not exist in the array.\n\n");


    return 0;
}
