# [CIS 1201 MIDTERM #1]Dynamic Insertion with Single Duplication

by Oscar Iii Cabarron
<hr>
**Program Description:** This program accepts user input up to an initial count of 8. It dynamically creates an array with that size and allows the user to input integers up to that size to populate the array. If the input is invalid the program prompts again, if the input already exists the **1st instance of the duplicate is accepted and the size of the array dynamically increased by 1.** Any succeeding duplicates of the same number are invalid. Every valid input is inserted in the array in its proper place in ascending order. The current array is then printed. The program ends after printing the entire final array.

**Task:** Given the pre-existing code, complete the functions to make the program work as intended.

1. **int* init_array(void)** - creates and initializes the dynamic array and assigns it to the existing pointer.
2. **void insert_sort(int *arr, int count, int value) -** accepts the array, the current count, and the value to be inserted. Enacts insertion sort to insert the value in its proper place in the array
3. **void print_array(const int *arr, int count)-** _ALREADY PROVIDED_. Prints the current array
4. **int populate_array(int *arr) -** accepts the array and asks for user's integer input, rejecting invalids then inserts each valid unique integer into the sorted array through the appropriate function and prints the array through the print function after every successful insertion. This returns the last value of count. **Note:** The program should accept only 1 duplicate of any number, for every duplicate increase the size of the array by 1.

Sample Output 1

```
Enter integer #1: 1
Current array: 1
Enter integer #2: 2
Current array: 1 2
Enter integer #3: 3
Current array: 1 2 3
Enter integer #4: 4
Current array: 1 2 3 4
Enter integer #5: 5
Current array: 1 2 3 4 5
Enter integer #6: 6
Current array: 1 2 3 4 5 6
Enter integer #7: 6
duplicate accepted, array size increased to 9
Current array: 1 2 3 4 5 6 6
Enter integer #8: 7
Current array: 1 2 3 4 5 6 6 7
Enter integer #9: 8
Current array: 1 2 3 4 5 6 6 7 8

Final Array: 1 2 3 4 5 6 6 7 8
```

Sample Output 2

```
Enter integer #1: 5
Current array: 5
Enter integer #2: 5
duplicate accepted, array size increased to 9
Current array: 5 5
Enter integer #3: 1
Current array: 1 5 5
Enter integer #4: 2
Current array: 1 2 5 5
Enter integer #5: 6
Current array: 1 2 5 5 6
Enter integer #6: 6
duplicate accepted, array size increased to 10
Current array: 1 2 5 5 6 6
Enter integer #7: 3
Current array: 1 2 3 5 5 6 6
Enter integer #8: 4
Current array: 1 2 3 4 5 5 6 6
Enter integer #9: 7
Current array: 1 2 3 4 5 5 6 6 7
Enter integer #10: 9
Current array: 1 2 3 4 5 5 6 6 7 9

Final Array: 1 2 3 4 5 5 6 6 7 9
```

Sample Output 3

```
Enter integer #1: 10
Current array: 10
Enter integer #2: 1
Current array: 1 10
Enter integer #3: 2
Current array: 1 2 10
Enter integer #4: 3
Current array: 1 2 3 10
Enter integer #5: 7
Current array: 1 2 3 7 10
Enter integer #6: 9
Current array: 1 2 3 7 9 10
Enter integer #7: 9
duplicate accepted, array size increased to 9
Current array: 1 2 3 7 9 9 10
Enter integer #8: -1
Current array: -1 1 2 3 7 9 9 10
Enter integer #9: -1
duplicate accepted, array size increased to 10
Current array: -1 -1 1 2 3 7 9 9 10
Enter integer #10: -1
The integer -1 already appears twice. Third instance rejected. Please enter a different value.
Enter integer #10: 8
Current array: -1 -1 1 2 3 7 8 9 9 10

Final Array: -1 -1 1 2 3 7 8 9 9 10
```
