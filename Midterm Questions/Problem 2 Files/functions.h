#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void cleanName(char str[]) {
    int size = strlen(str);
    
    for(int i = 0; i < size; ++i){
        if (islower(str[i])){
            toupper(str[i]);
        }
    }
    
    
    int isWord = 0;
    
    for (int i = 0; i < size; ++i){
        if(sentence[i] == ' '){
            isWord = 0;
        } else if(isWord != 0){
          isWord = 1;
          
          count++;
        }
    }
    
}

void cleanDOB(char str[]) {
    // Write your code here
    int size = strlen(str);
    
    for(int i = 0; i < size; ++i){
        if(str[i] == '/'){
            str[i] = '-';
        }
    }
}

bool isValidDOB(char str[]) {
    int size = strlen(str);
    
    if(strcmp("2025-10-29", str) != 0){
        return true;
    }
    return false;
}

bool isValidID(char str[]) {
   int size = strlen(str);
    int isOkay = 0;
    
    for(int i = 0; i < size; ++i){
        if(isalpha(str[i])){
            return false;
        }
    }
}

bool cleanRecords(char name[], char id[], char dob[]) {
    // Write your code here
    
    cleanName(name);
    cleanDOB(dob);
    
    if(isValidDOB(dob) && isValidID(id)){
        return true;
    }
    
    
    return false;
}
