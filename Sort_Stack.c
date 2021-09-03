#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int arr[20];
};
struct stack og;
void push(struct stack *t,int a);
int pop(struct stack *t);
struct stack sort(struct stack *t);
void display();
void create(struct stack *t);
int main()
{
    create(&og);
    printf("1. New element\n2.Sort\n3.Exit\n");
    int ch;
    int a;
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter a character: ");
                scanf("%d",&a);
                push(&og,a);
                display();
                break;
            }
            case 2:
            {
                og=sort(&og);
                display();
                break;
            }
            case 3:
            {
                exit(0);
                break;
            }
            default:
            printf("Invalid choice.");
        }
    }
    return 0;
}
void create(struct stack *t)
{
    t->top=-1;
}
void push(struct stack *t,int a)
{
    if(t->top>20)
    {
        printf("STACK FULL");
        return;
    }
    else
    {
        t->top=t->top+1;
        t->arr[t->top]=a;
    }
}
int pop(struct stack *t)
{
    int a;
    if(t->top<=-1)
    {
        printf("STACK EMPTY");
        return 0;
    }
    else
    {
        a=t->arr[t->top];
        t->top=t->top-1;
    }
    return a;
}
struct stack sort(struct stack *org)
{
    struct stack temp;
    create(&temp);
    while(org->top!=-1)
    {
        int tmp;
        tmp= pop(org);
        while(temp.top!=-1 && temp.arr[temp.top]>tmp)
        {
            push(org,pop(&temp));
        }
        push(&temp,tmp);
    }
    return temp;
}
void display()
{
    int i;
    if(og.top<=-1)
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        printf("Top= %d",og.top);
        printf("\nElements are:");
        for(i=0;i<=og.top;i++)
        {
            printf("%d ",og.arr[i]);
        }

    }
}
