#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void peek();
void display();

int main()
{
    int choice,flag;
    while(1)
    {
        printf("\nMain Menu.");
        printf("\n1.Enqueue.");
        printf("\n2.Dequeue.");
        printf("\n3.Peek.");
        printf("\n4.Display.");
        printf("\n5.Exit.");

        flag:
        printf("\nEnter your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
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

void enqueue()
{
    int data;
    if(rear==MAX-1)
        printf("\nOverflow.");
    else
    {
        printf("\nEnter data to be inserted in queue:\t");
        scanf("%d",&data);
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            queue[rear]=data;
        }
        else
        {
            rear=rear+1;
            queue[rear]=data;
        }
    }
}

void dequeue()
{
    int data;
    if(front==-1 || front>rear)
        printf("\nUnderflow.");
    else
    {
        data=queue[front];
        front=front+1;
        printf("\nThe dequeued element is %d",data);
    }
}

void peek()
{
    if(front==-1 || front>rear)
        printf("\nUnderflow.");
    else
        printf("\nThe element at front of queue is %d.",queue[front]);
}

void display()
{
    int i;
    if(front==-1 || front>rear)
        printf("\nUnderflow.");
    else
    {
        printf("\nThe queue elements are:\t");
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
}
