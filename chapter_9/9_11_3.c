//
// Created by klause on 2020/6/26.
//
#include <stdio.h>

void helper(char, int, int);

int main(void) {
    helper('$', 21, 6);
    return 0;
}

void helper(char ch, int m, int n) {
    int x;// 每行的字符数
    if (m % n == 0)
        x = m / n;
    else
        x = m / n + 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x; ++j) {
            if ((i == n - 1) && j >= (m - (n - 1) * x)) {
                continue;
            } else
                printf("%c", ch);
        }
        printf("\n");
    }
}
