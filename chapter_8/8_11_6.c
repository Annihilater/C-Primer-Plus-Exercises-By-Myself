//
// Created by klause on 2020/6/25.
//

#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void) {
    char ch;
    ch = get_first();
    printf("%c", ch);
    return 0;
}

char get_first(void) {
    int ch;
    while ((ch = getchar()) != '#') {
        if (isspace(ch))
            continue;
        break;
    }
    return (char) ch;
}
