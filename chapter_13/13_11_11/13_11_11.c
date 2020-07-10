//
// Created by klause on 2020/7/3.
//

//Program arguments: o chapter_13/13_11_11/test.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

int main(int argc, char *argv[]) {
    char ch;
    char words[SIZE], *filename;
    FILE *fp;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s file wrong.", argv[0]);
        exit(EXIT_FAILURE);
    }

    ch = argv[1][0];
    filename = argv[2];

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "I couldn't open %s file.", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(words, SIZE, fp) != NULL) {
        if (strchr(words, ch)) {
            printf("%s", words);
        }
    }

    fclose(fp);
    return 0;
}
