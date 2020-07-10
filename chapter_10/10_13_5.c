//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

double helper(const double [], int);

int main(void) {
    double ar[] = {1, 2, 20, 4, 5, 6};
    double result;
    result = helper(ar, 6);
    printf("The max number - the min number = %.2f!\n", result);
    return 0;
}

// 返回整形数组最大元素与最小元素的差值
double helper(const double ar[], int n) { // n 为数组元素个数
    double max = ar[0], min = ar[0];
    for (int i = 0; i < n; ++i) {
        if (ar[i] > max) {
            max = ar[i];
        }
        if (ar[i] < min) {
            min = ar[i];
        }
    }
    return max - min;
}
