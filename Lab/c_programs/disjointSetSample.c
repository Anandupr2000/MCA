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
// fn for intializing block of array created by realloc to 0
void setInit(int sIndex,int eIndex){
    for(int i=sIndex; i<=eIndex; i++){
        set[i] = 0;
    }
}
void readElements(int setNo){
    int element, loop =1,temp;
    bool setRepresentative = true;
    printf("\nEnter -1 to exit\n");
    // int a,b;
    // set = a;
    // setRep = b;
    int i = elementsCount;
    printf("\nEnter elements : \n");
    while(true){
        if(element==-1) break;
        else
        {
            scanf("%d",&element); 
            // saving entry to array
            // if(setLength==0){
            //     set = calloc(++setLength,sizeof(int));
            //     setRep = calloc(++setRepLength,sizeof(int));
            //     setRep[0] = element;
            //     set[0] = element;
            // }
            // else{
            //     if(element>setLength+1){
            //         //reallocate set array with greater size 
            //         setLength = element+1;
            //         set = realloc(set,(setLength)*sizeof(int));
            //         // search 
                // }
            // }
            temp = setLength;// saving current value of set
            if(search(element,elements,elementsCount)==-1)
            {
                // saving element entry 
                elements = realloc(elements,(++elementsCount)*sizeof(int));
                elements[i] = element;
                printf("\nEntered element is : %d",elements[i]);
                i++;
                if(setRepresentative)
                {
                    printf("\nSetting set rep as %d",element);
                    setRep = realloc(setRep,(++setRepLength)*sizeof(int));
                    if(element>=setLength) setLength = element+1;
                    printf("\nset Rep length increased to %d\n",setRepLength);
                    if (set == NULL) 
                    {
                        set = realloc(set,setLength*sizeof(int));
                        setInit(temp,setLength);
                    }
                    printf("\nset length increased to %d\n",setLength);
                    set[element] = -1;
                    printf("\nroot %d set as -1\n",element);
                    setRep[setRepLength-1] = element;
                    printf("\nset rep is %d\n",setRep[setRepLength-1]);
                    setRepresentative = false;
                }
                else
                {
                    printf("\nindex %d have root %d \n",element,setRep[setNo]);
                    if(element>=setLength){
                            // printf("Element greater than length of set");
                            printf("\n%d >= %d \n",element,setLength);
                            setLength = element+1;
                            set = realloc(set,(setLength)*sizeof(int));
                            setInit(temp,setLength);
                        }
                        set[element] = setRep[setNo];
                }
            }
            else{
                printf("\nElement already entered!!\nEnter new one : ");
            }
            
        }
        // since 0 is also a number and array intial length
        // if(element>=setLength){
        //     setLength = element+1;
        //     set = realloc(set,(setLength)*sizeof(int));
        //     if(setRepresentative){ // if set representative not setup 
        //         setRep = realloc(setRep,(++setRepLength)*sizeof(int));
        //         set[element] = -1;
        //         setRep[setRepLength-1] = element; 
        //         setRepresentative =false;
        //     }
        //     else{
        //         // storing element with index value itself as its root value
        //         // printf("\nEntering value to set with index %d and root %d after setting up setRepresentative ",set[element-1],setRep[setNo-1]);
        //         // printf("\nSet representative = %d",setRep[setNo]);
        //         set[element] = setRep[setNo];
        //     }
        // }
        // // if element less than length of set array
        // else{
        //     // printf("\nEntering value to set");
        //     // printf("\nSet representative = %d",setRep[setNo]);
        //     set[element] = setRep[setNo];
        // }
    }
}
void readSet(){
    int choice,flag = 1,i=0;
    // while (flag==1){
    //     printf("\n\n1 - Enter Set%d",i+1);
    //     printf("\n0 - Exit");
    //     scanf("%d", &choice);
    //     switch (choice){
    //         case 0:
    //             {
    //                 flag =0;
    //                 break;
    //             }
    //         case 1:
    //             {
                    readElements(setRepLength); // passing set number
    //             }
    //     }
    //     i++;
    // }
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