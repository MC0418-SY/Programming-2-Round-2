#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "function.h"

int main() {
    char name[100] = "";
    char id[50] = "";
    char dob[11] = "";
    bool isValid;

    printf("Input user details:\n");
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline
    printf("ID  : ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0; // Remove newline
    printf("DOB : ");
    fgets(dob, sizeof(dob), stdin);
    dob[strcspn(dob, "\n")] = 0; // Remove newline

    isValid = cleanRecords(name, id, dob);

    printf("\nCleaned result:\n");
    printf("Name: %s\n", name);
    printf("ID  : %s\n", id);
    printf("DOB : %s\n", dob);
    printf("Record is %s!\n", isValid ? "VALID" : "INVALID");

    return 0;
}
