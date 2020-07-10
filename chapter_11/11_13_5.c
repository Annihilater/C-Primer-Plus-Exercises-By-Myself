//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

char *helper(char *, char);

int main(void) {
    char str1[40] = "helloworld";
    char c = 'x';
    char *p;
    p = helper(str1, c);
    if (p == NULL)
        printf("找不到!");
    else
        printf("%c", *p);
    return 0;
}

char *helper(char *str1, char c) {
    char *p;
    int index = 0;
    p = str1;
    while ((*p != c) && (*p != '\0')) {
        index++;
        p++;
    }

    if (*p == '\0') {
        return NULL;//找到str1字符串的结尾都没有找到
    } else {
        printf("%c 在第 %d 位\n", *p, index);
        return p;
    }
}
