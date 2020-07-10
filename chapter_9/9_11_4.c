//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

double helper(double, double);

int main(void) {
    double r;
    r = helper(2.0, 4.0);
    printf("%.2f", r);
    return 0;
}

double helper(double a, double b) {
    return 1 / ((1 / a + 1 / b) / 2);
}
