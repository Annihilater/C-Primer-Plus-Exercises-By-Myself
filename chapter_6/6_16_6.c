//
// Created by klause on 2020/6/23.
//
#include <stdio.h>

int main(void) {
    int upper, lower, a, b, c;
    printf("Please input the lower: ");
    scanf("%d", &lower);
    printf("Please input the upper: ");
    scanf("%d", &upper);


    for (int i = 0; i < upper - lower; ++i) {
        a = lower + i;
        b = a * a;
        c = b * a;
        printf("num = %d num^2 = %d num^3 = %d\n", a, b, c);
    }
    return 0;
}
