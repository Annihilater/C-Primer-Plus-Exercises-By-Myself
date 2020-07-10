//
// Created by klause on 2020/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define SIZE 40//int 4个字节,1 个字节 8 位,共 32 位

int func(int number, int n);

char *itobs(int n, char *ps);

int main(void) {
    int number = 255;
    char tmp[SIZE];
    itobs(number, tmp);
    printf("%d is %s\n", number, tmp);

    for (int i = 1; i < strlen(tmp); ++i) {
        printf("%d 's %2d is %d.\n", number, i, func(number, i) ? 1 : 0);
    }
    return 0;
}

int func(int number, int n) {
    int result;
    char tmp[SIZE];

    for (int j = 0; j < SIZE; ++j) {
        tmp[j] = '\0';
    }
    itobs(number, tmp);

    if (tmp[strlen(tmp) - n] == '1')//字符串的索引是从左向右，位的索引是从右向左，所以是倒序
        result = 1;
    else
        result = 0;

    return result;
}

char *itobs(int n, char *ps) {
    const static int size = CHAR_BIT * sizeof(int);

    for (int j = size - 1; j >= 0; j--, n >>= 1)
        ps[j] = (n & 01) + '0';
    ps[size] = '\0';
    return ps;
}
