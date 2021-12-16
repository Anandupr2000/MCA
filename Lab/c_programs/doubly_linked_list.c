#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/////TODO: Traversal - success
/////TODO: insert at the beginning is working fine - ok
/////TODO: insert at the last - success
/////TODO: insert in between the list - success
/////TODO: delete at the beginning - success
/////TODO: delete at the last - success
/////TODO: delete in between the list - success 
////////////////////////////////

int maxlength = 0;

// creating node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
//displaying elements
void display(int orientation)
{
    struct Node *temp = head;
    struct Node *lastNode = NULL;
    while (temp != NULL)
    {
        lastNode = temp;
        if(orientation == 1) printf(" %d ", temp->data);
        temp = temp->next;
    }
    if(orientation == 0){
        temp = lastNode;
        while(temp != NULL){
            printf(" %d ", temp->data);
            temp = temp->prev;
        }
    }
}

//displaying element at specified position
void displayAt(int pos)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == pos)
        {
            struct Node *previous = temp->prev;
            struct Node *nxt = temp->next;
            printf(" Value in current position = %d ", temp->data);
            printf(" Value in previous position = %d ", previous->data);
            printf(" Value in next position = %d ", nxt->data);
            return;
        }
        temp = temp->next;
    }
}

void insert(int element, int pos)
{
    int count = 1;
    bool inserted = false;
    struct Node *temp = head; // using head address for start
    struct Node *newnode = malloc(sizeof(struct Node));
    newnode->data = element;

    struct Node *previous = NULL;
    struct Node *nxt = NULL;

    //if insertion done at start of list
    if (pos == 1)
    {
        //here nxt is considered to be first node before which newnode is inserted
        if (head == NULL)
        {        
            printf("\nCreating new doubly linked list");
            head = newnode;
        }
        else
        {
            nxt = head;
            newnode->next = nxt; //pointing newnode's next pointer to existing node
            nxt->prev = newnode; // making first node point to newnode
        }
        newnode->prev = NULL; //pointing existing node's prev pointer to null
        head = newnode;       //pointing head to newnode
        inserted = true; 
    }
    // printf("\nSearching....");
    else
    {
        printf("\n\nSearching.");
        while (temp != NULL)
        {
            // if insertion done in position other than first and last position
            if (count == pos)
            {
                printf("\n%d position found", count);

                //if insertion done at positon other than begining and end of list

                previous = temp->prev;    // previous node
                previous->next = newnode; // next node
                newnode->prev = previous; // assigning previous node's address to previous of newnode
                newnode->next = temp;     // assigning current node's address to next of newnode
                temp->prev = newnode;     // assigning new node's address to previous of current node
                inserted = true;
                printf("\nInserting at %d position of list successfull", count);
                break;
            }
            else if (pos == count +1 && pos == maxlength + 1)
                {
                    //if insertion done at end of list, make next pointer NULL

                    temp->next = newnode; // assigning address of newnode to next ptr of last node
                    newnode->prev = temp; // assigning address of last node to newnode's prev ptr
                    newnode->next = NULL; // making next pointer of new node point to null
                    inserted = true;
                    // printf("\nInserting at end of list successfull");
                    break;
                }

            else
            {
                printf(".");
            }
            temp = temp->next;
            count++;
        }
    }
    if(inserted){
            maxlength++; // After insertion increase the size of the list
            printf("\nAfter inserting, Doubly linked list : ");
            display(1);
            printf("\n");
        }
        else{
            printf("\nInsertion failed !!!!!!");
        }
    printf("\nMaxlength = %d", maxlength);
}
//Insert at middle
void insertAtMiddle(int element){
   int middle;
   if(maxlength%2)
       middle = maxlength/2;
   else
       middle = (maxlength/2)+1;
   insert(element, middle);
}
//searching element
void search(int element)
{
    bool found = false;
    int count = 1;
    struct Node *searchedNode = head;
    printf("\nSearching.");
    while (searchedNode != NULL)
    {
        if (searchedNode->data == element)
        {
            found = true;
            printf("\n%d found at position %d.", searchedNode->data, count);
        }
        else{
            printf(".");
        }
        searchedNode = searchedNode->next;
        count++;
    }

    if (!found)
    {
        printf("\n%d not found.", element);
    }
}
//deleting
void delete (int pos)
{
    if (head == NULL)
    {
        printf("\nError- List empty, deletion not possible");
    }
    else
    {

        int count = 1;
        bool deleted = false;
        // printf("\nPerforming delete operation...\n");
        // printf("\n%d is maxlength", maxlength);
        struct Node *temp = head;
        printf("\n%d is given position", pos);
        struct Node *delNode = NULL;
        // if(temp->prev!=NULL){
        printf("\nSearching....\n");

        // case 1
        if(pos>maxlength || pos<1){
            printf("\nDeletion not possible !!!!!");
            return;
        }
        //case 2 if node is at starting
        else if (pos == 1)
        {
            if (temp->next == NULL) // if list has only one element
            {
                free(temp);
                head = NULL;
            }
            else // for more than one element
            {
                head = temp->next; // assign the address of next node to head
                printf("\nPopped element is %d", temp->data);
                delNode = temp;// assign the address of current node to delNode
                temp = temp->next;//replacing current node with next node
                temp->prev = NULL;
                free(delNode);
            }
            deleted = true;
            printf("\n1st node deleted");
        }
        else
        {
            while (temp != NULL)
            {
                if (count == pos)
                {
                    printf("\n%d position found", count);

                    //case 3 if node is in last
                    if (pos == maxlength)
                    {
                        // printf("%d at head", temp->data);
                        delNode = temp;
                        temp = temp->prev;
                        temp->next = NULL;
                    }

                    //case 4 if node is not in start
                    else
                    {
                        struct Node *prev = temp->prev;
                        struct Node *nxt = temp->next;
                        delNode = temp;
                        prev->next = nxt;
                        nxt->prev = prev;
                    }
                    free(delNode);
                    deleted = true;
                    break;
                }
                else
                {
                    printf(".");
                }
                temp = temp->next;
                count++;
            }
        }
        if(deleted && head!=NULL){
            printf("\nAfter poping, Doubly linked list : ");
            display(1);
            maxlength--;
        }
        else{
            printf("\nDeletion failed !!!!!!!");
        }
    }
}

