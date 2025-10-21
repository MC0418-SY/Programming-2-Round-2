#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 5;
    
    int arr[] = {11, 22, 32, 44, 55};
    //This is how you set the elements in a STATIC array
    
    for(int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if(i < size - 1) {
            printf(", ");
        }
    }
    
    printf("\n");
    
    
    int *newArr = (int*)malloc(sizeof(int) * size);
    
    //This is you set the elements in a DYNAMIC array
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    for(int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if(i < size - 1) {
            printf(", ");
        }
    }
    
    return 0;
}
