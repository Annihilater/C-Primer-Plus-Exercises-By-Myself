//
// Created by klause on 2020/6/23.
//

#include <stdio.h>

int main(void) {
    int num = 65;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}
