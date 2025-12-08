#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getWordCount(char sentence[]) {
    int size = strlen(sentence);
    int count = 0;
    int isWord = 0;
    
    for (int i = 0; i < size; ++i){
        if(sentence[i] == ' '){
            isWord = 0;
        } else if(isWord != 0){
           isWord = 1;
           count++;
        }
    }
    
    return count;
}

int* createSequence(int num) {
    int *sequence = malloc(sizeof(int) * num);
    
    for (int i = 0; i < num - 1; ++i){
        sequence[i] = i;
    }
    
    return sequence;
}

int* getStartingIndices(char sentence[], int wordCount) {
    int *indices = malloc(sizeof(int) * wordCount);
    
    for (int i = 0; i < wordCount; ++i){
        for (int j = 0; j < wordCount; ++i){
            if(sentence[j+1] != ' '){
                wordCount++;
            }
        }
        
    }
    
}

int* getLetterCounts(char sentence[], int wordCount) {
    for (int i = 0; i < wordCount; ++i){
        for (int j = 0; j < wordCount; ++i){
            if(sentence[j+1] != ' '){
                wordCount++;
            }
        }
        
    }
}

int compareWords(char word1[], char word2[], int len1, int len2) {
    // Write your code here
}


void rearrangeWords(char sentence[]) {
    int wordCount = getWordCount(sentence);
    if (wordCount == 0) return;

    int* sequence = createSequence(wordCount);
    int* startingIndices = getStartingIndices(sentence, wordCount);
    int* letterCounts = getLetterCounts(sentence, wordCount);

    // Write the code for rearranging the words here

    char result[1000] = "";
    // Write the code for building the sentence with sorted words here

    // Copy result back
    strcpy(sentence, result);

    // Cleanup
    free(sequence);
    free(startingIndices);
    free(letterCounts);
}
