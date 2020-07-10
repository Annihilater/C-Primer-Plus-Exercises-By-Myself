//
// Created by klause on 2020/6/25.
//
#include <stdio.h>

int helper(int, int);

int main(void) {
    int a, b, result;

    printf("Please enter two integer: ");

    while (scanf("%d %d", &a, &b) != 2) {
        scanf("%s");
        printf("Please enter two integer: ");
    }

    result = helper(a, b);
    printf("%d + %d = %d\n", a, b, result);
    return 0;
}

int helper(int a, int b) {
    return a + b;
}
