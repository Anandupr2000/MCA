#include <stdio.h>
#include <stdbool.h>

int setCreate(int *arr,int setStart)
{
    int i = setStart-1, element;
    printf("Enter -1 to exit\n");
    while (true)
    {
        printf("Enter element %d : \n", i + 1);
        scanf("%d", &element);
        // checking enter is for exit or not
        if (element == -1)
        {
            break;
        }
        else
        {
            // insert element to set
            // int flag=0;
            // while(flag==0)
            // {
            //     for(int j=i-1;j>=0;j--)
            //     {
            //         if(arr[j]==e)
            //         {
            //             printf("\n%d already entered !!!\n\nEnter a new one : ",e);
            //             scanf("%d", &e);
            //         }
            //         else
            //         {
            //             // if element is unique, enter it to array and exit
            //             arr[i]=e;
            //             flag=1;
            //         }
            //     }
            // }
            int j = i;
            // if(arr[i]!=NULL)
            // {
                // finding free array index
                // while (arr[j] != NULL)
                // {
                //     j++;
                // }
                // printf("\nvacant index found after traversing %d indices\n",j);
                arr[j] = element;
            // }
            i++;
        }
    }
}
void showArray(int *arr)
{
    int i = 0;
    printf("Array => ");
    // checking for not null index
    while (arr[i] != NULL)
    {
        printf(" %d", arr[i]);
        i++;
    }
}
// void elementAt(int *arr, int index){
//         printf(" %d ",)
// }
void processChoice(int choice)
{
    int *set;
    switch (choice)
    {
    case 1:
    {
        int choice1 = 1, i = 1,length=1;
        while (true)
        {
            printf("\n============================\n");
            printf("1.Read Set%d\n", i);
            printf("0.Exit\n");
            printf("\n============================\n");
            printf("Enter Choice:");
            scanf("%d", &choice1);
            if (choice1 == 0)
                break;
            else
            {
                length += (setCreate(set,length))-1;
            }
            i++;
        }
        break;
    }
    case 2:
    {
        showArray(set);
    }
    case 3:{
        int index;
        printf("\nEnter index value : ");
        scanf("%d",index);
        int e;
        for(int i=0;i<index;i++) if(i=index-1) printf("ELement at %d is %d" ,index,set[i]);
    }
    }
}
void main()
{
    int choice = 1;
    system("clear");
    while (true)
    {
        printf("\n============================\n");
        printf("1.Read Set\n");
        printf("2.Show set\n");
        printf("3.Show element \n");
        printf("0.Exit\n");
        printf("\n============================\n");
        printf("Enter Choice:");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        else
        {
            processChoice(choice);
        }
    }
    // do{
    //     printf("\n============================\n");

    //     printf("5.Union\n");
    //     printf("6.Intersection\n");
    //     printf("7.Difference\n");
    //     printf("8.Print Sets\n");
    //     printf("0.Exit\n");
    //     printf("\n============================\n");
    //     printf("Enter Choice:");
    //     scanf("%d",&choice);
    // }while(choice!=0);
}