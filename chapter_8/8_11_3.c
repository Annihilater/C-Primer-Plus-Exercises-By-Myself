//
// Created by klause on 2020/6/25.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch, low_count = 0, up_count = 0;;

    while ((ch = getchar()) != '#') {
        if (isupper(ch))
            up_count++;
        if (islower(ch))
            low_count++;
    }
    printf("A number of capital letters: %d\n", up_count);
    printf("A number of lower case letters: %d\n", low_count);
    return 0;
}
