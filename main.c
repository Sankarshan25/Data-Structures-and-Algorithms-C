#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX],top=-1;
void push();
void pop();
void peek();
void display();

int main()
{
    int choice,flag;
    while(1)
    {
        printf("\nMain Menu.");
        printf("\n1.Push.");
        printf("\n2.Pop.");
        printf("\n3.Peek.");
        printf("\n4.Display.");
        printf("\n5.Exit.");

        flag:
        printf("\nEnter your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("\nPlease enter correct choice.");
            goto flag;
        }
    }

    return 0;
}

void push()
{
    int data;
    if(top==MAX-1)
        printf("\nOverflow.");
    else
    {
        printf("\nEnter the data to be pushed into stack:\t");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
    }
}

void pop()
{
    int data;
    if(top==-1)
        printf("\nUnderflow.");
    else
    {
        data=stack[top];
        top=top-1;
        printf("\nThe popped data is %d.",data);
    }
}

void peek()
{
    if(top==-1)
        printf("\nUnderflow.");
    else
    {
        printf("\nThe top element is %d.",stack[top]);
    }
}

void display()
{
    int i;
    if(top==-1)
        printf("\nUnderflow");
    else
    {
        printf("\nStack elements are:\t");
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }

}

