//
// Created by klause on 2020/6/23.
//
#include <stdio.h>

int main(void) {
    char ch;
    printf("Please input a char: ");
    scanf("%c", &ch);

    for (int i = 0; i <= ch - 65; ++i) {
        for (int j = 0; j < ch - 65 - i; ++j) {
            printf(" ");
        }
        for (int k = 0; k <= i; ++k) {
            printf("%c", 65 + k);
        }
        for (int l = 0; l < i; ++l) {
            printf("%c", 65 + i - l - 1);
        }
        printf("\n");
    }
    return 0;
}
