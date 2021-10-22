#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head,*last;
void createlist();
void displayfromfirst();
void displayfromlast();
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
    last=NULL;
    while(1)
    {
        printf("\n\nMain Menu.");
        printf("\n1.Create List.");
        printf("\n2.Display List from Start.");
        printf("\n3.Display List from End.");
        printf("\n4.Length of List.");
        printf("\n5.Insert at beginning.");
        printf("\n6.Insert at any position.");
        printf("\n7.Insert at end.");
        printf("\n8.Delete first node.");
        printf("\n9.Delete any node.");
        printf("\n10.Delete last node.");
        printf("\n11.Delete entire list.");
        printf("\n12.Reverse the List.");
        printf("\n13.Exit.");

        flag:
        printf("\n\nEnter your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            createlist();
            break;

            case 2:
            displayfromfirst();
            break;

            case 3:
            displayfromlast();
            break;

            case 4:
            length();
            printf("\nThe length of list is:\t%d",length());
            break;

            case 5:
            insertatbegin();
            break;

            case 6:
            insertatany();
            break;

            case 7:
            insertatend();
            break;

            case 8:
            deletefirst();
            break;

            case 9:
            deleteany();
            break;

            case 10:
            deletelast();
            break;

            case 11:
            deleteall();
            break;

            case 12:
            reverse();
            break;

            case 13:
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
    struct node *newnode;
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
        last=head;

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
                newnode->prev=last;
                newnode->next=NULL;
                last->next=newnode;
                last=newnode;
            }
        }
        last->next=head;
        head->prev=last;
    }
}


void displayfromfirst()
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

void displayfromlast()
{
    struct node *temp;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        temp=last;
        printf("\nThe elements in the list from end are:\t");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->prev;
        }
        while(temp!=last);

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
            newnode->prev=newnode;
            head=newnode;
            last=newnode;
        }
        else
            {
                newnode->next=head;
                newnode->prev=last;
                last->next=newnode;
                head->prev=newnode;
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
                newnode->prev=temp;
                temp->next->prev=newnode;
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
        newnode->prev=last;
        newnode->next=head;
        last->next=newnode;
        head->prev=newnode;
        last=newnode;
    }

}

void deletefirst()
{
    struct node *temp;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        temp=head;
        head=temp->next;
        head->prev=last;
        last->next=head;
        temp->next=NULL;
        temp->prev=NULL;
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
            q->next->prev=p;
            q->next=NULL;
            q->prev=NULL;
            free(q);
        }
    }
}

void deletelast()
{
    struct node *temp;
    if(head==NULL)
        printf("\n\nNo elements in the list.");
    else if(head->next==head)
    {
        temp=head;
        head=last=NULL;
        free(temp);
    }
    else
    {
        temp=last;
        last=last->prev;
        head->prev=last;
        last->next=head;
        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}

void deleteall()
{
    struct node *temp;
    if(head==NULL)
        printf("\n\nNo elements in list.");
    else
    {

        while(head->next!=head)
        {
            temp=head;
            head=head->next;
            head->prev=last;
            last->next=head;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
        }
        temp=head;
        head=last=NULL;
        free(temp);

    }
}


void reverse()
{
    struct node *current,*nextnode;
    if(head==NULL)
        printf("\nThere are no nodes in the List.");
    else
    {
        current=head;
        do
        {
            nextnode=current->next;
            current->next=current->prev;
            current->prev=nextnode;
            current=nextnode;
        }
        while(current!=head);
        head=last;
        last=current;
    }
}
