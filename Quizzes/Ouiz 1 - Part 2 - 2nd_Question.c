/*
  2. Write a function 
        filterEven()
      that returns a new dynamically allocated array 
      containing all the even values. This time no size, 
      the array is appended with a sentinel (-1).

      In C programming, a sentinel value is a special 
      value used to indicate the end of a sequence of data. 
      It acts as a "flag" or "dummy value" that signals 
      a termination condition. 
      
      For example,
        arr --> | 1 | 2 | 3 | 4 | 5 | -1 |
        Index     0   1   2   3   4    5

      In this example, there are 5 elements.
      ----------------------------------------
      Another example,
        arr --> | -1 |   |   |   |   |   |
        Index     0    1   2   3   4   5
        
      In this example, the array is empty.
*/

#include <stdio.h>  
#include <stdlib.h> 

//Function prototype

void filterEven();

int main() {
    
    //initialize the array
   filterEven();

    return 0;
}



void filterEven(){
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1};
    int size = sizeof(arr)/sizeof(arr[0]);
  
    int *newSize;
   int evenCount = 0;
  int i = 0;
  int index = 0;
  
 while(*arr != -1){
      
    if (arr[i] = -1){
        break;
    }
      
    if (arr[i] % 2 == 0){
      evenCount++;
    } 
    
    printf("%d ", i);
    i++;
  }

  *newSize = evenCount;
  
  int *newArr = (int*)malloc(evenCount * sizeof(int));


  while(*arr != -1){
    if (arr[i] % 2 == 0){
        newArr[index++] = arr[i];
    }
    i++;
  }
  
  newArr[index + 1] = -1;

printf("The even numbers are:  ");

  while(*arr != -1){
    printf("%d  ", arr[i]);
    i++;
  }

  
free(newArr);
  
}
