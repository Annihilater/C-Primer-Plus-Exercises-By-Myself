//
// Created by klause on 2020/6/23.
//
#include <stdio.h>
#include <math.h>

#define PRINCIPAL 100
#define RATE1 0.10
#define RATE2 0.05

int main(void) {
    double interest_1, interest_2;
    for (int i = 0; i < 100; ++i) {
        interest_1 = PRINCIPAL + PRINCIPAL * RATE1 * i;//第一种投资本息和
        interest_2 = PRINCIPAL * pow((1 + RATE2), (double) i);//第二种投资本息和
        if (interest_2 > interest_1) {
            printf("%d %.2lf %.2lf", i, interest_1, interest_2);
            break;
        }
    }


    return 0;
}

