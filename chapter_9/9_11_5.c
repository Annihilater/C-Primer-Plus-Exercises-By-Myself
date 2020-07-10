//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

void larger_of(double *, double *);

int main(void) {
    double x = 2.0, y = 4.0;
    printf("old x = %.2f y = %.2f\n", x, y);
    larger_of(&x, &y);
    printf("new x = %.2f y = %.2f\n", x, y);
    return 0;
}

void larger_of(double *a, double *b) {
    double tmp;
    if (*a > *b)
        tmp = *a;
    else
        tmp = *b;

    *a = tmp;
    *b = tmp;
}
