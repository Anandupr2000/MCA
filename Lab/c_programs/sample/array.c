#include <stdio.h>
// #include <conio.h>

void main(){
    int size = 5;
    int a[10]={1,2,3,4,5,6,9,10};
    int *ptr = a;
    int i=0;
    while(*ptr){
        printf(" %d",*ptr);
        ptr++;
        i++;
    }
    for(;i<10;i++){
        printf(" %d",*ptr);
        ptr=ptr+i;
        if(!*ptr) break;
    }
}