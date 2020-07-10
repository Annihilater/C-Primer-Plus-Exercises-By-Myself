//
// Created by klause on 2020/7/8.
//
//Program arguments: 00110101
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n = 0;

    if (argc != 2) {
        printf("Usage: %s wrong!\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < strlen(argv[1]); ++i) {
        if (argv[1][i] == '1')
            n++;
    }

    printf("%s : %d", argv[1], n);
    return 0;
}
