//
// Created by klause on 2020/6/25.
//

#include <stdio.h>

double helper(double, double);

int main(void) {
    double a, b, result;

    printf("Please enter two integer: ");

    while (scanf("%lf %lf", &a, &b) != 2) {
        scanf("%s");
        printf("Please enter two integer: ");
    }

    result = helper(a, b);
    printf("%.2f + %.2f = %.2f\n", a, b, result);
    return 0;
}

double helper(double a, double b) {
    return a + b;
}
