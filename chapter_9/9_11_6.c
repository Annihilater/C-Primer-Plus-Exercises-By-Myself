//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

void helper(double *, double *, double *);

int main(void) {
    double a = 2.0, b = 1.0, c = 3.0;
    printf("old a = %.2f b = %.2f c = %.2f\n", a, b, c);
    helper(&a, &b, &c);
    printf("new a = %.2f b = %.2f c = %.2f\n", a, b, c);
    return 0;
}

void helper(double *a, double *b, double *c) {
    double tmp;
    if (*a > *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if (*b > *c) {
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
    if (*a > *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
