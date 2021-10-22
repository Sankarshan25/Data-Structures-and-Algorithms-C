#include <stdio.h>
#include <stdlib.h>
void ShellSort(int a[],int n);
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

    ShellSort(a,n);

    printf("\nThe elements after sorting are:\t");

    for(i=0;i<n;i++)
    {
        printf("\na[%d]=%d",i,a[i]);
    }

    return 0;
}

void ShellSort(int a[],int n)
{
    int i,j,gap,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0;i-gap)
            {
                if(a[i+gap]>a[i])
                {
                    break;
                }
                else
                {
                    swap(&a[i+gap],&a[i]);

                }
            }
        }
    }

}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

