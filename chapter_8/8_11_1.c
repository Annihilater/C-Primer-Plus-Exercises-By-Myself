//
// Created by klause on 2020/6/25.
//
#include <stdio.h>

int main(void) {
    int ch, n = 0;
    while ((ch = getchar()) != '#') {
        n++;
    }
    printf("%d", n);
    return 0;
}
