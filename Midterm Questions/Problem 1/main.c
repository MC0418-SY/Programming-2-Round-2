#include "functions.h"

int main(void) {
    int *arr = init_array();

    int count = populate_array(arr);
    printf("\nFinal Array: ");
    print_array(arr, count);
    free(arr);
    return 0;
}
