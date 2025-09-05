#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);

int getPrime(int arr[], int n);

int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
    
    int item, prime;
    
    display(arr, n);
    prime = getPrime(arr, n);
    printf("No. of Prime Numbers: %d\n", prime);

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


int getPrime(int arr[], int n){
    //This function is to count the number of prime numbers in the collection
    int count = 0;
    int isPrime = 0;
 
    for(int i = 0; i < n; i++){
        int x = arr[i];
        isPrime = 1;
       if(x <= 1){
           isPrime = 0;
       }
       for(int j = 2; j * j <= x; j++){
               if(x % j == 0){
                   isPrime = 0;
               }
           }
        if(isPrime >= 1){
            count++;
        }
    }
    return count;
}


