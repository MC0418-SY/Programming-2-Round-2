#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);
int *replace(int arr[], int n);


int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
    display(arr, n);
    int *replaceList = replace(arr, n);
    display(replaceList, n);
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

int *replace(int arr[], int n){
    //This function replaces a number in the collection
    int num;
    int changed;
    int count = 0;
    
    int* temp = malloc(sizeof(int) * n);
    
    printf("Enter Number to Change: ");
    scanf("%d", &num);
        
    for(int i = 0; i < n; i++){
        if(num == arr[i]){
                printf("Change Number to: ");
                scanf("%d", &changed);
                arr[i] = changed;
                count++;
            }
            temp[i] = arr[i];
        }
        if(count == 0){
            printf("%d not found", num);
        }
       return temp;
}



