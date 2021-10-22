#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front,*rear;

void enqueue();
void dequeue();
void peek();
void display();

int main()
{
    front=rear=NULL;
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
    int value;
    struct node *newnode;
    newnode=(struct node *) malloc (sizeof(struct node));
    if(newnode==NULL)
        printf("\nMemory Allocation failed.");
    else
    {
        printf("\nEnter data of new node:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;

        if(front==NULL)
            front=rear=newnode;
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
        printf("\nUnderflow");
    else
    {
        temp=front;
        front=front->next;
        printf("\nThe data to be dequeued is %d.",temp->data);
        temp->next=NULL;
        free(temp);
    }
}

void peek()
{
    if(front==NULL)
        printf("\nNo elements in the queue.");
    else
    {
        printf("\nThe element at front of the queue is %d.",front->data);
    }
}

void display()
{
    struct node *temp;
    if(front==NULL)
        printf("\nNo elements in the queue.");
    else
    {
        temp=front;
        printf("\nThe elements in the queue are:\t");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
