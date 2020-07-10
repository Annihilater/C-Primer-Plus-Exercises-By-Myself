//
// Created by klause on 2020/6/26.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int helper(char);

int main(void) {
    int r;
    char ch;
    printf("Please enter your text: \n");

    while (1) {
        while (scanf("%c", &ch) != 1) {
            printf("Please enter letters: \n");
        }
        if (ch == '#') break;
        r = helper(ch);

        if (r == -1)
            printf("%c is not letter.\n", ch);
        else
            printf("%c is letter and number is %d.\n", ch, r);
    }
    return 0;
}

int helper(char x) {
    int r;
    if (isalpha(x)) {
        if (isupper(x))
            r = toascii(x) - 64;
        else
            r = toascii(x) - 96;
    } else
        r = -1;
    return r;
}
