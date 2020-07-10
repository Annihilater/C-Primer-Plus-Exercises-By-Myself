//
// Created by klause on 2020/7/7.
//

#include <stdio.h>
#include <math.h>

#define SIZE 100

void show(double source[], int n);

void transform(double source[], double target[], int n, double (*p)(double m));

double func1(double k);

double func2(double m);

int main(void) {
    double source[SIZE], target[SIZE];
    double (*p1)(double k);
    double (*p2)(double m);
    double (*p3)(double x);
    double (*p4)(double y);

    for (int i = 0; i < SIZE; ++i) {
        source[i] = (double) (i + 1);
    }

    printf("Source Array:\n");
    show(source, SIZE);

    p1 = func1;
    transform(source, target, SIZE, p1);
    printf("\nFunc1 Target Array:\n");
    show(target, SIZE);

    p2 = func2;
    transform(source, target, SIZE, p2);
    printf("\nFunc2 Target Array:\n");
    show(target, SIZE);

    p3 = &sin;
    transform(source, target, SIZE, p3);
    printf("\nSin Target Array:\n");
    show(target, SIZE);

    p4 = cos;
    transform(source, target, SIZE, p4);
    printf("\nCos Target Array:\n");
    show(target, SIZE);

    return 0;
}

void show(double source[], int n) {
    for (int j = 0; j < n; ++j) {
        printf("%6.2f ", source[j]);
        if ((j + 1) % 10 == 0)
            printf("\n");
    }
}

void transform(double source[], double target[], int n, double (*p)(double m)) {
    for (int i = 0; i < n; ++i) {
        target[i] = (double) p((double) source[i]);
    }
}

double func1(double k) {
    return (float) (2 * k);
}

double func2(double m) {
    return (float) (3 * m);
}
