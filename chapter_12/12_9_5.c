//
// Created by klause on 2020/7/1.
//

#include <stdio.h>
#include <stdlib.h>

void sort(int ar[], int n);

int main(void) {
    int n = 100;
    int ar[n];

    for (int i = 0; i < n; ++i) {
        ar[i] = rand() % 10 + 1;
    }

    printf("Your array list is:\n");
    for (int j = 1; j < n + 1; ++j) {
        printf("%2d ", ar[j - 1]);
        if ((j % 25) == 0)
            printf("\n");
    }

    sort(ar, n);

    printf("After sort, your array list is:\n");
    for (int j = 1; j < n + 1; ++j) {
        printf("%2d ", ar[j - 1]);
        if ((j % 25) == 0)
            printf("\n");
    }
    return 0;
}

void sort(int ar[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ar[i] < ar[j]) {
                tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;
            }
        }
    }
}
