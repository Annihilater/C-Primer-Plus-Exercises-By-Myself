//
// Created by klause on 2020/6/23.
//
#include <stdio.h>

int main(void) {
    int nums[8];
    for (int j = 0; j < 8; ++j) {
        scanf("%d", &nums[j]);// input "1 2 3 4 5 6 7 8"
    }
    for (int i = 0; i < 8; ++i) {
        printf("%d", nums[7 - i]);
    }
    return 0;
}

