#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// creating node
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL; //is top pointer in stack

void display()
{
    struct Node *temp;
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
void peek(int count1)
{
}

void change(int position1,int newValue)
{
    int position=0;
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        position++;
        if(position == position1){
            temp->data = newValue;
        }
        temp = temp->next;
    }
// }
// void push(int element)
// {
//     struct Node *newnode = malloc(sizeof(struct Node));
//     newnode->data = element; // since newnode is pointer we use ->
//     newnode->next = head;
//     head = newnode;
//     printf("\nAfter pushing, Stack : ");
//     display();
// }
void pop()
{
    if (head == NULL)
    {
        printf("Underflow occured");
        return;
    }
    else
    {
        struct Node *temp;
        temp = head;
        head = temp->next;
        printf("\nPopped element is %d", temp->data);
        free(temp);
    }
    printf("\nAfter poping, Stack : ");
    display();
}
void search(int element)
{
    bool found = false;
    int count = 0;
    struct Node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("\nStack is empty.");
        return;
    }
    while (temp != NULL)
    {
        count++;
        if (temp->data == element)
        {
            printf("\n%d found position %d.", element, count);
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found)
        printf("\n%d not found.", element);
}

void main()
{
    int menuInput = 1, element;
    // printf("Enter data : ");
    // scanf("%d",&maxlength);

    while (menuInput != 0)
    {
        printf("\n\n*********** Menu ***********");
        printf("\n1 - Enter element ");
        printf("\n2 - Delete element ");
        printf("\n3 - Search element ");
        printf("\n4 - Display queue ");
        // printf("\n5 - Change specific element value");
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
                printf("\nStack : ");
                display();
                break;
            }
        // case 5:
        //     {
        //         int newVal,pos;
        //         printf("\nEnter position : ");
        //         scanf("%d",&newVal);
        //         printf("\nEnter value : ");
        //         scanf("%d",&pos);
        //         change(pos,newVal);
        //         break;
        //     }
        default: printf("\n****** Unknown input ********\nPlease enter a valid input\n");
        }
    }
}