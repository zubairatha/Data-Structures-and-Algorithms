#include<stdio.h>
#include<ctype.h>
# define MAXSIZE 20
int stack[MAXSIZE];
int top=-1;
int main()
{
    void push(int);
    int pop();
    void display();
    int will=1,i,num;
    while(will==1)
    {
        printf("Menu:\n 1.Add element to stack\n2.Delete element from the stack\n3.Display elements in the stack\n");
        scanf("%d",&will);
        switch(will)
        {
            case 1:
            printf("\nEnter the data:\n");
            scanf("%d",&num);
            push(num);
            break;
            case 2:
            printf("\nValue returned from pop function is %d",pop());
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid choice.");
        }
        printf("\nTo continue press 1. Else press any other key");
        scanf("%d",&will);
    }
}
void push(int y)
{
    if(top>MAXSIZE)
    {
        printf("STACK FULL");
        return;
    }
    else
    {
        top++;
        stack[top]=y;
    }
}
int pop()
{
    int a;
    if(top<=0)
    {
        printf("STACK EMPTY");
        return 0;
    }
    else
    {
        a=stack[top];
        top--;
    }
    return a;
}
void display()
{
    int i;
    if(top<=0)
    {
        printf("STACK EMPTY");
    }
    else
    {
        printf("\nElements are:");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
        printf("\nTotal number of elements: %d",(top+1));
    }
}
