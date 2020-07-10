//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void helper(int *, int);

int main(void) {
    int source[7] = {1, 2, 3, 4, 5, 6, 7};
    int *ptr = &source[2];      // 定义一个指针指向数组的第三个元素
    helper(ptr, 3);         //把指针传给函数
    return 0;
}

void helper(int *ptr, int n) {
    int target[n];
    for (int i = 0; i < n; ++i, ptr++) {    // 使用指针递增
        target[i] = *ptr;                   //直接获取指针指向位置的值，也就是源数组的第三个元素的值
        printf("%d ", target[i]);
    }
}
