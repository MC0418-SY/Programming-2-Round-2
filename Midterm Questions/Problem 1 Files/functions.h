#include <stdio.h>
#include <stdlib.h>

#define SIZE 8  /* initial size of the array */

// Initialize dynamic array to SIZE
int* init_array(void) {
    int *newArr = malloc(sizeof(int) * SIZE);
    return newArr;
}

//Insert given input to dynamic array in ascending order
void insert_sort(int *arr, int count, int value) {
    int key, j;
    for(int i = 1; i < count; ++i){
        key = arr[i];
        j = i -1;
        
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        
        arr[j+1] = key;
        
    }
}

//prints the current array only up to the last count
void print_array(const int *arr, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// asks for user's integer input, rejecting invalid then Inserts each valid unique integer 
// into the sorted array and prints the array after every successful insertion.
// The program should accept only 1 duplicate of any number, for every duplicate 
// increase the size of the array by 1.
// Returns the last count
int populate_array(int *arr) {
    int max = SIZE; 
    int count = 0;
    int num;
    
    
    for (int i = 0; i < max; ){
        printf("Enter integer #%d: ", i + 1);
        scanf("%d", &num);
        
        int occur = 0;
        for(int j = 0; j < i; ++j){
            if(arr[j] == num){
                occur++;
            }
        }
        
        if(occur == 0){
            arr[i] = num;
            count = i + 1;
        } else if (occur == 1){
            arr[i] = num;
            count = i + 1;
            max++;
            printf("duplicate accepted, array size increased to %d\n", max);
        } else if(occur > 1) {
            printf("The integer %d already appears twice. Third instance rejected. Please enter a different value.\n", num);     
            continue;
        }
        
        insert_sort(arr, count, arr[i]);
        printf("Current array: ");
        print_array(arr, count);
        
        i++;
    }
}
