//
// Created by klause on 2020/6/26.
//


#include <stdio.h>

double power(double, int);

int main(void) {
    double x, xpow;
    int exp;
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2) {

        if (x == 0 && exp == 0) {
            printf("0 的 0 次幂未定义。\n");
            printf("Enter a number and the positive integer power:");
            continue;
        }

        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip --bye!\n");

    return 0;
}

double power(double n, int p) {
    double pow = 1;
    if (n == 0)
        return 0;

    if (p == 0)
        return 1;

    if (p > 0) {
        for (int i = 0; i < p; i++) {
            pow = n * power(n, p - 1);
        }
    }

    if (p < 0) {
        for (int i = 0; i < -p; i++) {
            pow = n * power(n, p + 1);
        }
        pow = 1 / pow;
    }

    return pow;
}

