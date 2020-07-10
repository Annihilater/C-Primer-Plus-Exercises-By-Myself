//
// Created by klause on 2020/6/25.
//

#include <stdio.h>

int helper(int, int, int);

int main(void) {
    int a, b, c, result;

    printf("Please enter three integer: ");

    while (scanf("%d %d %d", &a, &b, &c) != 3) {
        scanf("%s");
        printf("Please enter three integer: ");
    }

    result = helper(a, b, c);
    printf("The max number in %d %d %d is %d!", a, b, c, result);
    return 0;
}

int helper(int a, int b, int c) {
    int max = 0;
    if (a > b)
        max = a;
    else
        max = b;

    if (max < c)
        max = c;
    return max;
}
