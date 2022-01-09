#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *set1=NULL,*set2=NULL,set1Length=0,set2Length=0;

int search(int element, int *arr, int length){
    int pos; 
    bool found = false;
    for(int i=0;i<length;i++){
        if(arr[i]==element){
            pos = i; 
            found = true; 
            break;
        }
    }
    if(found){
        return pos;
    }
    else{
        return -1;
    }
}
// void setInit(int eIndex){
//     for(int i=0; i<eIndex; i++){
//         if(search(set[i],elements,elementsCount)==-1)
//             set[i] = 0;
//     }
// }
void displaySet(int *arr,int length){
    printf("\nArray elements are :");
    for(int i=0; i<length; i++){
        printf(" %d",arr[i]);
    }
}
// int length(int *arr, int length){
//     if(arr==NULL) return -1;
//     int count = 0;
//     for(int i=0; i<length;i++){
//         count++;
//     }
//     return count;
// }
// fn for reading 2 sets
void readSet(int *set,int *l){
    int element;
    printf("\nEnter -1 for quit");
    printf("\nEnter elements :\n");
    while(true)
    {
        printf("length is %d\n",*l);
        scanf("%d",&element);
        if(element == -1) break;
        else
        {
            if(search(element,set1,set1Length)==-1 && search(element,set2,set2Length)==-1)
            {
                if(set==NULL) 
                {
                    set = calloc(1,sizeof(int));
                    set[0] = element;
                    (*l)++;
                }
                else
                {
                    (*l)++;
                    set = realloc(set,(*l)*sizeof(int));
                    set[(*l)-1] = element;
                }
                // if(set==set1)   set1Length++;
                // else if(set==set2)   set2Length++;
            }
        }
    }
}
void main(){
    system("clear");
	int choice =1;
    // intializing arrays
    // set = calloc(1,sizeof(int));
    // setRep = calloc(1,sizeof(int));
	while(choice!=0)
	{
		printf("\n1 - Enter set");
		printf("\n2 - Display Array");
		printf("\n3 - Display set elements");
		printf("\n0 - Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
                printf("\nEnter set1\n");
				readSet(set1,&set1Length);
                printf("\nEnter set2\n");
				readSet(set2,&set2Length);
				break;	
				}
			case 2:{
                printf("\nSet1\n");
				displaySet(set1,set1Length);
                printf("\nSet2\n");
				displaySet(set2,set2Length);
				break;	
				} 	
		}
	}
	free(set1);
	free(set2);
}