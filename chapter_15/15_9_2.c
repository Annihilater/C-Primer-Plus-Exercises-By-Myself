//
// Created by klause on 2020/7/8.
//

// 00110101 11000110

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

void func1(char arg1[], char arg2[]);//取反

void func2(char arg1[], char arg2[]);//按位与

void func3(char arg1[], char arg2[]);//按位或

void func4(char arg1[], char arg2[]);//按位异或


int main(int argc, char *argv[]) {
    char arg1[SIZE];
    char arg2[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arg1[i] = '\0';
        arg2[i] = '\0';
    }

    if (argc != 3) {
        printf("Usage: %s wrong!\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(arg1, argv[1]);
    strcpy(arg2, argv[2]);

    func1(arg1, arg2);
    func2(arg1, arg2);
    func3(arg1, arg2);
    func4(arg1, arg2);
    return 0;
}

void func1(char arg1[], char arg2[]) {
    char arg3[SIZE], arg4[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arg3[i] = '\0';
        arg4[i] = '\0';
    }

    for (int j = 0; j < strlen(arg1); ++j) {
        if (arg1[j] == '0')
            arg3[j] = '1';
        if (arg1[j] == '1')
            arg3[j] = '0';
    }
    for (int j = 0; j < strlen(arg2); ++j) {
        if (arg2[j] == '0')
            arg4[j] = '1';
        if (arg2[j] == '1')
            arg4[j] = '0';
    }

    printf("~(%s) = %s\n", arg1, arg3);
    printf("~(%s) = %s\n", arg2, arg4);
}

void func2(char arg1[], char arg2[]) {
    char result[SIZE];
    int len = strlen(arg1) > strlen(arg2) ? (int) strlen(arg2) : (int) strlen(arg1);

    for (int j = 0; j < SIZE; ++j) {
        result[j] = '\0';
    }

    for (int i = 0; i < len; ++i) {
        if (arg1[i] == '1' && arg2[i] == '1')
            result[i] = '1';
        else
            result[i] = '0';
    }
    printf("%s & %s = %s\n", arg1, arg2, result);
}

void func3(char arg1[], char arg2[]) {
    char result[SIZE];
    int len = strlen(arg1) > strlen(arg2) ? (int) strlen(arg2) : (int) strlen(arg1);

    for (int j = 0; j < SIZE; ++j) {
        result[j] = '\0';
    }

    for (int i = 0; i < len; ++i) {
        if (arg1[i] == '1' || arg2[i] == '1')
            result[i] = '1';
        else
            result[i] = '0';
    }
    printf("%s | %s = %s\n", arg1, arg2, result);
}

void func4(char arg1[], char arg2[]) {
    char result[SIZE];
    int len = strlen(arg1) > strlen(arg2) ? (int) strlen(arg2) : (int) strlen(arg1);

    for (int j = 0; j < SIZE; ++j) {
        result[j] = '\0';
    }

    for (int i = 0; i < len; ++i) {
        if (arg1[i] != arg2[i])
            result[i] = '1';
        else
            result[i] = '0';
    }
    printf("%s ^ %s = %s\n", arg1, arg2, result);
}
