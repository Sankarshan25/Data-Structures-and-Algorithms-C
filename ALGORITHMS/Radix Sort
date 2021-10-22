#include <stdio.h>
#include <stdlib.h>
void Radix_Sort(int a[],int n);
void Count_Sort(int a[],int n,int pos);
int get_max(int a[],int n);

int main()
{
    int a[20],i,n;
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
    Radix_Sort(a,n);

    printf("\nThe array elements after sorting are:\t");
    for(i=0;i<n;i++)
    {
        printf("\na[%d]=\t%d",i,a[i]);
    }
    return 0;
}

void Radix_Sort(int a[],int n)
{
    int max,pos;
    max=get_max(a,n);

    //Calling count sort for each digit
    for(pos=1;max/pos>0;pos*=10)
    {
        Count_Sort(a,n,pos);
    }
}

void Count_Sort(int a[],int n,int pos)
{
    int count[10]={0},b[n],i;

    //Storing frequency of the digit corresponding to pos for each number in count array
    for(i=0;i<n;i++)
    {
        count[((a[i])/pos)%10]++;
    }

    //Updating count array
    for(i=1;i<=10;i++)
    {
        count[i]=count[i]+count[i-1];
    }

    //Sorting the array according to the position currently being checked
    for(i=n-1;i>=0;i--)
    {
        b[--count[((a[i]/pos)%10)]]=a[i];
    }


   for(i=0;i<n;i++)
   {
       a[i]=b[i];
   }

}



int get_max(int a[],int n)
{
    int i;
    int max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }

    return max;
}


