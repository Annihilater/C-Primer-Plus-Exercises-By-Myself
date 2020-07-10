//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void show(const double ar[], int n);    // n 是数组元素的个数

void show2(const double ar[][3], int n);    // n 是二维数组的行数

int main(void) {
    show((double[]) {8, 3, 9, 2}, 4);
    show2((double[][3]) {{8, 3, 9},
                         {5, 4, 1}}, 2);
    return 0;
}

void show(const double ar[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%.2f\n", ar[i]);
    }
}

void show2(const double ar[][3], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
}
