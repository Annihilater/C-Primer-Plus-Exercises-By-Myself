//
// Created by klause on 2020/6/19.
//

#include <stdio.h>

int main(void) {
    float height;
    char name[40];
    printf("Please enter your name:");
    scanf("%s", name);
    printf("Please enter your height:");
    scanf("%f", &height);
    printf("%s, you are %.3f feet tall", name, height);
    return 0;
}
