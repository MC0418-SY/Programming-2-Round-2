#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void display(int arr[], int n);
bool fibonacciSeq(int arr[], int n);

int main(){
    int n = 10;
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int fibo[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    
    display(arr,n);
        if(fibonacciSeq(arr, n)){
            printf("YES, it is part of the Fibonacci Sequence\n\n");
        }
        else{
            printf("NO, it is not a part of Fibonacci Sequence\n\n");
        }
    
    display(fibo,n);
        if(fibonacciSeq(fibo, n)){
            printf("YES, it is part of the Fibonacci Sequence\n\n");
        }
        else{
            printf("NO, it is not a part of Fibonacci Sequence\n\n");
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

bool fibonacciSeq(int arr[], int n) {
    //This function is for checking if the numbers in the collection are in the Fibonacci sequenc
    for (int i = 2; i < n; i++) {
        if (arr[i] != arr[i - 1] + arr[i - 2]) {
            return false;
        }
    }
    return true;
}

