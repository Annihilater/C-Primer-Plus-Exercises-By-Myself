//
// Created by klause on 2020/7/3.
//

//Program arguments: o chapter_13/13_11_8/test1.txt chapter_13/13_11_8/test2.txt chapter_13/13_11_8/test3.txt
//Program arguments: o
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

int main(int argc, char *argv[]) {
    char *filename, words[SIZE];
    FILE *fp;
    char ch;
    int ch2;
    int count;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file wrong.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ch = argv[1][0];//因为命令行的每个参数都是字符串，所以用分片取一个字符的字符串的首字母表示单个字符 "o" -> 'o'

    if (argc == 2) {
        fprintf(stdout, "Stdin from user input.\n");
        fprintf(stdout, "Please input words:\n");
        while (fscanf(stdin, "%s", words) != 1) {
            fprintf(stderr, "Input words was wrong. Please input again:\n");
        }

        count = 0;
        for (int i = 0; i < strlen(words); ++i) {
            if (words[i] == (int) ch) {
                count++;
            }
        }
        printf("Characters %c appear in %s : %d\n", ch, words, count);

    } else {
        fprintf(stdout, "Stdin from from.\n");
        for (int i = 2; i < argc; ++i) {
            count = 0;
            filename = argv[i];

            if ((fp = fopen(filename, "r")) == NULL) {
                fprintf(stderr, "I couldn't open %s file.\n", filename);
                exit(EXIT_FAILURE);
            }

            while ((ch2 = getc(fp)) != EOF) {
                if (ch2 == (int) ch) {
                    count++;
                }
            }
            printf("Characters %c appear in the file %s : %d\n", ch, filename, count);
            fclose(fp);
        }
    }

    return 0;
}

