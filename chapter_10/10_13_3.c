//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

int helper(const int [], int);

int main(void) {
    int ar[] = {1, 2, 3, 4, 5}, result;
    result = helper(ar, 5);
    printf("The max number is %d!\n", result);
    return 0;
}

// 返回整形数组的最大元素
int helper(const int ar[], int n) { // n 为数组元素个数
    int max = ar[0];
    for (int i = 0; i < n; ++i) {
        if (ar[i] > max)
            max = ar[i];
    }
    return max;
}
