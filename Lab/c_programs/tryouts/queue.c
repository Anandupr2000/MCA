#include <stdio.h>
static int *queue;
static int front=0,rear=0,length=0;
void display(){
    for(int i=0;i<rear;i++) printf(" %d ",queue[i]);
}
void enqueue(int element){
    if(rear==length) printf("Overflow occured");
    else {
        queue[rear]=element;
        rear++;
        printf("After entering %d , queue  is : ",element);
        display();
    }
}
void dequeue(){}
void main(){
    int menuInput=1,menuExit=1,element;

    // reading size of queue
     printf("Enter length of queue : ");
    scanf("%d",&length);
    int array[length];
    queue = array;
    // displaying menu
    while(menuExit!=0){
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element : ");
        printf("\n2 - Delete element : ");
        printf("\n3 - Search element : ");
        printf("\n4 - Display queue : ");
        printf("\n0 - Exit\n");
        scanf("%d", &menuInput);
        if (menuInput == 0) break;
        else if (menuInput == 1) {
            printf("Enter element : ");
            scanf("%d",&element);
            enqueue(element);     
        }
        else if (menuInput==2)
        {
            // dequeue
            dequeue();     
        }
        else if (menuInput==3)
        {
            /* search */
            ;
        }
          
    }
}