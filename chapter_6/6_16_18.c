//
// Created by klause on 2020/6/23.
//
#include <stdio.h>

int main(void) {
    int friends = 5;
    printf("1 5\n");
    for (int i = 1; i < 10000; ++i) {
        friends = (friends - i) * 2;
        printf("%d %d\n", i + 1, friends);
        if (friends > 150) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}

