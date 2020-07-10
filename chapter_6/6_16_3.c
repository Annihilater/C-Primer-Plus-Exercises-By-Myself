//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", 70 - j);
        }
        printf("\n");
    }
    return 0;
}
