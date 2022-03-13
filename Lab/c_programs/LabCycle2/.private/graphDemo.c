#include <stdio.h>
#include <stdlib.h>

// structure of graph used here is array of vertex as each vertex is a linked list,
// containing node to next adjucent vertices
struct Node{
    int value;
    struct Node *adjVertex;
};
struct Node *start = NULL;
void read(){
    int noVertices,i=0;
    printf("Enter the no of vertices : ");
    scanf("%d",&noVertices);
    s = calloc(noVertices, sizeof(struct Node));
    while(start){
        int noAdj=0;
        struct Node *n=NULL;
        printf("Enter value for vertex %d : ",i);
        scanf("%d",&start->value);
        printf("\nEnter -1 to exit entering values");
        printf("Enter value for adjacent vertices for %d : ",start->value);
        start->adjVertex = n; 
        do{
            n = malloc(sizeof(struct Node));
            scanf("%d",n->value);
            n = n->adjVertex; 
        }while(n->value!=-1);
        start->adjVertex = calloc(noAdj,sizeof(struct Node));
        start++;
    }
}
void display(){
    if(start){

    }
    else{
        printf("No graph found");
    }
}
void main(){
    display();
}