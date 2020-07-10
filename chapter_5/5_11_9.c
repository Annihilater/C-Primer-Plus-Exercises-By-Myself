//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

int Temperatures(double);

int main(void) {
    double input;
    input = 100.00;
    printf("Enter a fahrenheit to start: ");
    while (scanf("%lf", &input) == 1) {
        Temperatures(input);
        printf("Please input the fahrenheit: ");
    }
    printf("Done!");
    return 0;
}

int Temperatures(double t) {
    double const x = 5.0 / 9.0;
    double const F_TO_C = 32.0;
    double const C_TO_K = 273.16;
    double s, k;

    s = x * (t - F_TO_C);
    k = s + C_TO_K;
    printf("%.2lf ℉\n", t);
    printf("%.2lf ℃\n", s);
    printf("%.2lf K\n", k);
    return 0;
}
