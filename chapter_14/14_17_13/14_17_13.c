//
// Created by klause on 2020/7/6.
//

#include <stdio.h>

double func1(double n, double m);

double func2(double n, double m);

double func3(double n, double m);

double func4(double n, double m);

int main(void) {
    double (*ar[4])(double, double) ={func1, func2, func3, func4};
    double x;
    x = ar[1](10.0, 2.5);
    printf("%.2f", x);
    return 0;
}

double func1(double n, double m) {
    return n + m;
}

double func2(double n, double m) {
    return n + m;
}

double func3(double n, double m) {
    return n + m;
}

double func4(double n, double m) {
    return n + m;
}

