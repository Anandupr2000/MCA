#include <stdio.h>
#include <stdbool.h>
// creating node
int *top;
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}node;
struct Node *head = NULL;
void push(int element){
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = head;//pointing newnode's next pointer to existing node
    head->prev = newnode;//pointing existing node's prev pointer to newnode
    head = newnode;//pointing back to newnode
}
void main() {
    int menuInput=1,element;
    // printf("Enter data : ");
    // scanf("%d",&maxlength);

    while(menuInput!=0){
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element ");
        printf("\n2 - Delete element ");
        printf("\n3 - Search element ");
        printf("\n4 - Display queue ");
        printf("\n0 - Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &menuInput);
        switch (menuInput){
            case 0: break;
            case 1: {
                    printf("Enter element : ");
                    scanf("%d",&element);
                    push(element);
                    break;
                    }
            case 2: {
                        pop();
                        break;
                    }        
            case 3: {
                        printf("Enter element : ");
                        scanf("%d",&element);
                        search(element);
                    }        
            case 4: {
                        printf("\nQueue elements are : ");
                        display();
                        break;
                    }        
        }
    }
}