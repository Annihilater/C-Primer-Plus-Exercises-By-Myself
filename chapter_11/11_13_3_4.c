//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <ctype.h>

void read(char *);

int main(void) {
    char characters[11];

    puts("请输入一些字符：");
    read(characters);
//    puts(characters);
    printf("%s", characters);
    return 0;
}

void read(char *str) {
    char ch;

    while (isspace(ch = (char) getchar()))
        continue;
    while (!isspace(ch)) {
        *str++ = ch;
        ch = (char) getchar();
    }
    *str = '\0';
}
