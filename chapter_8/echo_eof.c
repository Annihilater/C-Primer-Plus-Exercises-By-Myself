//
// Created by klause on 2020/6/24.
//
// 8.3.2 文件结尾 程序 8.2 文件名:echo_eof.c
#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    return 0;
}
