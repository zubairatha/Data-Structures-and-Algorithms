#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h> 
struct node{  
    int data;  
    struct node *next;  
};      
struct node *head, *tail = NULL;  
void addNode(int);
void sortList();
void display();
int main()
{
    int ch;
    int item=0;
    while(1)
    {
        printf("\n1.Insert a number\n2.Sort\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter a number: ");
            scanf("%d",&item);
            addNode(item);
            break;
            case 2:
            sortList();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nInvalid choice.");
        }
    }
}
void addNode(int data) 
{  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  

    if(head == NULL) {  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        tail->next = newNode;  
        tail = newNode;  
    }  
}  
    void sortList() {  
        struct node *current = head, *index = NULL;  
        int temp;  
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                index = current->next;  
                  
                while(index != NULL) {  
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  
void display() {  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {   
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
