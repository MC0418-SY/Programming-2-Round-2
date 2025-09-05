#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void display(int arr[], int n);
int occurance(int arr[], int n, int item);

int main(){
    srand(time(NULL));
    int arr[10];
    int n = 10;
    
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 11 + 1;
    }
    
    int item, answer;
    
    display(arr, n);
    answer = occurance(arr, n, item);
    printf("Occurances: %d\n", answer);
    
    
    

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

int occurance(int arr[], int n, int item){
    //This function is to count the number of occurences for a number
    printf("Enter a Number: ");
    scanf("%d", &item);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(item == arr[i]){
            count++;
        }
    }
    return count;
}

