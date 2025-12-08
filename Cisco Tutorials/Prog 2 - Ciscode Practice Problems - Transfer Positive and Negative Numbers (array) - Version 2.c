#include <stdio.h>
#include <stdlib.h>

void transferPosNeg(int* arr, int n, int* posNum, int* negNum, int* posCount, int* negCount);

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *posNum = (int*)malloc(n * sizeof(int));
    int *negNum = (int*)malloc(n * sizeof(int));
    if (posNum == NULL || negNum == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int posCount, negCount;
    transferPosNeg(arr, n, posNum, negNum, &posCount, &negCount);

   
    if (posCount == 0) {
        printf("No positive numbers");
    } else {
       printf("Positive numbers: ");
        for (int i = 0; i < posCount; i++) {
            printf("%d ", posNum[i]);
        }
    }
    printf("\n");

    
    if (negCount == 0) {
        printf("No negative numbers");
    } else {
      printf("Negative numbers: ");
        for (int i = 0; i < negCount; i++) {
            printf("%d ", negNum[i]);
        }
    }
    printf("\n");

    free(posNum);
    free(negNum);

    return 0;
}

void transferPosNeg(int* arr, int n, int* posNum, int* negNum, int* posCount, int* negCount) {
    *posCount = 0;
    *negCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            posNum[*posCount] = arr[i];
            (*posCount)++;
        } else if (arr[i] < 0) {
            negNum[*negCount] = arr[i];
            (*negCount)++;
        }
    }
}
