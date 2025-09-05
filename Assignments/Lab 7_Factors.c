#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);
int *getNumFactors(int arr[], int n, int *ret);


int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
    int item, answer;
    int ret_n;
    
    display(arr, n);
    int *factorList = getNumFactors(arr, n, &ret_n);
    
    display(factorList, ret_n);
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

int *getNumFactors(int arr[], int n, int *ret_n){
    //This function gets all the factors of a number in the collection
    *ret_n = 0;
    int *list = malloc(sizeof(int) * n);
    
    int x;
    int count = 0;
    
    printf("Enter a Number: ");
    scanf("%d", &x);
    for(int i = 0; i < n; i++){
        if(x == arr[i]){
            count++;
        }
    }
    
    if(count == 0){
        printf("Error! %d not found.", x);
    } else {
        printf("Factors: ", x);
        for(int i = 1; i <= x; i++){
            if(x % i == 0){
                list[(*ret_n)++] = i;
            }
        }
    }
    return list;
}



