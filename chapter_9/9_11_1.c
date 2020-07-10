//
// Created by klause on 2020/6/26.
//

#include <stdio.h>

double min(double, double);

int main(void) {
    double a = 1, b = 7, result;
    result = min(a, b);
    printf("The min number of %.2f and %.2f is %.2f! ", a, b, result);
    return 0;
}

double min(double x, double y) {
    return (x > y) ? y : x;
}
