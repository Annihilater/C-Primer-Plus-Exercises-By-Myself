//
// Created by klause on 2020/6/24.
//
#include <stdio.h>

int main(void) {
    char ch;
    char ch_pre = 0;
    int n = 0;

    printf("Please enter text to be analyzed (# to terminate): ");

    while ((ch = getchar()) != '#') {
        if (ch == 'i' && ch_pre == 'e') {
            n++;
        }
        ch_pre = ch;
    }
    printf("ei has appeared %d times.\n", n);
    return 0;
}
