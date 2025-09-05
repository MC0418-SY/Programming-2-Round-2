#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);
char **getClassify(int arr[], int n);

int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 20, 10};
    int n = 10;
    
    int item, answer;
    
    display(arr, n);
    
    char **list = getClassify(arr, n);
    
    for(int i = 0; i < n; i++){
        printf("%d = %s\n", arr[i], list[i]);
        free(list[i]);
    }
    
    free(list);
    
    printf("\n");
            

    return 0;
}



void display(int arr[], int n){
    //This function is for displaying the array
    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i< n-1){
            printf(", ");
        }
    }
    printf("}\n");
    
}

char **getClassify(int arr[], int n){
    //This function classifies the elements in the array in to "fizz", "buzz", and "fizzbuzz".
    /*  
        Fizz = if divisible by 2
        Buzz = if divisible by 5
        FizzBuzz = if divisible by 2 and 5
    */
 
    char **type = malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        type[i] = malloc(20 * sizeof(char));
        
        if (arr[i] % 2 == 0 && arr[i] % 5 == 0) {
            strcpy(type[i], "FizzBuzz");
        }
        else if(arr[i] % 5 == 0){
            strcpy(type[i], "Buzz");
        }
        else if (arr[i] % 2 == 0){
            strcpy(type[i], "Fizz");
        }
        else{
            strcpy(type[i], "None");
        }
    }
    
    
    
    return type;
}


