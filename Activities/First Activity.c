// First Activity Given by Sir Gran

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[20];

void display(int arr[], int n);
void moveElems(int arr[], int n, int n_shift);
int getMax(int arr[], int n);
int getMin(int arr[], int n);
int getSum(int arr[], int n);
float getMean(int arr[], int n);
float getMedian(int arr[], int n);
//make a copy of the array and sort it and find the middle, do not sort the original array
void sortArray(int arr[], int n);

int main(){
    int arr[10] = {5, 2, 3, 4, 1, 6, 7, 8, 9, 10};

    int shifts;
    int choice;
    String menu[7] = {"Display", "Move", "Max", "Min", "Sum", "Mean", "Median"};
    
    do {
        for (int i = 0; i < 7; ++i){
            printf("[%2d.] %s\n", i + 1, menu[i]);
        }
        
        printf("Enter your choice (0 to EXIT): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Display List: \n");
                // call display function
                display(arr, 10);
                printf("\n");
                break;
            case 2:
                printf("Move List:\n");
                // make input for number of shifts, call move and display
                printf("Enter number of shifts: ");
                scanf("%d", &shifts);
                moveElems(arr, 10, shifts);
                display(arr, 10);
                printf("\n");
                break;
            case 3:
                printf("\nGet Max Function\n");
                // call and display Max
                int maxim = getMax(arr, 10);
                printf("Max: %d\n", maxim);
                break;
            case 4:
                printf("\nGet Min\n");
                // call and display Min
                int minim = getMin(arr, 10);
                printf("Min: %d\n", minim);
                break;
            case 5:
                printf("\nGet Sum\n");
                //call and display Sum
                int summa = getSum(arr, 10);
                printf("Sum: %d\n", summa);
                break;
            
            case 6: 
                printf("\nGet Mean\n");
                //call and display mean
                float meanie = getMean(arr, 10);
                printf("Mean: %.2f\n", meanie);
                break;
            case 7:
                printf("\nGet Median\n");
                //call and display median
                float medianer = getMedian(arr, 10);
                printf("Median: %.2f\n", medianer);
                break;
            default:
                printf("Invalid choice.");
        }
    } while (choice != 0);
    
    return 0;
}

void display(int arr[], int n){
    printf("{");
    for(int i = 0; i < n; ++i){
        printf("%d", arr[i]);
            if(i < n - 1){
                printf(",");
            }
    }
    printf("}\n");
}

void moveElems(int arr[], int n, int n_shift) {
    int elem_out;
    
    for(int j = 0; j < n_shift; ++j){
        elem_out = arr[n - 1];
        for(int i = n - 1; i > 0; --i){
            arr[i] = arr[i - 1];
        }
        arr[0] = elem_out;
    }
}

int getMax(int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; ++i){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    
    return max;
}

int getMin(int arr[], int n){
    int min = arr[0];
    
    for (int i = 0; i < n; ++i){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    
    return min;
}

int getSum(int arr[], int n){
    int sum = 0;
    
    for(int i = 0; i < n; ++i){
        sum += arr[i];
    }
    
    return sum;
}

float getMean(int arr[], int n){
    int sum = getSum(arr, n);
    
    float mean = sum / (float)n;
    
    return mean;
    
}

float getMedian(int arr[], int n){
  int *copy = malloc(sizeof(int) * n); 
    if (copy == NULL) return -1; 

    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }

    sortArray(copy, n);

    display(copy, n);

    float median;
    
    if (n % 2 != 0) {
        median = (float)copy[n / 2];
    } else {
        median = (copy[n / 2 - 1] + copy[n / 2]) / 2.0;
    }

    free(copy); 
    return median;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


