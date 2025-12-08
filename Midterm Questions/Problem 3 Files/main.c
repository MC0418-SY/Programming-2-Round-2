#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    char sentence[1000];
    printf("Input : ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; // Remove newline
    rearrangeWords(sentence);
    printf("Result: %s", sentence);
    return 0;
}
