#include <stdio.h>
// #include <stdbool.h>

int rear=-1,front=-1,*array,maxlength;

void read(){
    for(int i=0;i<maxlength;i++) scanf("%d",&array[i]);
    }
void display(){
    for(int i=0;i<maxlength;i++) printf(" %d ",array[i]);
}
// bool isFull(){
//     if(rear==maxlength) return true;
//     else return false;
// }
// bool isEmpty(){
//     if(front==maxlength) return true;
//     else return false;
// }
void enqueue(int element){
    printf("\nenqueing...");
    if(rear==-1){
        rear++;
        array[rear]=element;
    }
    else if(rear==front){
        printf("\nOverflow occured");
    }
    else{
        if(rear==maxlength-1){//checking rear is at the end
            printf("rear is maximum");
            array[rear]=element;
            rear = 0;
        }
        else {
            printf("\ninserting...");
            array[rear]=element;
            rear++;
        }
    }
    printf("\nAfter inserting %d, queue is ",element);
    display();
}
void dequeue(){
    if(front==rear-1){
        printf("Underflow occured");
    }
    else{
        printf("Element deleted is : %d",array[front]);
        if(front==maxlength-1){
            array[front]=0;
            printf("\nElement deleted is : %d",array[front]);
            front = 0;
        }
        else{
            array[front]=0;
            front++;
        }
    }
    printf("\nAfter deleting, queue is ");
    display();
}
void search(int element){
    for(int i=0;i<maxlength;i++){
        if(array[i]==element){
            printf(" %d found at index position %d",array[i],i);
        }
    }
}
void main(){
    int menuInput=1,element;
    printf("Enter no of elements in queue : ");
    scanf("%d",&maxlength);

    int a[maxlength];
    array = a;
    // read();

    // printf("\nQueue elements are : ");
    // display();
    while(menuInput!=0){
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element : ");
        printf("\n2 - Delete element : ");
        printf("\n3 - Search element : ");
        printf("\n4 - Display queue : ");
        printf("\n0 - Exit\n");
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