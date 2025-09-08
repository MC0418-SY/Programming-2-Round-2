**Referencing and Dereferencing (Pointers)**

Description:
There are supposed to be illustrations alongside this, but just DIY for now.


// C Program to implement Boolean data type
#include <stdio.h>  // For printf()
#include <stdbool.h>  // For boolean data type (bool, true, false)

// Main Function
int main() {
    int *p;
    int *n;
    int a;
    
    a = 5;
    
    p = &a;
    
    n = p;
    
    
    printf("%d\n", &a);
    printf("%d\n", a);
    
    printf("%d\n", p); // This will print the address pointed by p
    printf("%d\n", *p); // This will print the value of the address pointed at by p
    
    printf("%d\n", n); // Thi
    printf("%d", *n);

    return 0;
}
