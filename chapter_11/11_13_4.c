//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <ctype.h>

void read(char *, int);

int main(void) {
    char characters[11];
    int n = 3;

    puts("请输入一些字符：");
    read(characters, n);
    puts(characters);
    return 0;
}

void read(char *str, int n) {
    char ch;
    int i = 0;

    while (isspace(ch = (char) getchar()))
        continue;

    while (i < n && !isspace(ch)) {
        *str++ = ch;
        ch = (char) getchar();
        i++;
    }
    *str = '\0';
}
