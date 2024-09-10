#include <stdio.h>
#include <string.h>

void findLongestShortestWord(char *str) {
    int length = strlen(str);
    char longestWord[500];
    char shortestWord[500];
    char word[500];
    int wordLength = 0;
    int longestLength = 0;
    int shortestLength = length;
    int i, j;
    
    for (i = 0, j = 0; i <= length; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            word[j] = '\0';
            j = 0;
            wordLength = strlen(word);
            
            if (wordLength > longestLength) {
                longestLength = wordLength;
                strcpy(longestWord, word);
            }
            
            if (wordLength < shortestLength) {
                shortestLength = wordLength;
                strcpy(shortestWord, word);
            }
        } else {
            word[j++] = str[i];
        }
    }
    
    printf("%s\n", longestWord);
    printf("%s\n", shortestWord);
}

int main() {
    char str[500];
    gets(str);
    
    findLongestShortestWord(str);
    
    return 0;
}