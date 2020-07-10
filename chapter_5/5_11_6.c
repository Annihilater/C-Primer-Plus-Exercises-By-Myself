//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

int main(void) {
    int count, sum, days;

    count = 0;
    sum = 0;
    printf("Please input days:");
    scanf("%d", &days);

    while (count++ < days)
        sum = sum + count * count;
    printf("sum = %d\n", sum);
    return 0;
}
