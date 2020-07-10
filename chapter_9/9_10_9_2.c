//
// Created by klause on 2020/6/25.
//

#include <stdio.h>

int helper(int, int);

int main(void) {
    int a = 1, b = 10, result;
    printf("Please enter an integer between %d and %d: ", a, b);
    result = helper(a, b);
    printf("%d", result);
    return 0;
}

int helper(int low, int up) {
    int n;
    while (1) {
        if (scanf("%d", &n) == 1) {
            if (n >= low && n <= up)
                return n;
            else
                printf("Please enter an integer between %d and %d: ", low, up);
            continue;
        } else
            return 4;
    }
}
/*
 * 用户输入：上限下限
 * 超出上下限，提示用户重新输入
 * 在范围内，返回整数
 * 如果输入非整数字符，返回 4
 */
