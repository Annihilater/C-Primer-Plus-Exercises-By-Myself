//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void helper(double [], int);

int main(void) {
    double ar[] = {1, 2, 20, 4, 5, 6};

    printf("The old array is:\n");
    for (int i = 0; i < 6; ++i) {
        printf("%.2f ", ar[i]);
    }

    helper(ar, 6);

    printf("\nThe new array is:\n");
    for (int i = 0; i < 6; ++i) {
        printf("%.2f ", ar[i]);
    }

    return 0;
}

// 倒序排序数组：冒泡排序法
void helper(double ar[], int n) { // n 为数组元素个数
    if (n != 0 && n != 1) {//长度为 1 和 0 的数组不需要处理
        double tmp;
        int changed = 0;

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n - i - 1; ++j) {
                if (ar[j] < ar[j + 1]) {
                    tmp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = tmp;
                    changed = 1;
                }
            }

            if (changed == 0)//如果遍历一遍没有发生交换说明，数组是倒序的，可以不进行之后的循环
                break;
        }
    }
}
