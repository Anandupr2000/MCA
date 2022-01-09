#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *set,length=10;
bool isPresent(int element,int *arr){
	for(int i=0;i<length;i++){
		if(arr[i]==element){
			return true;	
		}
		else return false;
	}
}
void readSet(int *arr){

	printf("\nEnter elements \n");
	for(int i=0;i<length;i++){
		int temp, flag = 1;	
		scanf("%d",&temp);				
		while(flag!=0)
		{
			if(isPresent(temp,arr)) 
			{
				printf("\nElement already present !!\n\nEnter new one : ");
				scanf("%d",&temp);			
			} 
			else
			{
				arr[i]=temp;
				flag=1;
			}
		}	
	}
}
void displaySet(int *arr){
	
	printf("\nSet elements are : ");
	for(int i=0;i<length;i++){
		printf(" %d",arr[i]);	
	}
	
}
void main(){
	int choice =1;
	set = calloc(10,sizeof(int));
	while(choice!=0)
	{
		printf("\n1 - Enter set elements");
		printf("\n2 - Display set elements");
		printf("\n0 - Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
				readSet(set);
				break;	
				}
			case 2:{
				displaySet(set);
				break;	
				} 	
		}
	}
	free(set);
}
