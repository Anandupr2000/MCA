#include <stdio.h>
#include <stdbool.h>

int rear=-1,front=-1,*array,maxlength;

void read(){
    for(int i=0;i<maxlength;i++) scanf("%d",&array[i]);
    }
void display(){
    for(int i=0;i<maxlength;i++) printf(" %d ",array[i]);
}
bool isFull(){
   // 1 is added to rear since rear start from 0
    if(front==((rear+1)%maxlength)) return true;
    else return false;
}
bool isEmpty(){
    if(front==-1) return true;
    else return false;
}
void enqueue(int element){
    if(isFull()){
        printf("\nError - Overflow occured");
    }
    else{
        printf("\nInserting...");
        if(front ==-1 && rear==-1){
            ++front;
            ++rear;  
        }
        else {
                printf("rear = %d",rear);
                rear = (rear+1)%maxlength;
                if(front == rear-maxlength||front == rear+1){//checking rear is at the end
                printf("\n\n**** Warning! No more insertion possible since rear is at maximum ****\n");
                }
        }
        array[rear] = element;
        printf("\nAfter inserting %d, queue is ",element);
        display();
    }
}
void dequeue(){
    if(isEmpty()){
        printf("Error - Underflow occured");
    }
    else{
        printf("Element deleted is : %d",array[front]);
        array[front]=0;
        printf("\nAfter deleting, queue is ");
        display();
        if(front==rear){
            printf("\n\n**** Warning! No more deletion is possible since front is at rear ****\n");
            front = -1;
            rear = -1;
        }else{
            front=(front+1)%maxlength;
        }
        printf("\nfront = %d\n",front);
    }
}
void search(int element){
    for(int i=0;i<maxlength;i++){
        if(array[i]==element){
            printf(" %d found at index position %d",array[i],i+1);
            break;
        }
    }
}
void main(){
    int menuInput=1,element;
    printf("Enter length of queue : ");
    scanf("%d",&maxlength);

    int a[maxlength];
    array = a;
   
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
                    enqueue(element);
                    break;
                    }
            case 2: {
                        dequeue();
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