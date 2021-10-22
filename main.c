#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head, *last;
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
        printf("\n2.Display List from First.");
        printf("\n3.Display List from Last.");
        printf("\n4.Length of List.");
        printf("\n5.Insert at beginning.");
        printf("\n6.Insert at any position.");
        printf("\n7.Insert at end.");
        printf("\n8.Delete first node.");
        printf("\n9.Delete any node.");
        printf("\n10.Delete last node.");
        printf("\n11.Delete entire list.");
        printf("\n12.Reverse the list.");
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

    printf("\nEnter the number of nodes:\t");
    scanf("%d",&n);
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL)
        printf("\nMemory Allocation not possible.");
    else
    {
        printf("\nEnter data of node 1:\t");
        scanf("%d",&value);
        head->data=value;
        head->next=NULL;
        head->prev=NULL;
        last=head;

    for(i=2;i<=n;i++)
     {
        newnode=(struct node *) malloc (sizeof(struct node));
        if(newnode==NULL)
            printf("\nMemory Allocation not possible.");
        else
        {
            printf("\nEnter data of node %d:\t",i);
            scanf("%d",&value);
            newnode->data=value;
            newnode->next=NULL;
            newnode->prev=last;
            last->next=newnode;
            last=newnode;
        }

     }

   }
}

void displayfromfirst()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        printf("\nThe elements in the list are:\t");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void displayfromlast()
{
    struct node *temp;
    temp=last;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        printf("\nThe elements in the list are:\t");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->prev;
        }
    }
}

int length()
{
    struct node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;
}

void insertatbegin()
{
    int value;
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("\nMemory Allocation failed.");
    else
    {
        printf("\nEnter data of new node:\t");
        scanf("%d",&value);
        newnode->data=value;
        if(head==NULL)
        {
            newnode->prev=NULL;
            newnode->next=NULL;
            last=newnode;
        }
        else
        {
            newnode->next=head;
            head->prev=newnode;
        }
        head=newnode;
    }
}

void insertatany()
{
    int loc,len,value,i=1;
    struct node *newnode,*temp;
    len=length();
    newnode=(struct node *) malloc (sizeof(struct node));
    if(newnode==NULL)
        printf("\nMemory Allocation not possible.");
    else
    {
        if(head==NULL)
        {
            printf("\nEnter data of new node:\t");
            scanf("%d",&value);
            newnode->data=value;
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
            last=newnode;
        }
        else
        {
                printf("\nEnter the location to insert new node:\t");
                scanf("%d",&loc);
                if(loc>(len+1))
                    printf("\nInvalid Location.");
                else if(loc==1)
                    insertatbegin();
                else
                {
                    printf("\nEnter data of new node:\t");
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

}

void insertatend()
{
    int value;
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("\nMemory Allocation not possible.");
    else
    {
        printf("\nEnter data of new node:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        if(head==NULL)
        {
            newnode->prev=NULL;
            head=newnode;
        }
        else
        {
            newnode->prev=last;
            last->next=newnode;
        }
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
        temp->next=NULL;
        head->prev=NULL;
        free(temp);
    }
}

void deleteany()
{
    struct node *p,*q;
    int loc,i=1,len;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        printf("\nEnter the location of the node to be deleted:\t");
        scanf("%d",&loc);
        len=length();
        if(loc>len)
            printf("\nInvalid Location.");
        else
        {
            p=head;
            q=head;
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
        printf("\nNo elements in the list.");
    else
    {
        temp=last;
        last=last->prev;
        last->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}

void deleteall()
{
    struct node *temp;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        temp=head;
        while(head!=NULL)
        {
            head=head->next;
            temp->next=NULL;
            temp->prev=NULL;
            free(temp);
        }
        free(head);
    }
}

void reverse()
{
    struct node*temp,*nextnode;
    if(head==NULL)
        printf("\nNo elements in the list.");
    else
    {
        temp=head;
        while(nextnode!=NULL)
        {

            nextnode=temp->next;
            temp->next=temp->prev;
            temp->prev=nextnode;
            temp=nextnode;
        }
        temp=head;
        head=last;
        last=temp;

    }
}

