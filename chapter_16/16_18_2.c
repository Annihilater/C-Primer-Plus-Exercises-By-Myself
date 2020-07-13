//
// Created by klause on 2020/7/10.
//

#include <stdio.h>

#define HARMONIC_MEAN(X, Y) (1.0/(1.0/(X) + 1.0/(Y)))

int main(void) {
    double n = 10, m = 10;
    printf("%.2f and %.2f Harmonic mean is %.2f", n, m, HARMONIC_MEAN(n, m));
    return 0;
}
