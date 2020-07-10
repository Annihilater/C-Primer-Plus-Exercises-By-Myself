//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

char *helper(char *);

int main(void) {
    char *st = "hello good";
    char *ptr;

    ptr = helper(st);
    printf("%c", *ptr);
    return 0;
}

char *helper(char *source) {
    char *ptr = NULL;//定义为空指针，如果下面 while 循环没有找到空格字符，就返回空指针
    int i = 0;

    if (*source == ' ')//判断首位是不是空格字符
        ptr = source;

    while (*source != ' ') {
        i++;
        source++;
        ptr = source;
    }

    printf("第 %d 位是空格!\n", i + 1);
    return ptr;
}