void main()
{
    int menuInput = 1, element;

    while (menuInput != 0)
    {
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element at first position");
        printf("\n2 - Enter element at specified position ");
        printf("\n3 - Enter element at last position");
        printf("\n4 - Delete element at first position");
        printf("\n5 - Delete element at specified position");
        printf("\n6 - Delete element at last position");
        printf("\n7 - Search element ");
        printf("\n8 - Display list in forward direction");
        printf("\n9 - Display list in reverse direction");
        printf("\n0 - Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &menuInput);
        switch (menuInput)
        {
        case 0:
            break;
        case 1:
        {
            printf("\nEnter element : ");
            scanf("%d", &element);
            insert(element, 1);
            break;
        }
        case 2:
        {
            int pos;
            printf("\nEnter position : ");
            scanf("%d", &pos);
            printf("\nEnter element : ");
            scanf("%d", &element);
            insert(element, pos);
            break;
        }
        case 3:
        {
            printf("\nEnter element : ");
            scanf("%d", &element);
            insert(element, maxlength+1);
            break;
        }
        case 4:
        {
            delete (1);
            break;
        }
        case 5:
        {
            int pos;
            printf("\nEnter positon of element for deletion : ");
            scanf("%d", &pos);
            delete (pos);
            break;
        }
        case 6:
        {
            delete (maxlength);
            break;
        }
        case 7:
        {
            printf("\nEnter element : ");
            scanf("%d", &element);
            search(element);
            break;
        }
        case 8:
        {
            printf("\nDoubly_linked_list in forward direction => ");
            display(1);
            break;
        }
        case 9:
        {
            printf("\nDoubly_linked_list in reverse direction => ");
            display(0);
            break;
        }
        }
    }
}
