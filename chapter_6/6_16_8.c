//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    float first, second, result;
    printf("Please input first float num and second num: ");
    while (scanf("%f %f", &first, &second) == 2) {
        result = (first - second) / (first * second);
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", first, second, first, second, result);
        printf("Enter next couple value: ");
    }
    printf("Done!");
    return 0;
}
