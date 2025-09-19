/*
    3. Write a display function that uses the array property in question 2 i.e. the sentinel value.
        void display(int *arr);
        void display(int arr[]);
*/

#include <stdio.h>
#include <stdlib.h>

int* filterEven();
void display(int *arr);

int main() {

    // filterEven();
    int *filteredArray = filterEven();
    
    printf("Even Numbers: ");
    display(filteredArray);
    free(filteredArray);
    return 0;
}

int* filterEven(){
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

    // Copy even numbers
    for(int i = 0; i < size; i++) {
        if (arr[i] == -1) break;
        if (arr[i] % 2 == 0) {
            newArr[index++] = arr[i];
        }
    }

    // Add sentinel at correct position
    newArr[index] = -1;

    return newArr;

}



void display(int *arr) {
    int i = 0;
    while (arr[i] != -1) {
        if(arr[i + 1] ==  -1) {
            printf("%d ", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
        i++;
    }
}
