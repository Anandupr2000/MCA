#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int *set = NULL,*setRep=NULL,*elements=NULL,elementsCount=0,setLength=0,setRepLength=0;
bool isPresent(int element,int *arr){
	for(int i=0;i<setLength;i++){
		if(arr[i]==element){
			return true;	
		}
		else return false;
	}
}
void displaySet(){
    printf("\nEntered elements are :");
    for(int i=0;i<elementsCount;i++) printf(" %d",elements[i]);
	printf("\nArray elements are : ");
	for(int i=0;i<setLength;i++){
		printf(" %d",set[i]);	
	}
    
	printf("\nArray representative elements are : ");
	for(int i=0;i<setRepLength;i++){
		printf(" %d",setRep[i]);	
	}
    printf("\n");
}
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
// void correctArray(){
//     for(int i=0; i<setRepLength;i++){
//         for(int j=0; j<setLength;j++){
//             if(set[j]!=setRep[i] || set[j]!=-1){
//                 set[j] = 0;
//             }
//         }
//     }
// }

// fn for intializing block of array created by realloc to 0
void setInit(int sIndex,int eIndex){
    for(int i=sIndex; i<=eIndex; i++){
        set[i] = 0;
    }
}
void readElements(int setNo){
    int element, temp,loop =1;
    bool setRepresentative = true;
    printf("\nEnter -1 to exit\n");
    
    int i = elementsCount;
    printf("\nEnter elements : \n");
    while(true){
        if(element==-1) break;
        else
        {
            scanf("%d",&element); 
            temp = setLength;// saving current value of set
            if(set==NULL){
                set = calloc(1,sizeof(int));
                setRep = calloc(1,sizeof(int));
            }
            if(search(element,elements,elementsCount)==-1)
            {
                // saving element entry 
                elements = realloc(elements,(++elementsCount)*sizeof(int));
                elements[i] = element;
                printf("\nEntered element is : %d",elements[i]);
                i++;
                // entering set Rep element and set element
                if(setRepresentative)
                {
                    printf("\nSetting set rep as %d",element);
                    setRep = realloc(setRep,(++setRepLength)*sizeof(int));
                    printf("\nset Rep length increased to %d\n",setRepLength);
                    if (element>=setLength) 
                    {
                        printf("\n%d >= %d \n",element,setLength);
                        setLength = element+1;
                        printf("\nAllocating new memory");
                        set = realloc(set,(setLength)*sizeof(int));
                        // if(set==NULL) printf("Realloc returned null ptr");

                        setInit(temp,setLength);
                    }
                    
                    printf("\nset length increased to %d\n",setLength);
                    set[element] = -1;
                    printf("\nroot %d set as -1\n",element);
                    setRep[setRepLength-1] = element; // storing element as set rep
                    printf("\nset rep is %d\n",setRep[setRepLength-1]);
                    setRepresentative = false;
                }
                else
                {
                    printf("\nindex %d have root %d \n",element,setRep[setNo]);
                    if(element>=setLength){
                        // printf("Element greater than length of set");
                        setLength = element+1;
                        printf("\n%d >= %d \n",element+1,setLength);
                        set = realloc(set,(setLength)*sizeof(int));
                        setInit(temp,setLength);
                    }
                    set[element] = setRep[setNo];
                    // else{
                    //     // printf("Element greater than length of set");
                    //     printf("\n%d < %d \n",element,setLength);
                    //     set[element] = setRep[setNo];
                    // }
                }
            }
            else{
                printf("\nElement previously entered!!!\nEnter new one : ");
            }
            // correctArray();
            displaySet();
        }
    }
}
void readSet(){
    readElements(setRepLength); // passing set number
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
				readSet();
				break;	
				}
			case 2:{
				displaySet();
				break;	
				} 	
		}
	}
	free(set);
	free(setRep);
}