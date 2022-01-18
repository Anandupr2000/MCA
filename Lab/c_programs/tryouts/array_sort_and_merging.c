#include <stdio.h>
void read(int count, int *arr)
{
    for (int i = 0; i < count; i++)
        scanf("%d", &arr[i]);
}
void display(int count, int *arr)
{
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
}
void sort_array(int count, int *arr)
{
    int temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void main()
{
    int i, count1, count2;

    // reading limit of first array
    printf("Enter limit of first array : ");
    scanf("%d", &count1);

    // reading first array
    int arr1[count1];
    printf("Enter first array : ");
    read(count1, arr1);

    // reading limit of second array
    printf("Enter limit of second array : ");
    scanf("%d", &count2);

    // reading second array
    int arr2[count2];
    printf("Enter second array : ");
    read(count2, arr2);

    // printing both arrays
    printf("\nfirst array => ");
    display(count1, arr1);
    printf("\nsecond array => ");
    display(count2, arr2);

    // sorting both arrays
    // sorting first array
    sort_array(count1, arr1);
    // sorting second array
    sort_array(count2, arr2);

    printf("\n********* sorted arrays ********* ");
    printf("\nfirst array => ");
    display(count1, arr1);
    printf("\nsecond array => ");
    display(count2, arr2);

    // merging both arrays together
    int count3 = count1 + count2;
    int arr3[count3];
    // inserting first array
    for (i = 0; i < count1; i++)
        arr3[i] = arr1[i];
    // inserting 2nd array
    for (i = 0; i < count2; i++)
        arr3[count1 + i] = arr2[i];

    // sorting merged array
    sort_array(count3, arr3);
    // printing merged array
    printf("\n********* merged array ********* ");
    printf("\nmerged array is => ");
    display(count3, arr3);
}