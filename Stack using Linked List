#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top;
void push();
void pop();
void peek();
void display();

int main()
{
    int choice,flag;
    top=NULL;
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
    int value;
    struct node *newnode;
    newnode=(struct node *) malloc (sizeof(struct node));
    if(newnode==NULL)
        printf("\nMemory allocation failed.");
    else
    {
        printf("\nEnter data of the node:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    struct node *temp;
    if(top==NULL)
        printf("\nUnderflow.");
    else
    {
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
}

void peek()
{
    if(top==NULL)
        printf("\nUnderflow.");
    else
    {
        printf("\nThe top element is %d.",top->data);
    }
}

void display()
{
    struct node *temp;
    if(top==NULL)
        printf("\nUnderflow.");
    else
    {
        printf("\nStack elements are:\t");
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
