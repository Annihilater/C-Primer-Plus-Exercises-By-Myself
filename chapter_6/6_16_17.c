//
// Created by klause on 2020/6/23.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    double principal, rate;
    principal = 100.00;
    rate = 0.08;
    for (int i = 0; i < 1000000; ++i) {
        principal = principal * (1 + rate) - 10;
        if (principal <= 0) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
