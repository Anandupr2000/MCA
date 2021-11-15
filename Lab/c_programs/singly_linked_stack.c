#include <stdio.h>
// creating node
int *top;
struct Node{
    int data;
    struct Node *next;
}*head,node;
void push(int element){
    struct Node *newnode = ;
    while(newnode!=NULL){
        node.next;
        newnode.data = element;
    }
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