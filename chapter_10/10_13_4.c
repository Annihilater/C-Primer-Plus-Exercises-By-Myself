//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

int helper(const double [], int);

int main(void) {
    double ar[] = {1, 2, 10, 4, 5, 6};
    int result;
    result = helper(ar, 6);
    printf("The max number's index is %d!\n", result);
    return 0;
}

// 返回整形数组的最大元素的下标
int helper(const double ar[], int n) { // n 为数组元素个数
    double max = ar[0];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (ar[i] > max) {
            max = ar[i];
            index = i;
        }
    }
    return index;
}
