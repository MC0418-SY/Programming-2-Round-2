#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void display(int arr[], int n);
bool nextNumSmaller(int arr[], int n);

int main(){
    int arr[10] = {45, 7, 2, 35, 43, 3, 12, 34, 12, 1};
    int n = 10;
    
    display(arr, n);
    if(nextNumSmaller(arr, n)){
        printf("YES, they are smaller.\n\n");
    } else {
        printf("NO, they are not smaller.\n\n");
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

bool nextNumSmaller(int arr[], int n) {
    //This function is to check all the values after the specified first occurence of a given value are smaller than the given value.
    int value;
    int pos = -1;

    printf("Number: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return false;
    }

    for (int j = pos + 1; j < n; j++) {
        if (arr[j] >= value) {
            return false;
        }
    }

    return true;
}