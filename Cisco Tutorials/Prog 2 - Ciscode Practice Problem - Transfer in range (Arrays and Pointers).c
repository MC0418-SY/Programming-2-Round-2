#include <stdio.h>
#include <stdlib.h>

int* transferInRange(int* arr, int n, int low, int high, int* rangeCount);

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int low, high;
    int rangeCount;
  
    // Implementation here...
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; ++i){
      scanf("%d", &arr[i]);
    }

    printf("Input Low Range: ");
    scanf("%d", &low);
    printf("Input High Range: ");
    scanf("%d", &high);

    int *newRange = transferInRange(arr, n, low, high, &rangeCount);
    
    if(newRange == NULL){
        printf("No elements in range [%d, %d] ", low, high);
    } else {
        printf("Elements in range [%d, %d]: ", low, high);
        for(int i = 0; i < rangeCount; ++i){
            printf("%d ", newRange[i]);
        }
        
        
    }
    
    
    
    
}

int* transferInRange(int* arr, int n, int low, int high, int* rangeCount) {
    // Implementation here...
    *rangeCount = 0;
    
    
    for(int i = 0; i < n; ++i){
        if(arr[i] > low && arr[i] < high){
            (*rangeCount)++;
        }
    }
    
    if(*rangeCount == 0){
        return NULL;
    }
    
    int *newRange = (int*)malloc(sizeof(int) * (*rangeCount));
    
    int newIndex = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] > low && arr[i] < high){
            newRange[newIndex++] = arr[i];
        }
        
        
    }
    
    return newRange;
}







