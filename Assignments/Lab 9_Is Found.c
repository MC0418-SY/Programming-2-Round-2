#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);
bool checkElement(int arr[], int n);

int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;

    display(arr, n);
    if(checkElement(arr, n)){
        printf("TRUE, %d is in the collection.\n\n");
    }
    else{
        printf("FALSE, %d is not in the collection.\n\n");
    }
 
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


bool checkElement(int arr[], int n){
    //This function is to check if the entered element is in the collection. 
    int value;
    int count = 0;
    
    printf("Enter a Number: ");
    scanf("%d", &value);
    
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            return true;
        }
    }
    
    return false;
}


