# [CIS 1201 MIDTERM #3] English is fun

by Sabrinah Yonell Yap

You are hired as an English teacher to automate the rearranging of words in a given sentence into dictionary order (i.e. alphabetical order).

The partially completed program performs the following in order:

1. Ask for user input a string representing a sentence  
    1. Assume the input will contain either lowercase letters or spaces - no punctuations.
2. Pass the string to a function `void rearrangeWords(char sentence[])` for modification
3. Displays the result in the console.

Tasks to do inside the function `void rearrangeWords(char sentence[])`:

1. Determine the word count  
    1. To be handled by `int getWordCount(char sentence[])`
    2. Assume all words are separated by a single space only.
2. Create three dynamically allocated arrays  
    1. First with an array of n integers initialized with numbers 0, 1, 2, ... to n-1 to store the index position of each word  
        1. To be handled by `int* createSequence(int num)`
    2. Second with an array of n integers initialized with values storing the indices of the first letter of each word in the sentence  
        1. To be handled by `int* getStartingIndices(char sentence[], int wordCount)`
    3. Third with an array of letter counts for each word in the sentence  
        1. To be handled by `int* getLetterCounts(char sentence[], int wordCount)`
3. Use the **three dynamic arrays** above as support in **rearranging the words** in the given **sentence**.  
    1. Create an auxillary function called `int compareWords(char word1[], char word2[], int len1, int len2)` that helps compare the first `n` characters of both strings. Here, `n` represents the smaller value between `len1` and `len2`. If both strings share the same starting words and one string is a substring of the other, we treat the shorter string as the first in order.  
        1. Return `-1` if the first string is the first in order `(word1 < word2)`
        2. Return `0` if both strings are equal `(word1 == word2)`
        3. Return `1` if the second string should go first in order `(word1 > word2)`
    2. Create a separate string initialized with `'\0'` characters to store the partial result, then copy the complete result back to the original string before the function terminates.  
        1. Use `strncat()`with parameters: (1) destination string, (2) source string, (3) number of characters from source string

**NOTE: Strictly no usage of tokenization functions (e.g. strtok()) or usage of 2D arrays (e.g. array of strings) allowed! Submissions violating this constraint will be given a zero (0) for this problem.**

Sample Output 1

```
Input : this is the best exam ever
Result: best ever exam is the this
```

Sample Output 2

```
Input : bb ccc dddd a ffffff eeeee
Result: a bb ccc dddd eeeee ffffff
```

Sample Output 3

```
Input : testabc testing test tests
Result: test testabc testing tests
```
