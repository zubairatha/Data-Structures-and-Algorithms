#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*temp=NULL,*t1;
 
struct btnode *root = NULL;
int flag;

struct btnode* newnode(int value)
{
    struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->value = value;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

void printPostorder(struct btnode* node)
{
    if (node == NULL)
        return;
    printPostorder(node->l);
    printPostorder(node->r);
    printf("%d ", node->value);
}

void printInorder(struct btnode* node)
{
    if (node == NULL)
        return;
    printInorder(node->l);
    printf("%d ", node->value);
    printInorder(node->r);
}

void printPreorder(struct btnode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->value);
    printPreorder(node->l);
    printPreorder(node->r);
}

void in_order_search(struct btnode *p, int val)
{
    if (!p)
    {
        return;
    }
    in_order_search(p->l, val);
    if(p->value == val)
    {
        printf("\nElement present in the binary tree.\n");
        flag = 1;
    }
    in_order_search(p->r, val);
}
void delsearch(struct btnode *p, int val,int val2)
{
    if (!p)
    {
        return;
    }
    delsearch(p->l, val,val2);
    if(p->value == val)
    {
        p->value=val2;
        return;
    }
    delsearch(p->r, val,val2);
}
int rightMin(struct btnode *temp)
{
    int tmp;
    t1=temp;
    while(temp->r!=NULL)
    {
        t1=temp;
        temp=temp->r;
    }
    tmp=temp->value;
    t1->r=NULL;
    temp=NULL;
    free(temp);
    return tmp;
}
void del(struct btnode *p,int val)
{
    int tmp;
    tmp=rightMin(p);
    delsearch(p,val,tmp);
}
void main()
{ 
    /* Inserting elements in the binary tree */
    int search_val,del_val;
    root = newnode(50);
    root->l = newnode(20);
    root->r = newnode(30);
    root->l->l = newnode(70);
    root->l->r = newnode(80);
    root->l->l->l = newnode(10);
    root->l->l->r = newnode(40);
    root->l->r->r = newnode(60);
    root->r->l = newnode(100);
    root->r->r = newnode(45);
    int ch;
    printf("OPERATIONS\n1.Inorder Traversal\n2.Preorder Traversal\n3.Postorder Traversal\n4.Search\n5.Delete an element\n6.Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printInorder(root);
            break;
            case 2:
            printPreorder(root);
            break;
            case 3:
            printPostorder(root);
            break;
            case 4:
            flag=0;
            printf("\nEnter the value to be searched:");
            scanf("%d", &search_val);
            in_order_search(root, search_val);
            if (flag == 0)
            {
                printf("Element not present in the binary tree\n");
            }
            break;
            case 5:
            printf("\nEnter the value to be deleted: ");
            scanf("%d", &del_val);
            del(root,del_val);
            break;
            case 6:
            exit(0);
            default:
            printf("\nWrong choice. Try again.\n");
            
        }
    }

}
 
