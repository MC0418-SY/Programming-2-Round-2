#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);
int getNumPosition(int arr[], int n);

int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
   
    display(arr, n);
    int search = getNumPosition(arr, n);
    printf("Position: %d\n", search);
    
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



int getNumPosition(int arr[], int n) {
    //This function is for getting the position of the entered number.
    int value;

    printf("Enter a Number: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;  
        }
    }

    return -1; 
}



