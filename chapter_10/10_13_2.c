//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void copy_arr(double [], const double [], int);

void copy_ptr(double [], const double [], int);

void copy_ptrs(double [], const double [], const double *);

int main(void) {
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    printf("The source array is :\n");
    for (int i = 0; i < 5; ++i) {
        printf("%.2f ", source[i]);
    }
    printf("\n");

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);

    copy_ptrs(target3, source, source + 5);
    return 0;
}

// 使用数组表示法进行拷贝
void copy_arr(double target1[], const double source[], int n) {
    printf("The target1 array is :\n");
    for (int i = 0; i < n; ++i) {
        target1[i] = source[i];
        printf("%.2f ", target1[i]);
    }
    printf("\n");
}

// 使用指针表示法和指针递增进行拷贝
void copy_ptr(double target2[], const double source[], int n) {
    printf("The target2 array is :\n");
    for (int i = 0; i < 5; source++, i++) {//指针递增
        target2[i] = *source;//指针表示法
        printf("%.2f ", target2[i]);
    }
    printf("\n");
}

void copy_ptrs(double target3[], const double source[], const double *source_end) {
    printf("The target3 array is :\n");
    for (int i = 0; source < source_end; ++i, source++) {//指针递增
        target3[i] = *source;//指针表示法
        printf("%.2f ", target3[i]);
    }
    printf("\n");
}
