//
// Created by klause on 2020/7/10.
//

#include <stdio.h>
#include <string.h>

#define SIZE1 100
#define SIZE2 300

void show(double ar[], int n);

int main(void) {
    double data1[SIZE1], data2[SIZE2];

    for (int i = 0; i < SIZE1; ++i) {
        data1[i] = i + 1;
    }

    for (int j = 0; j < SIZE2; ++j) {
        data2[j] = j + 1001;
    }

    printf("data1:\n");
    show(data1, SIZE1);
    printf("data2:\n");
    show(data2, SIZE2);

    memcpy(data1, data2, 100 * sizeof(double));
    printf("After memcpy first 100:\n");
    show(data1, 100);

    memcpy(data1, data2 + 200, 100 * sizeof(double));
    printf("After memcpy last 100:\n");
    show(data1, 100);


    return 0;
}

void show(double ar[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%4.0f ", ar[i]);
        if (i % 10 == 9)
            printf("\n");
    }
}


