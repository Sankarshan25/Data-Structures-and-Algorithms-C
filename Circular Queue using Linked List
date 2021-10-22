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
        printf("\nMemory allocation failed.");
    else
    {
        printf("\nEnter data to be inserted in queue:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        if(front==NULL)
        {
            front=rear=newnode;
            rear->next=front;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            rear->next=front;
        }
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
        printf("\nNo elements in queue.Underflow.");
    else if(front==rear)
    {
        temp=front;
        front=rear=NULL;
        printf("\nThe dequeued element is %d.",temp->data);
        temp->next=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        front=front->next;
        rear->next=front;
        printf("\nThe dequeued element is %d.",temp->data);
        temp->next=NULL;
        free(temp);
    }
}

void peek()
{
    if(front==NULL)
        printf("\nQueue is empty.Underflow.");
    else
        printf("\nThe element at front of queue is %d.",front->data);
}

void display()
{
    struct node *temp;
    if(front==NULL)
        printf("Queue is empty.Underflow.");
    else
    {
        temp=front;
        printf("\nThe queue elements are:\t");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        while(temp!=front);
    }
}
