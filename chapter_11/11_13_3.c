//
// Created by klause on 2020/6/28.
//

#include <stdio.h>

void read(char *, int);

int main(void) {
    char ar[20];
    int n = 10;
    read(ar, n);
    printf("%s", ar);
    return 0;
}

void read(char *ar, int n) {
    char c;
    int i = 0;

    // 当输入是以空白开始时，跳过前面所有的空白字符(空格、空白、换行、制表符)
    c = (char) getchar();
    while (c == ' ' || c == '\0' || c == '\t' || c == '\n') {
        c = (char) getchar();
    }

    // 当输入不超过 n，字符不是空格、空白、换行符时才进行读取操作
    while (i < n - 1 && c != '\n' && c != '\0' && c != ' ') {
        ar[i] = c;
        c = (char) getchar();
        i++;
    }

    // 如果单词没有达到最大长度的话，字符串末尾补空字符
    while (i <= n - 1) {
        ar[i] = '\0';
        i++;
    }

    // 当输入超过 n，字符是空格、空白、换行符时清空输入缓存
    while (getchar() != '\n')
        continue;

}
