//
// Created by klause on 2020/6/24.
//

#include <stdio.h>

int main(void) {
    char ch;
    int n = 0;

    printf("Please enter text to be analyzed:(# to terminate):");

    while ((ch = getchar()) != '#') {
        switch (ch) {
            case '.': {
                putchar('!');
                n++;
                break;
            }
            case '!': {
                putchar('!');
                putchar('!');
                n++;
                break;
            }
            default: {
                putchar(ch);
                break;
            }
        }
    }
    printf("\nchanges : %d\n", n);
    return 0;
}
