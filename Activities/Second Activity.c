// Second Activity of Sir Gran 
// Coded by: Nicole Louis Heredia

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef char String[20];


void display (int arr[], int n);
void moveElems(int arr[], int n, int n_shift);
float getMax (int arr[], int n);
float getMin (int arr[], int n);
float getSum (int arr[], int n);
float getMean (int arr[], int n);
float getMedian (int arr[], int n);
int *getMode(int arr[], int n, int *ret_n);
void populate(int arr[], int n);

//make a copy of the array, and find the median, and sort it out
void sortArray(int arr[], int n);



int main(){
srand(time(NULL)); // This line is for generating random elements for the array
// int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int arr[11] = {1, 7, 2, 2, 3, 7, 3, 1, 7, 2, 3};
int arr[11];
int n = 11;
populate(arr, n);



int ret_n = 0;
int n_shift;
float ans;


// int A = {1, 3, 2, 5, 5, 6, 7, 8, 8, 8};
// arr = malloc(sizeof(int) * n);


int choice;
String menu[8] = {"Display", "Move", "Max", "Min", "Sum", "Mean", "Median", "Mode"};
do{
    printf("\n");
    for(int i = 0; i < 8; i++){
        printf("[%2d.] %s\n", i+1, menu[i]);
    }
    
    printf("Enter your choice (0 to EXIT): ");
    scanf("%d", &choice);
    
    switch (choice){
        case 0:
            
            
            break;
        case 1:
            printf("Display List\n");
            //call Display
            display (arr, n);
            
            break;
        case 2:
            printf("Move List\n");
            //make input shift for number of shift, call move and display
            printf("Enter number of shifts: ");
            scanf(" %d", &n_shift);
            
            moveElems(arr, n, n_shift);
            display (arr, n);
            break;
                
        case 3:
            printf("Get Max\n");
            //call and display max
            
            ans = getMax (arr, n);
            
            printf("%.2f\n", ans);
            
            break;
        
        case 4:
            printf("Get Min\n");
            //call and display min
            ans = getMin (arr, n);
            printf("%.2f\n", ans);
            break;
            
        case 5:
            printf("Get Sum\n");
            //call and display sum
            ans = getSum (arr, n);
            printf("%.2f\n", ans);
            break;
            
        case 6:
            printf("Get Mean\n");
            //call and display mean or average
            ans = getMean (arr, n);
            printf("%.2f\n", ans);
            break;
            
        case 7:
            printf("Get Median\n");
            //call and display median
            ans = getMedian (arr, n);
            printf("%.2f\n", ans);
            break;

        case 8:
            printf("Get Mode\n");

            int *mode = getMode(arr, n, &ret_n);
            
            display(mode, ret_n);
            
        
            break;
        
        
        default:
        printf("invalid choice!\n");
        break;
        
    }
    
}  while (choice != 0); 
    
    
    return 0;
}


 
void display (int arr[], int n){
    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i < n-1){
            printf(", ");
        }
    }
    
    printf("}\n");
}


void moveElems(int arr[], int n, int n_shift){
    int x = arr[0];
    
    for(int j = 0; j < n_shift; j++){
        x = arr[n-1];
        for(int i = n-1; i > 0; --i){
            arr[i] = arr[i-1];
        }
    
    arr[0] = x;
    }
    
}


float getMax (int arr[], int n){
    float max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
    
}
float getMin (int arr[], int n){
    float min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}


float getSum (int arr[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    return sum;
    
}
float getMean (int arr[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    float mean = sum/n;
    
    return mean;
}


float getMedian (int arr[], int n){
    
    int temp[50];

    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }
    
    sortArray(temp, n);
    
    if(n%2 == 0){
        return (temp[n/2 - 1] + temp[n/2]) / 2.0;
    }
    else{
        return (temp[n/2]);
    }

}



void sortArray(int arr[], int n){
    
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            
            if(arr[j] > arr[j+1]){
            int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    
}


void populate (int arr[], int n){
    //This function is for populating the array
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 11 + 1;
    }
}



int *getMode(int arr[], int n, int *ret_n){
    

int * freqList = malloc(sizeof(int) * n);

// int freqNum;
int highCount = 0;

 *ret_n = 0;
  
  for(int i = 0; i < n; i++) {
       int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
                
            }
        }
        if(count > highCount){
            highCount = count;
            *ret_n = 0;
            
            freqList[(*ret_n)++] = arr[i];
        }
        else if(count == highCount){
            
            int alreadyAdded = 0;
            
            
            for(int k = 0; k < *ret_n; k++){
                if(freqList[k] == arr[i]){
                    alreadyAdded = 1;
                    
                  
                }
            }
            
        if(!alreadyAdded){
            freqList[(*ret_n)++] = arr[i];
        }
        }
         
    }

    return freqList;
  free(freqList);  
  

}
