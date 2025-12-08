#include <stdio.h>

void transferPosNeg(int* arr, int n, int* posCount, int* negCount, int* posNum, int* negNum);

int main() {
    int n, negCount, posCount;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    int *posNum, *negNum;
    
    transferPosNeg(arr, n, &posCount, &negCount, posNum, negNum);
    
    return 0;
}

void transferPosNeg(int* arr, int n, int* posCount, int* negCount, int* posNum, int* negNum) {
    *posCount = 0;
    *negCount = 0;
    
    // First pass: count and print positive numbers
    printf("Positive numbers: ");
    for(int i = 0; i < n; ++i){
        if(arr[i] > 0){
            printf("%d ", arr[i]);
            (*posCount)++;
        }
    }
    if(*posCount == 0) printf("No positive numbers");
    
    printf("\n");
    
    // Second pass: count and print negative numbers
    printf("Negative numbers: ");
    for(int i = 0; i < n; ++i){
        if(arr[i] < 0){
            printf("%d ", arr[i]);
            (*negCount)++;
        }
    }
    if(*negCount == 0) printf("No negative numbers");
}
