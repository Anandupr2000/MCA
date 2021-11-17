#include <stdio.h>
#include <stdlib.h>
// creating node
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL; //is top pointer in stack

void display()
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp = head;
    if (temp == NULL)
    {
        printf(" empty.");
    }
    else
    {
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}
void peek(int count1){

}
void push(int element)
{
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = element; // since newnode is pointer we use ->
    newnode->next = head;
    head = newnode;
    printf("\nAfter pushing, Stack is ");
    display();
}
void pop()
{
    if (head == NULL)
    {
        printf("Underflow occured");
    }
    else
    {
        struct Node *temp;
        temp = head;
        head = temp->next;
        printf("\nPopped element is %d",temp->data);
        free(temp);
    }
    printf("\nAfter poping, Stack is ");
    display();
}
void search(int element)
{
    int count = 0;
    struct Node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("\nStack is empty.");
    }
    while (temp != NULL)
    {
        count++;
        if (temp->data == element)
        {
            printf("\n%d found position %d.", element, count);
            break;
        }
        else
        {
            printf("\n%d not found.");
            break;
        }
        temp = temp->next;
    }
    free(temp);
}

void main()
{
    int menuInput = 1, element;
    // printf("Enter data : ");
    // scanf("%d",&maxlength);

    while (menuInput != 0)
    {
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element ");
        printf("\n2 - Delete element ");
        printf("\n3 - Search element ");
        printf("\n4 - Display queue ");
        printf("\n0 - Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &menuInput);
        switch (menuInput)
        {
        case 0:
            break;
        case 1:
        {
            printf("Enter element : ");
            scanf("%d", &element);
            push(element);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            printf("Enter element for searching : ");
            scanf("%d", &element);
            search(element);
            break;
        }
        case 4:
        {
            printf("\nStack elements are : ");
            display();
            break;
        }
        }
    }
}