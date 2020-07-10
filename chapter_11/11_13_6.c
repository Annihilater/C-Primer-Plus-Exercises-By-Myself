//
// Created by klause on 2020/6/28.
//
#include <stdio.h>

int helper(char *, char);

int main(void) {
    char str1[40] = "helloworld";
    char c;
    int m;
    printf("Please input a char to find in %s(q to quit):\n", str1);
    while (1) {

        c = (char) getchar();
        if (c == '\n')
            continue;
        if (c == 'q')
            break;
        m = helper(str1, c);
        if (m == 0)
            printf("找不到! %d\n", m);
        else
            printf("找到了! %d\n", m);
        printf("Please input a char to find in %s(q to quit):\n", str1);
    }
    return 0;
}

int helper(char *str1, char c) {
    char *p;
    int index = 0;
    p = str1;
    while ((*p != c) && (*p != '\0')) {
        index++;
        p++;
    }

    if (*p == '\0') {
        return 0;//找到str1字符串的结尾都没有找到
    } else {
        printf("%c 在第 %d 位\n", *p, index);
        return 1;
    }
}
