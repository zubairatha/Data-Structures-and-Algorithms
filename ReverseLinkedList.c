#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head, *var;

static void reverse(struct node **head_ref)
{
    struct node *current = *head_ref;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void display(struct node *head)
{
    struct node *trav = head;

    while (trav != NULL)
    {
        printf("-> %d ", trav->data);
        trav = trav->next;
    }
}

void insert(int value)
{
    struct node *temp;
    temp = head;
    var = (struct node *)malloc(sizeof(struct node));
    var->data = value;
    if (head == NULL)
    {
        head = var;
        head->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        var->next = NULL;
        temp->next = var;
    }
}

int main()
{
    int i;
    while (i != 2)
    {
        printf("1.Add a node\n2.Reverse List.\nEnter your choice\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
        {
            int val = 0;
            printf("Enter the number: ");
            scanf("%d", &val);
            insert(val);
            break;
        }
        case 2:
            printf("Unreversed : ");
            display(head);
            printf("Reversed : ");
            reverse(&head);
            display(head);
            break;
        default:
            printf("Invalid option.");
        }
    }
}
