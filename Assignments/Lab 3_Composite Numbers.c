#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void display(int arr[], int n);
int *getComposite(int arr[], int n, int *ret);


int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
    int item, answer;
    int ret_n;
    
    display(arr, n);
    int *compositeList = getComposite(arr, n, &ret_n);
    
    display(compositeList, ret_n);
    free(compositeList);
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



int *getComposite(int arr[], int n, int*ret_n){
    //This function is to get and display the composite numbers in the collection
    *ret_n = 0;
    int isComp = 0;
    
    int *list = malloc(sizeof(int)*n);
    
        for(int i = 0; i < n; i++){
            int x = arr[i];
            isComp = 1;
             for(int j = 2; j * j <= x; j++){
                   if(x % j == 0){
                       isComp = 0;
                   }
               }
            if(!isComp)
            list[(*ret_n)++] = arr[i];
        }
    return list;
}



