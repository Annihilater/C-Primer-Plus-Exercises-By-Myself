//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

int main(void) {
    float input;
    scanf("%f", &input);
    printf("The input is %.1f or %.1e.\n", input, input);
    printf("The input is %+.3f or %.3E.\n", input, input);
    return 0;
}
