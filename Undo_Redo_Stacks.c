#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct op
{
    int top;
    char arr[20];
};
struct op undo;
struct op redo;
void push(struct op *t,char a);
char pop(struct op *t);
void und();
void red();
void display();
void create(struct op *t);
int main()
{
    create(&undo);
    create(&redo);
    printf("\nUndo top=%d,Redo top=%d\n",undo.top,redo.top);
    printf("1.Enter a character\n2.Undo\n3.Redo\n4.Exit\n");
    int ch;
    char a;
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter a character: ");
                scanf("%s",&a);
                push(&undo,a);
                display();
                break;
            }
            case 2:
            {
                und();
                display();
                break;
            }
            case 3:
            {
                red();
                display();
                break;
            }
            case 4:
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
void create(struct op *t)
{
    t->top=-1;
}
void push(struct op *t,char a)
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
char pop(struct op *t)
{
    char a;
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
void und()
{
    char a=pop(&undo);
    push(&redo,a);
}
void red()
{
    char a=pop(&redo);
    push(&undo,a);
}
void display()
{
    int i;
    if(undo.top<=-1)
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        printf("Top= %d",undo.top);
        printf("\nElements are:");
        for(i=0;i<=undo.top;i++)
        {
            printf("%c ",undo.arr[i]);
        }

    }
}
