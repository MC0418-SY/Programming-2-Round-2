/*
    1. Write a function 
            int *filterEven(int *nums, int size, int *newSize)
        that returns a new dynamically allocated array containing 
        all the even values and updates newSize of the number of 
        even.
*/

#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n);

int main() {
    //set the size of the array first
    int size = 5;
    //initialize the array using malloc
    int *arr = malloc(sizeof(int) * size);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    display(arr, size);
    
    printf("Third Element: %d\n", *(arr + 2));
    printf("Last Element: %d\n", arr[size - 1]);
    
    arr = realloc(arr, sizeof(int) * (size + 3));
    arr[size++] = 60;
    display(arr, size);
    
    int i;
    for(i = size; i > 0; --i) {
        if(arr[i - 1] > 25) {
            arr[i] = arr[i - 1];
        } else {
            break;
        }
    }
    arr[i] = 25;
    size++;
    display(arr, size);
    
    for(i = 0; i < size && arr[i] != 40; ++i) {}
    for(; i < size; ++i) {
        arr[i] = arr[i+1];
    }
    size--;
    display(arr, size);
    
    arr[0] = 5;
    display(arr, size);
    
    printf("SIZE: %d\n", sizeof(arr)/sizeof(int));
    
    printf("REVERSE: ");
    for(int i = size - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for(i = 0; i < size && arr[i] != 25; ++i) {}
    printf("INDEX: %d", i);
    
    return 0;
}

void display(int arr[], int n) {
    printf("{");
    for(int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if(i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
