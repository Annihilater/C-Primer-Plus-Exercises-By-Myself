//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

#define MAX 5 // 我有一个疑惑，为什么MAX一定得是要输入的最大字符数呢？为何不能更大，比如说预定为40等

char *get_string(char *str, int n);

int main(void) {
    char str[MAX];
    int i;

    puts("Please enter a n characters: ");
    get_string(str, 5);

    for (i = 0; i < 5; i++)
        putchar(str[i]);
    return 0;
}

char *get_string(char *str, int n) {
    int i = 0;
    char c = (char) getchar();

    while (i < n && c != ' ' && c != '\t' && c != '\n') {
        *(str + i) = c;
        i++;
        c = (char) getchar();
    }
    return str;
}
