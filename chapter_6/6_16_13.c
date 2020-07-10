//
// Created by klause on 2020/6/23.
//
#include <stdio.h>
#include <math.h>

int main(void) {
    int nums[8], j;
    for (int i = 0; i < 8; ++i) {
        nums[i] = (int) pow((double) 2, (double) i);
    }

    j = 0;
    do {
        printf("%d\n", nums[j]);
        j++;
    } while (j < 8);

    return 0;
}
