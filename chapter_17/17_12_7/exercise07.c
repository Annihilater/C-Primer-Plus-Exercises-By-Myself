//
// Created by klause on 2020/7/15.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"

void printMenu(void);

int getOption(void);

void printWordCount(Item item);

char *toLowercase(char *string);

char *get(char *string, int n);

int main(int argc, char *argv[]) {//Program arguments: chapter_17/17_12_7/test.txt

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    char tmp[WORD_SIZE];
    Tree words;
    Tree *ptree = InitializeTree(&words);
    while (fscanf(fp, "%s", tmp) == 1) {
        toLowercase(tmp);
        if (!AddWord(tmp, ptree)) {
            fprintf(stderr, "Could not add word to search tree.\n");
            exit(1);
        }
    }

    int ch;
    char word[WORD_SIZE];
    while ((ch = getOption()) != 'q') {
        if (ch == 'a') {
            ApplyToAll(ptree, printWordCount);
        } else if (ch == 'b') {
            printf("Enter a word to search for: ");
            get(word, WORD_SIZE);
            ApplyToNode(word, ptree, printWordCount);
        }
        puts("");
    }

    DeleteAll(ptree);
    puts("Bye.");
}

void printMenu(void) {
    puts("Options:");
    puts("a) List all words with their respective counts");
    puts("b) Search for a word");
    puts("q) Quit");
    printf("Select an option: ");
}

int getOption(void) {
    printMenu();
    int opt;
    while ((opt = getchar()) != 'a' && opt != 'b' && opt != 'q') {
        puts("That is not a valid option. Try again.");
        printf("Select an option: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    return opt;
}

void printWordCount(Item item) {
    printf("%15s: %3d\n", item.word, item.count);
}

char *toLowercase(char *string) {
    char *ret_val = string;
    for (; *string != '\0'; string++) {
        *string = (char) tolower(*string);
    }
    return ret_val;
}

char *get(char *string, int n) {
    // wrapper for fgets - read from stdin and replace
    // first newline with null character

    char *ret_val = fgets(string, n, stdin);

    for (; *string != '\0'; string++) {
        if (*string == '\n') {
            *string = '\0';
            break;
        }
    }
    return ret_val;
}
