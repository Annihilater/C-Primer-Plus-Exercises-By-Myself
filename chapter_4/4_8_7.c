//
// Created by klause on 2020/6/19.
//
#include <stdio.h>
#include <float.h>

int main(void) {
    double a;
    float b;
    a = 1.0 / 3.0;
    b = 1.0 / 3.0;
    printf("a=%.6f b=%.6f\n", a, b);
    printf("a=%.12f b=%.12f\n", a, b);
    printf("a=%.16f b=%.16f\n", a, b);
    printf("a=%.20f b=%.20f\n", a, b);
    printf("%d\n", FLT_DIG);
    printf("%d\n", DBL_DIG);
    return 0;
}
