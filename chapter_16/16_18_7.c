//
// Created by klause on 2020/7/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);

double *new_d_array(int n, ...);

int main(void) {
    double *p1;
    double *p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);

    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

double *new_d_array(int n, ...) {
    double *arr = (double *) malloc(n * sizeof(double));

    va_list ap;                         //初始化一个接收参数的容器
    va_start(ap, n);                    //将参数放进容器

    for (int i = 0; i < n; ++i)
        arr[i] = va_arg(ap, double);    //安装参数顺序, 一次取出一个参数, 参数类型要对应好

    va_end(ap);                         //清理工作: 释放容器
    return arr;
}

void show_array(const double ar[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%10.2f ", ar[i]);
    }
    printf("\n");
}

