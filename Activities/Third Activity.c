// Third Activity of Sir Gran
// Coded By: Maria Cheyenne Gilbero, Nicole Louis Heredia

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

void insertFront(int arr[], int *n, int item);
void insertRear(int arr[], int *n, int item);
void insertAt(int arr[], int *n, int item, int index);
void deleteFront(int arr[], int *n);
void deleteRear(int arr[], int *n);
void deleteItem(int arr[], int *n, int item);
void deleteAllItem(int arr[], int *n, int item);
//deletes all occurrences of an item

bool isFound(int arr[], int n, int key);
//searches for the item in the collection

int searchItem (int arr[], int n, int key);

void display (int arr[], int n);
//*n is for modifying the count and the n is just for display since no changes need to be made in the function

int main(){
    int myArr[MAX];
    int count = 0;

    
    display(myArr, count);
    insertFront(myArr, &count, 10);
    display(myArr, count);
    insertFront(myArr, &count, 20);
    display(myArr, count);
    insertFront(myArr, &count, 30);
    display(myArr, count);
    insertFront(myArr, &count, 40);
    display(myArr, count);
    
 
    insertAt(myArr, &count, 100, 3);
    display(myArr, count);
    insertAt(myArr, &count, 150, 1);
    display(myArr, count);
    insertAt(myArr, &count, 45, 6);
    display(myArr, count);
 
    insertRear(myArr, &count, 10);
    display(myArr, count);
    insertAt(myArr, &count, 100, 8);
    display(myArr, count);
    
    deleteAllItem(myArr, &count, 100);
    display(myArr, count);
    
    
    int num = 10;
    printf("\nYo! Where %d at? I'm tryna find %d!\n", num, num);
    
    if(isFound(myArr, count, num)){
        printf("Ayo! I found %d!", num);
    } else {
        printf("Bruh.");
    }
    
    int searched = searchItem(myArr, count, num);
    
    printf("\nWassup! I searched for %d and found it at index %d!", num, searched);

    return 0;
}

void display (int arr[], int n){
    printf("{");
        for (int i = 0; i < n; ++i){
            printf("%d", arr[i]);
            if(i < n - 1){
                printf(",");
            }
        }
    printf("}");
    printf("\n");
}

void insertFront(int arr[], int *n, int item) {
    if (MAX > *n){
        for (int i = *n; i > 0; --i){
            arr[i] = arr[i - 1];
        }
        arr[0] = item;
        (*n)++;
    }
}

void insertRear(int arr[], int *n, int item){
    arr[*n] = item;
    (*n)++;
}

void insertAt(int arr[], int *n, int item, int index){
    for (int i = *n; i > index; --i){
        arr[i] = arr[i - 1];
    }
    arr[index] = item;
    (*n)++;
    
}

void deleteFront(int arr[], int *n){
    for (int i = *n; i < 0; i++){
            arr[i] = arr[i + 1];
    }
    (*n)--;
}

void deleteRear(int arr[], int *n){
    (*n)--;
}


void deleteItem(int arr[], int *n, int item){
    for (int i = 0; i < *n; i++){
        if(arr[i] == item){
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            break;
        }
    }
    (*n)--;
}


void deleteAllItem(int arr[], int *n, int item){
    for (int i = 0; i < *n; i++){
        if(arr[i] == item){
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
           (*n)--;
        } else {
            i++; 
        }
    }
    
}

bool isFound(int arr[], int n, int key){
    for(int i = 0; i < n; ++i){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
}


int searchItem (int arr[], int n, int key){
    int found;
    for(int i = 0; i < n; ++i){
        if (arr[i] == key){
            found = i;
            break;
        }
    }
    return found;
}


