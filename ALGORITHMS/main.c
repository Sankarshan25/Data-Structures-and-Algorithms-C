#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root;
struct node *create();
void inorder();
void preorder();
void postorder();


int main()
{
    int choice,flag;
    root=NULL;
    while(1)
    {
        printf("\n\nMain Menu");
        printf("\n\n1.Create Binary Tree.");
        printf("\n\n2.Display Inorder Traversal of Binary Tree");
        printf("\n\n3.Display Preorder Traversal of Binary Tree");
        printf("\n\n4.Display Postorder Traversal of Binary Tree");
        printf("\n\n5.Exit.");

        flag:
        printf("\n\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root=create();
            break;

        case 2:
            if(root==NULL)
            {
               printf("\nNo nodes in the tree");
               break;
            }
            inorder(root);
            break;

        case 3:
             if(root==NULL)
            {
               printf("\nNo nodes in the tree");
               break;
            }
            preorder(root);
            break;

        case 4:
             if(root==NULL)
            {
               printf("\nNo nodes in the tree");
               break;
            }
            postorder(root);
            break;

        case 5:
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


struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));

    printf("\nEnter data(for no node,enter -1):\t");
    scanf("%d",&x);

    if(x==-1)
    {
        return 0;
    }

    newnode->data=x;
    printf("\nEnter left child of %d",x);
    newnode->left=create();

    printf("\nEnter right child of %d",x);
    newnode->right=create();
    return newnode;
}


void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }

    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);


}

void preorder(struct node *root)
{
    if(root==0)
    {
        return;
    }

    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);

}


void postorder(struct node *root)
{
    if(root==0)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
}
