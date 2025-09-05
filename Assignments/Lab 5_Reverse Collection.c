#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);

int occurance(int arr[], int n, int item);
int getPrime(int arr[], int n);
int getNumPosition(int arr[], int n);

bool checkElement(int arr[], int n);
bool numPalindrome(int arr[], int n);
bool fibonacciSeq(int arr[], int n);
bool nextNumSmaller(int arr[], int n);

char **getClassify(int arr[], int n);
int *getReversed(int arr[], int n);
int *getReplaced(int arr[], int n);
int *getNumFactors(int arr[], int n, int *ret);
int *getComposite(int arr[], int n, int *ret);


int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
    int item, answer;
   
    printf("Display:");
    display(arr, n);
    int *reverseList = getReversed(arr, n);
    printf("Reversed:");
    display(reverseList, n);
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


int *getReversed(int arr[], int n){
    //This function reverses elements in the collection
    int *temp = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        temp[i] = arr[n - 1 - i];
    }
    return temp;
}


