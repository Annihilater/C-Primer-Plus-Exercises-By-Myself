//
// Created by klause on 2020/6/27.
//

#include <stdio.h>

void helper(int, const int [], const int[], int []);

void show(int, int []);

int main(void) {
    int n = 4;
    int ar1[] = {2, 4, 5, 8}, ar2[] = {1, 0, 4, 6}, ar3[n];
    show(n, ar1);
    show(n, ar2);
    helper(n, ar1, ar2, ar3);
    show(n, ar3);
    return 0;
}

// 将 ar1、ar2 对应的元素相加赋值给 ar3 对应的元素
void helper(int n, const int ar1[], const int ar2[], int ar3[]) {
    for (int i = 0; i < n; ++i) {
        ar3[i] = ar1[i] + ar2[i];
    }
}

void show(int n, int ar[]) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
