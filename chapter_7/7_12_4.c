//
// Created by klause on 2020/6/24.
//

#include <stdio.h>

int main(void) {
    char ch;
    int n = 0;

    printf("Please enter text to be analyzed:(# to terminate):");

    while ((ch = getchar()) != '#') {
        if ('.' == ch) {
            putchar('!');
            n++;
        } else if ('!' == ch) {
            putchar('!');
            putchar('!');
            n++;
        } else {
            putchar(ch);
        }
    }
    printf("\nchanges : %d\n", n);
    return 0;
}
