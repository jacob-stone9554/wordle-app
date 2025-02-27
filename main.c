#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ResultGreen 1
#define ResultYellow 2
#define ResultRed 4

typedef char Result;
typedef Result Results[5];

int main(int, char**, Results);

Result checkChar(char, int, char*);

bool checkWord(char *guessWord, char *word);
bool isIn(char, char*);

void example_print_results(Results);


int main(int argc, char *argv[]) {
    char *guessWord, *word;
    Results results;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <guessWord> <word>\n", argv[0]);
        return -1;
    }

    guessWord = argv[1];
    word = argv[2];
    //results = checkWord(guessWord, word);

    printf("Hello World!\n");

    return 1;
}

Result checkChar(char guessChar, int idx, char *word) {
    char correctChar = word[idx];

    switch (guessChar) {
        case correctChar:
            return ResultGreen;
        default:
            if (isIn(guessChar, word)) {
                return ResultYellow;
            }
    }

    return ResultRed;
}

bool checkWord(char *guessWord, char *word) {
    int idx = 0;

    for (idx = 0; guessWord[idx] != '\0'; idx++) {
        if (guessWord[idx] != word[idx]) {
            return false;
        }
    }

    return true;
}

bool isIn(char guessChar, char *word) {
    int idx = 0;

    for (idx = 0; word[idx] != '\0'; idx++) {
        if (word[idx] == guessChar) {
            return true;
        }
    }

    return false;
}

void example_print_results(Results results) {
    int i;

    for (i = 0; i < 5; i++) {
        switch (results[i]) {
            case ResultGreen:
                printf("%s\n", "Green");
                break;
            case ResultYellow:
                printf("%s\n", "Yellow");
                break;
            case ResultRed:
                printf("%s\n", "Red");
                break;
            default:
                printf("Unknown: \n", results[i]);
                break;
        }
    }
}
