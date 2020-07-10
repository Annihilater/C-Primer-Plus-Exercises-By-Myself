//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void input(double (*)[5]);

void show(double [3][5]);

void avg_row(double [3][5]);

void avg_all(double [3][5]);

void max(double [3][5]);

int main(void) {
    double ar[3][5];

    input(ar);//将输入的值存到数组

    printf("\nThe enter array is:\n");
    show(ar);//打印数组

    avg_row(ar);//计算行平均值
    avg_all(ar);//计算总平均值
    max(ar);//找出最大值
    return 0;
}

void input(double ar[3][5]) {//输入 3x5 的数组
    for (int i = 0; i < 3; ++i) {
        printf("Please input 5 double number:\n");
        for (int j = 0; j < 5; ++j) {
            scanf("%lf", &ar[i][j]);// input "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15"
        }
    }
}

void show(double ar[3][5]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
}

void avg_row(double ar[3][5]) {
    double sum, avg;

    for (int i = 0; i < 3; ++i) {
        sum = 0;
        for (int j = 0; j < 5; ++j) {
            sum += ar[i][j];
        }
        avg = sum / 5;
        printf("The %d rows's numbers average is: %.2lf!\n", i + 1, avg);
    }
}

void avg_all(double ar[3][5]) {
    double sum, avg;
    sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            sum += ar[i][j];
        }
    }
    avg = sum / 15;
    printf("The average of all number is: %.2lf!\n", avg);
}

void max(double ar[3][5]) {
    double max;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((i == 0 && j == 0) || ar[i][j] > max)
                max = ar[i][j];
        }
    }
    printf("The max of numbers is: %.2f", max);
}
