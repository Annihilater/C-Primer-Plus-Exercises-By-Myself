//
// Created by klause on 2020/6/22.
//

#include <stdio.h>

int main(void) {
    int num, i;
    printf("Please input a int number:");
    scanf("%d", &num);
    i = 0;
    while (i <= 10) {
        printf("%d\n", num + i);
        i++;
    }
    return 0;
}
