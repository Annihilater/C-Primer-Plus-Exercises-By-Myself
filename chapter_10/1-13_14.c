//
// Created by klause on 2020/6/27.
//


#include <stdio.h>

void input(int n, int m, double ar[n][m]);// 边长数组作为函数的形参

void show(int n, int m, double ar[n][m]);

void avg_row(int n, int m, double ar[n][m]);

void avg_all(int n, int m, double ar[n][m]);

void max(int n, int m, double ar[n][m]);

int main(void) {
    int n = 3, m = 5;
    double ar[n][m];

    input(n, m, ar);//将输入的值存到数组

    printf("\nThe enter array is:\n");
    show(n, m, ar);//打印数组

    avg_row(n, m, ar);//计算行平均值
    avg_all(n, m, ar);//计算总平均值
    max(n, m, ar);//找出最大值
    return 0;
}

void input(int n, int m, double ar[n][m]) {//输入 3x5 的数组
    for (int i = 0; i < n; ++i) {
        printf("Please input 5 double number:\n");
        for (int j = 0; j < m; ++j) {
            scanf("%lf", &ar[i][j]);// input "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"
        }
    }
}

void show(int n, int m, double ar[n][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
}

void avg_row(int n, int m, double ar[n][m]) {
    double sum, avg;

    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += ar[i][j];
        }
        avg = sum / 5;
        printf("The %d rows's numbers average is: %.2lf!\n", i + 1, avg);
    }
}

void avg_all(int n, int m, double ar[n][m]) {
    double sum, avg;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += ar[i][j];
        }
    }
    avg = sum / 15;
    printf("The average of all number is: %.2lf!\n", avg);
}

void max(int n, int m, double ar[n][m]) {
    double max;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i == 0 && j == 0) || ar[i][j] > max)
                max = ar[i][j];
        }
    }
    printf("The max of numbers is: %.2f", max);
}
