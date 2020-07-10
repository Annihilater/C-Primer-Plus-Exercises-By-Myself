//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void helper(double [][4], int, int);

int main(void) {
    double source[2][4] = {{1, 2, 3, 4},
                           {5, 6, 7, 8}};

    printf("The source array is:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%.2f ", source[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    helper(source, 2, 4);
    return 0;
}

void helper(double ar[2][4], int n, int m) {
    double target[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            target[i][j] = ar[i][j];
        }
    }
    printf("The target array is:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%.2f ", target[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
