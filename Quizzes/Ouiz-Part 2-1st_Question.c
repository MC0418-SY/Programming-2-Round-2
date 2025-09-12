#include <stdio.h>  
#include <stdlib.h> 

//Function prototype
int *filterEven(int *nums, int size, int *newSize);


int main() {
    
    //initialize the array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //get the size of the initialized array by using sizeof
    //sizeof is used to compute the size of its operand, which may be a data type or a variable
    //int = 4 bytes
    int size = sizeof(arr)/sizeof(arr[0]);
    
    //this is to store the newsize of the filtered array
    int hayst;

    //store the filtered array in an interger pointer since the function returns an array
    int *omg = filterEven(arr, size, &hayst);

    //this is for checking if omg is NULL or not
    if(omg != NULL){
        //if omg is NOT NULL, then it prints
        for (int i = 0; i < hayst; ++i){
            printf("%d  ", omg[i]);
        }    
    }

    //unnecessary statement by the coder
    printf("\nbruh");

    //always remember to free the dynamically allocated array to avoid a crash
    free(omg);

    return 0;
}


//this function is used to filter even elements in an array
int *filterEven(int *nums, int size, int *newSize){

    //this is to keep track of the number of even elements
    int evenCount = 0;
    
    for (int i = 0; i < size; ++i){
        //if the element is even, then evenCount increments
        if (nums[i] % 2 == 0){
            evenCount++;
        } 
    }

    //Set the new size using evenCount
    *newSize = evenCount;

    //Initialize the array here
    int *newArr = (int*)malloc(evenCount * sizeof(int));


    //this is to separate the index of nums and the newArray to avoid display issues
    int index = 0;
    for(int i = 0; i < size; ++i){
        //if the element is even, then it is stored in newArr
        if (nums[i] % 2 == 0){
            newArr[index++] = nums[i];
        }
    }

//The function will now return the new array
    return newArr;
}
