#include <stdio.h>  
#include <stdlib.h> 


int *filterEven(int nums[], int size, int *newSize);

// Main Function
int main() {
    int size = 5;
    int hayst;
    int arr[] = {10, 20, 30, 40, 50};


    int *omg = filterEven(arr, size, &hayst);
    
    printf("bruh");

    return 0;
}

int *filterEven(int nums[], int size, int *newSize){
    
    int evenCount = 0;
    
    for (int i = 0; i < size; ++i){
        if (nums[i] % 2 == 0){
            (*newSize)++;
        }
    }
    
    int *newArr = (int*)malloc(size * sizeof(int));
    
    for(int i = 0; i < *newSize; ++i){
        if (nums[i] % 2 == 0){
            newArr[i] = nums[i];
        }
    }
    
    return newArr;
    
    
    
    
    
    
    
    
}
