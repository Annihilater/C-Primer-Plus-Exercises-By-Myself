//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void helper(int n, int m, double [n][m]);//拷贝数组

void show(int x, int y, const double [x][y]);//打印数组

int main(void) {
    int n = 3, m = 5;
    double source[3][5] = {{1,  2,  3,  4,  5},
                           {6,  7,  8,  9,  10},
                           {11, 12, 13, 14, 15}};
    printf("The source array is:\n");
    show(n, m, source);

    helper(n, m, source);
    return 0;
}

void helper(int n, int m, double ar[n][m]) {
    double target[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            target[i][j] = ar[i][j];
        }
    }

    printf("The copy array is:\n");
    show(n, m, target);
}

void show(int x, int y, const double ar[x][y]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
