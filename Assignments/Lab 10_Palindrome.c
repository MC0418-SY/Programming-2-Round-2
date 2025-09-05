#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void display(int arr[], int n);
bool numPalindrome(int arr[], int n);


int main(){
    int arr[10] = {2, 1, 1, 1, 1, 1, 1, 1, 1, 2};
    int n = 10;
    
    
    display(arr, n);
        if(numPalindrome(arr, n)){
            printf("YES, it is a palindrome\n\n");
        }
        else{
            printf("NO, it is not a Palindrome\n\n");
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

bool numPalindrome(int arr[], int n) {
    //This function is for checking if the collection is palindromic
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;  
        }
    }
    return true;  
}
