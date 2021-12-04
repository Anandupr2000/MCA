#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/////TODO: Traversal - sucess
/////TODO: insert at the beginning is working fine - ok
/////TODO: insert at the last - sucess
/////TODO: insert in between the list - sucess
/////TODO: delete at the beginning 
/////TODO: delete at the last
/////TODO: delete in between the list
////////////////////////////////

int maxlength=0,*top;

// creating node
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
//displaying elements
void display(){
	struct Node *temp=head;
	while(temp!=NULL){
        printf(" %d ", temp->data);
		temp = temp->next; 
	}
}

//displaying element at specified position
void displayAt(int pos){
    int count=0;
    struct Node *temp=head;
    while(temp!=NULL){
        count++;
        if(count==pos){
            struct Node *previous=temp->prev;
            struct Node *nxt=temp->next;
            printf(" Value in current position = %d ", temp->data);
            printf(" Value in previous position = %d ", previous->data);
            printf(" Value in next position = %d ", nxt->data);
            return;
            }
		temp = temp->next;
	}
}

//inserting element
// void insert(int element){
//     struct Node *newnode = malloc(sizeof(struct Node));
//     newnode->data = element;
//     newnode->next = head;//pointing newnode's next pointer to existing node
//     newnode->prev = NULL;//pointing existing node's prev pointer to null
//     head = newnode;//pointing head to newnode
//     printf("\nAfter inserting, doubly_linked_list  => ");
//     display();
// }
void insert(int element,int pos){
    int count = 1;
    // printf("Position to be searched = %d",pos);
    // printf("\nInside insert fn");
    struct Node *temp = head; // using head address for start
    // printf("\nhead address assigned");
    struct Node *newnode = malloc(sizeof(struct Node));
    // printf("\nNew node created");
    newnode->data = element;
    // printf("\nData entered to node ,sucessfully");
    
    struct Node *previous = NULL;
    struct Node *nxt=NULL;

    //if insertion done at start of list
    if(pos==1){
        //here nxt is considered to be first node before which newnode is inserted
        printf("\nCreating new doubly linked list");
        if(head==NULL){
            head=newnode;
        }
        else{
            nxt = head;
            newnode->next = nxt;//pointing newnode's next pointer to existing node
            nxt->prev = newnode; // making first node point to newnode
        }
        newnode->prev = NULL;//pointing existing node's prev pointer to null
        head = newnode;//pointing head to newnode
        maxlength++;
        printf("\nAfter inserting, doubly_linked_list  => ");
        display();
    }
    // printf("\nSearching....");
    else{
        while (temp!= NULL)
            {
            //     printf("\ncount = %d position = %d",count,pos);
            //     printf("\ntemp->data = %d",temp->data);
            //     printf("\naddress of temp = %d",temp);
            //     printf("\nWhile loop entered,sucessfully");
                // printf("\nprevious data = %d",temp->prev->data);

                // if insertion done in position other than first and last position
                if(count==pos){
                    printf("\n%d position found",count);
                   

                    if(pos==maxlength){
                        //if insertion done at end of list, make next pointer NULL
                        temp->next=newnode;
                        newnode->prev = temp;                
                        newnode->next=NULL;
                        printf("\nInserting at end of list successfull");
                    }
                    else{
                        previous = temp->prev;
                        previous->next=newnode;
                        newnode->prev=previous;
                        newnode->next=temp;
                        printf("\nInserting at %d position of list successfull",count);
                    }
                    maxlength++;
                    printf("\nAfter inserting, doubly_linked_list  => ");
                    display();
                    break;
                }
                else{
                    printf("\nSearching....");
                    // printf(".");
                }
                temp=temp->next;
                count++;
            } 
    }
    printf("\nMaxlength = %d",maxlength);
}
//searching element
struct Node* search(int position){
	bool found = false;
    int count = 1;
	struct Node *searchedNode=head;

	while(searchedNode!=NULL){
		if(count==position){
            found = true;
			break;		
		}
		searchedNode = searchedNode->next; 
    	count++;
	}
	
    if(found) {
        printf("\n%d found at position %d.",searchedNode->data, count);
        return searchedNode;
    }
	else{
	 	printf("\n%d not found.",position);
		return NULL;	
	}
}
//deleting
void delete(int element,int pos)
{
    if (head == NULL)
    {
        printf("\nError- List empty, deletion not possible");
    }
    else
    {
	    
    struct Node *temp = search(element);
	// if(temp->prev!=NULL){
		//case1 if node is at starting
		if(temp->prev==NULL){
			head = temp->next;
			printf("\nPopped element is %d",temp->data);
			temp = temp->next;
			temp->prev=NULL;
		}
		//case2 if node is not in start 
		else{
			struct Node *prev = temp->prev;
			struct Node *nxt = temp->next;
			prev->next = nxt;
			nxt->prev = prev;			
		}
		free(temp);
    	printf("\nAfter poping, Stack : ");
    	display();
		// }
	}
    maxlength--;
}

void main() {
    int menuInput=1,element;
    
    while(menuInput!=0){
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element at first position");
        printf("\n2 - Enter element at specified position ");
        printf("\n3 - Enter element at last position");
        printf("\n4 - Delete element at first position");
        printf("\n5 - Search element ");
        printf("\n6 - Display queue ");
        printf("\n7 - Show element");
        printf("\n0 - Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &menuInput);
        switch (menuInput){
            case 0: break;
            case 1: {
                        printf("\nEnter element : ");
                        scanf("%d",&element);
                        insert(element,1);
                        break;
                    }
            case 2: {
                        int pos;
                        printf("\nEnter position : ");
                        scanf("%d",&pos);
                        printf("\nEnter element : ");
                        scanf("%d",&element);
                        insert(element,pos);
                        break;
                    }
            case 3: {
                        printf("\nEnter element : ");
                        scanf("%d",&element);
                        insert(element,maxlength);
                        break;
                    }
            
            case 4: {
                        int element;
                        printf("\nEnter element for deletion : ");
                        scanf("%d",&element);
                        delete(element,1);
                        break;
                    }        
            case 5: {
                        printf("Enter element : ");
                        scanf("%d",&element);
                        struct Node *searchedElement = search(element);
			            search(element);
                        if(searchedElement!=NULL){
                        	printf("\n%d is data found.", searchedElement->data);		
                        }
                        break;
                    }        
            case 6: {
                        printf("\nDoubly_linked_list  => ");
                        display();
                        break;
                    }        
            case 7: {
                        printf("Enter position : ");
                        scanf("%d",&element); // reading position
                        displayAt(element);//passing the position to displayAt fn
                        break;
                    }
        }
    }
}
