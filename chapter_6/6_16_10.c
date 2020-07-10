//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    int upper, lower, result;
    printf("Please input lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);
    while (lower < upper) {
        result = 0;
        for (int i = lower; i <= upper; ++i) {
            result += i * i;
        }
        printf("The sum of the squares from %d to %d is %d\n", lower * lower, upper * upper, result);

        printf("Enter next set of limits:");
        scanf("%d %d", &lower, &upper);
    }
    return 0;
}
