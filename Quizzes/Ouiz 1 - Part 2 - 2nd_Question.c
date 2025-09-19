/*
  2. Write a function 
        filterEven()
      that returns a new dynamically allocated array 
      containing all the even values. This time no size, 
      the array is appended with a sentinel (-1).

      In C programming, a sentinel value is a special 
      value used to indicate the end of a sequence of data. 
      It acts as a "flag" or "dummy value" that signals 
      a termination condition. 
      
      For example,
        arr --> | 1 | 2 | 3 | 4 | 5 | -1 |
        Index     0   1   2   3   4    5

      In this example, there are 5 elements.
      ----------------------------------------
      Another example,
        arr --> | -1 |   |   |   |   |   |
        Index     0    1   2   3   4   5
        
      In this example, the array is empty.
*/

#include <stdio.h>
#include <stdlib.h>

void filterEven();

int main() {

    return 0;
}


void filterEven(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int evenCount = 0;
    int index = 0;

    // Count even numbers until sentinel
    for(int i = 0; i < size; i++) {
        if (arr[i] == -1) break;
        if (arr[i] % 2 == 0) evenCount++;
    }

    // Allocate space for evens + sentinel
    int *newArr = (int*)malloc((evenCount + 1) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Copy even numbers
    for(int i = 0; i < size; i++) {
        if (arr[i] == -1) break;
        if (arr[i] % 2 == 0) {
            newArr[index++] = arr[i];
        }
    }

    // Add sentinel at correct position
    newArr[index] = -1;

    // Print results
    printf("Filtered array: ");
    for (int i = 0; newArr[i] != -1; i++) {
        printf("%d ", newArr[i]);
    }
    printf("-1\n");

    free(newArr);

}












