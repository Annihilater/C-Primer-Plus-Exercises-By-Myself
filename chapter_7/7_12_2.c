//
// Created by klause on 2020/6/24.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    int n = 0;
    printf("Please enter text to be analyzed:(# to terminate): ");
    while ((ch = getchar()) != '#') {
        printf("%c-%d   ", ch, ch);

        n++;
        if (n % 8 == 0)
            putchar('\n');

    }
    return 0;
}
