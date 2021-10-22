#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
void createlist();
void displaylist();
int length();
void insertatbegin();
void insertatany();
void insertatend();
void deletefirst();
void deleteany();
void deletelast();
void deleteall();
void reverse();


int main()
{
    int choice, flag;
    head=NULL;
    while(1)
    {
        printf("\n\nMain Menu.");
        printf("\n1.Create List.");
        printf("\n2.Display List.");
        printf("\n3.Length of List.");
        printf("\n4.Insert at beginning.");
        printf("\n5.Insert at any position.");
        printf("\n6.Insert at end.");
        printf("\n7.Delete first node.");
        printf("\n8.Delete any node.");
        printf("\n9.Delete last node.");
        printf("\n10.Delete entire list.");
        printf("\n11.Reverse the list.");
        printf("\n12.Exit.");

        flag:
        printf("\n\nEnter your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            createlist();
            break;

            case 2:
            displaylist();
            break;

            case 3:
            length();
            printf("\nThe length of list is:\t%d",length());
            break;

            case 4:
            insertatbegin();
            break;

            case 5:
            insertatany();
            break;

            case 6:
            insertatend();
            break;

            case 7:
            deletefirst();
            break;

            case 8:
            deleteany();
            break;

            case 9:
            deletelast();
            break;

            case 10:
            deleteall();
            break;

            case 11:
            reverse();
            break;

            case 12:
            exit(0);
            break;

            default:
            printf("\n\nWrong Choice. Enter correct choice from the list.");
            goto flag;

        }
    }

}

void createlist()
{
    int n,i=1,value;
    struct node *temp,*newnode;
    printf("\nEnter the no. of nodes:\t");
    scanf("%d",&n);
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL)
        printf("\nMemory Allocation failed.");
    else
    {
        printf("\nEnter data of node 1:\t");
        scanf("%d",&value);
        head->data=value;
        head->next=NULL;
        temp=head;

        for(i=2;i<=n;i++)
        {
            newnode=(struct node *) malloc (sizeof(struct node));
            if(newnode==NULL)
                printf("\nMemory Allocation failed.");
            else
            {
                printf("\nEnter data of node %d:\t",i);
                scanf("%d",&value);
                newnode->data=value;
                newnode->next=NULL;
                temp->next=newnode;
                temp=newnode;
            }
        }
        temp->next=head;
    }
}


void displaylist()
{
    struct node *temp;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        temp=head;
        printf("\nThe elements in the list are:\t");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        while(temp!=head);

    }

}
int length()
{
    int count=0;
    struct node *temp;
    if(head==NULL)
        printf("\nThere are zero elements in the list.");
    else
    {
        temp=head;
        do
        {
            count++;
            temp=temp->next;
        }
        while(temp!=head);
    }
    return count;
}

void insertatbegin()
{
    int value;
    struct node *newnode,*temp;
    newnode=(struct node *) malloc (sizeof(struct node));
    if(newnode==NULL)
        printf("\n\nMemory allocation not possible.");
    else
    {
        printf("\n\nEnter data of the new node:\t");
        scanf("%d",&value);
        newnode->data=value;
        if(head==NULL)
        {
            newnode->next=newnode;
            head=newnode;
        }
        else
            {
                newnode->next=head;
                temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                head=newnode;
            }
    }
}

void insertatany()
{
    struct node *newnode,*temp;
    int value,len,loc,i;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("\n\nMemory allocation failed.");
    else if (head==NULL)
        insertatbegin();
    else
    {
        printf("\n\nEnter the location to insert the node:\t");
        scanf("%d",&loc);
        len=length();
        if(loc>(len+1))
            printf("\n\nInvalid Location.");
        else if(loc==1)
            insertatbegin();
        else
        {
            printf("\n\nEnter data of the newnode:\t");
            scanf("%d",&value);
            newnode->data=value;
            temp=head;
            for(i=1;i<loc-1;i++)
            {
                temp=temp->next;
            }
                newnode->next=temp->next;
                temp->next=newnode;
        }
    }
}

void insertatend()
{
    int value;
    struct node *newnode,*temp;
    newnode=(struct node *) malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("\n\nMemory Allocation failed.");
    else if(head==NULL)
        insertatbegin();
    else
    {
        printf("\n\nEnter data of the newnode:\t");
        scanf("%d",&value);
        newnode->data=value;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }

}

void deletefirst()
{
    struct node *temp,*p;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        temp=p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        head=temp->next;
        temp->next=NULL;
        p->next=head;
        free(temp);
    }
}

void deleteany()
{
    struct node *p, *q;
    int loc,i=1,len;
    if(head==NULL)
        printf("\n\nNo elements in the list.");
    else
    {
        len=length();
        printf("\n\nEnter the location of the node to be deleted:\t");
        scanf("%d",&loc);
        if(loc>len)
        printf("\n\nInvalid Location.");
        else
        {
            p=head;
            for(i=1;i<loc-1;i++)
            {
                p=p->next;
            }
            q=p->next;
            p->next=q->next;
            q->next=NULL;
            free(q);
        }
    }
}

void deletelast()
{
    struct node *p,*q;
    int len,i=1;
    if(head==NULL)
        printf("\n\nNo elements in the list.");
    else
    {
        len=length();
        p=head;
        for(i=1;i<len-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=head;
        q->next=NULL;
        free(q);
    }
}

void deleteall()
{
    struct node *temp;
    if(head==NULL)
        printf("\n\nNo elements in list.");
    else
    {
        temp=head;
        while(temp!=head);
        {
            head=temp->next;
            temp->next=NULL;
            free(temp);
            temp=head;
        }
        temp->next=NULL;
        free(temp);
        head=NULL;
        free(head);

    }
}

void reverse()
{
    struct  node *current, *nextnode, *prevnode;
    if(head==NULL)
        printf("\n\nNo elements in the list.");
    else
    {
        current=head;
        nextnode=head;
        prevnode=NULL;
        do
        {
            nextnode=current->next;
            current->next=prevnode;
            prevnode=current;
            current=nextnode;
        }
        while(current!=head);
        current->next=prevnode;
        head=prevnode;
    }
}


