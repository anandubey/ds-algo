/******************************************************************************
*   author: Anand Kumar Dubey
******************************************************************************/


#include <stdio.h>


/*************************** Function declarations ***************************/

int search(int *arr, int arr_len, int to_find); 

/*********************** Function declarations END ***************************/


int search(int *arr, int arr_len, int to_find)
{
    /*
    *   Input:
    *       1. Integer array
    *       2. length of the array
    *       3. Item to be searched
    * 
    *   Output:
    *       Index of the item to be searched or -1 if not found.
    */

    for (int i=0; i < arr_len; i++)
    {
        if (*(arr + i) == to_find)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int to_find = 5;
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    
    int index = search(arr, arr_len, to_find);
    (index == -1)
        ? printf("Element is not present in array\n")
        : printf("Element is present at index %d\n", index);
    
    return 0;
}
