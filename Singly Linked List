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
void search();
void reverse();

int main()
{
    int choice,flag;
    head=NULL;
    while(1)
    {
        printf("\n\nMain Menu");
        printf("\n\n1.Create List.");
        printf("\n\n2.Display List.");
        printf("\n\n3.Length of List.");
        printf("\n\n4.Insert at beginning.");
        printf("\n\n5.Insert at any position.");
        printf("\n\n6.Insert at end.");
        printf("\n\n7.Delete first node.");
        printf("\n\n8.Delete any node.");
        printf("\n\n9.Delete last node.");
        printf("\n\n10.Delete entire list.");
        printf("\n\n11.Search for an element.");
        printf("\n\n12.Reverse the list.");
        printf("\n\n13.Exit.");
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
            printf("\n\nThere are %d nodes in the list.",length());
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
            search();
            break;
        case 12:
            reverse();
            break;
        case 13:
            exit(0);
            break;
        default:
            {
                printf("\n\nWrong Choice.Please enter correct choice from Main Menu.");
                goto flag;
            }
        }
    }
    return 0;
}

void createlist()
{
    int value,i=1,n;
    struct node *temp,*newnode;
    printf("\n\nEnter the number of nodes:\t");
    scanf("%d",&n);
    head=(struct node *) malloc(sizeof(struct node));
    if(head==NULL)
        printf("\n\nMemory allocation not possible.");
    else
    {
        printf("\n\nEnter the data of node 1:\t");
        scanf("%d",&value);
        head->data= value;
        head->next= NULL;
        temp=head;

        for(i=2;i<=n;i++)
        {
            newnode=(struct node *) malloc (sizeof(struct node));
            printf("\n\nEnter the data of node %d:\t",i);
            scanf("%d",&value);
            newnode->data=value;
            newnode->next=NULL;
            temp->next= newnode;
            temp=newnode;
        }
    }
}

void displaylist()
{
    struct node *temp;
    if(head==NULL)
        printf("\n\nNo elements in the list.");
    else
        {
            temp=head;
            printf("\n\nThe elements in the list are:\t");
            while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
        }
}

int length()
{
    int count=0;
    struct node *temp;
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
    newnode=(struct node *) malloc (sizeof(struct node));
    if(newnode==NULL)
        printf("\n\nMemory allocation not possible.");
    else
    {
        printf("\n\nEnter data of the new node:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=head;
        head=newnode;
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
        {
            printf("\n\nEnter data of the newnode:\t");
            scanf("%d",&value);
            newnode->data=value;
            newnode->next=NULL;
            head=newnode;
        }
    else
    {
        printf("\n\nEnter the location to insert the node:\t");
        scanf("%d",&loc);
        len=length();
        if(loc>(len+1))
        printf("\n\nInvalid Location.");
        else
        {
            printf("\n\nEnter data of the newnode:\t");
            scanf("%d",&value);
            newnode->data=value;
            newnode->next=NULL;
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
    else if (head==NULL)
    {
        head=newnode;
        printf("\n\nEnter data of the newnode:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
    }
    else
    {
        printf("\n\nEnter data of the newnode:\t");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=NULL;

        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
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
        p->next=NULL;
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
        while(head!=NULL)
        {
            temp=head;
            head=temp->next;
            temp->next=NULL;
            free(temp);
        }
        free(head);
    }
}


void search()
{
    int count=0,value,i=1,a[10],j=0;   //i=linked list index locations, j=array index
    struct node *temp;
    if(head==NULL)
        printf("\nThere are no elements in the list.");
    else
    {
        temp=head;
        printf("\nEnter the data to be located:\t");
        scanf("%d",&value);
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                count++;
                a[j]=i;
                j++;
            }
            i++;
            temp=temp->next;
        }
        if(count==0)
            printf("\nThe searched element %d is not present in the list.",value);
        else
        {
            printf("\nThe searched value %d is present %d times in the list.",value,count);
            printf("\n\nThe elements are present at locations:\t");
            for(j=0;j<count;j++)
            {
                printf("%d\t",a[j]);
            }
        }
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
        while(current!=NULL)
        {
            nextnode=nextnode->next;
            current->next=prevnode;
            prevnode=current;
            current=nextnode;
        }

        head=prevnode;
    }
}

