//
// Created by klause on 2020/6/23.
//
#include <stdio.h>

int main(void) {
    double ch1[8], ch2[8];

    printf("Please input ch1: ");
    for (int i = 0; i < 8; ++i) {
        scanf("%lf", &ch1[i]);// input "1 2 3 4 5 6 7 8"
    }

    ch2[0] = ch1[0];
    for (int j = 1; j < 8; ++j) {
        ch2[j] = ch2[j - 1] + ch1[j];
    }

    for (int k = 0; k < 8; ++k) {
        printf("%f ", ch1[k]);
    }
    printf("\n");
    for (int g = 0; g < 8; ++g) {
        printf("%f ", ch2[g]);
    }
    return 0;
}
