//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

void read(char *, int);

int main(void) {
    char characters[100];
    int n = 20;//这个 n 要小于 characters 数组的长度，否则会报错

    puts("请输入一些字符：");
    read(characters, n);
    puts(characters);
    return 0;
}

void read(char *str, int n) {
    char ch;
    int i = 0;
    while ((ch = (char) getchar()) != '#' && i < n - 1) {
        *(str + i) = ch;
        i++;
    }
    *(str + n - 1) = '\0';//末尾设置为空字符
}
