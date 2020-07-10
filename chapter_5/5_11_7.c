//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

void func(double);

int main(void) {
    double n;
    printf("Please input a double float number:");
    scanf("%lf", &n);
    func(n);
    return 0;
}

void func(double n) {
    double result;
    result = n * n * n;
    printf("n * n * n = %.2lf ", result);
}
