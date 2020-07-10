//
// Created by klause on 2020/7/8.
//

#include <stdio.h>
#include <string.h>

#define SIZE sizeof(int) * 8

void rotate_l(int x, int y);

char *itobs(int n, char *ps);

int main(void) {
    int number = 15, n = 4;

    rotate_l(number, n);
    return 0;
}

void rotate_l(int x, int y) {
    char tmp[SIZE + 1] = {[0]='\0'};
    int len;
    char left;

    printf("Your number is: %d\nMove %d places to the left:\n", x, y);
    itobs(x, tmp);
    printf("%10s : %s\n", "original", tmp);
    len = (int) strlen(tmp);

    left = tmp[0];
    int i = 0;
    do {
        x <<= 1;
        itobs(x, tmp);
        tmp[len - 1] = left;
        left = tmp[0];
        i++;
    } while (i < y);

    printf("%10s : %s\n", "After move", tmp);
}

char *itobs(int n, char *ps) {
    const static int size = sizeof(int) * 8;

    for (int j = size - 1; j >= 0; j--, n >>= 1)
        ps[j] = (n & 01) + '0';
    ps[size] = '\0';
    return ps;
}

