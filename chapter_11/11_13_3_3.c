//
// Created by klause on 2020/6/28.
//

#include <stdio.h>
#include <string.h>

#define MAX 40

char *get_word(char *str);

int main(void) {
    char str[MAX];
    int i;

    puts("Please enter some characters: ");
    get_word(str);
    printf("The first word in this sentence is:\n");
    for (i = 0; i < strlen(str); i++)
        putchar(str[i]);
    return 0;
}

char *get_word(char *str) {
    char c;
    int i = 0;
    c = (char) getchar();
    // 丢掉该行之前多余的空格、制表符和换行符
    while (c == ' ' || c == '\n' || c == '\t') {
//        putchar(c);
        c = (char) getchar();
    }
    // 读取输入行里的第一个单词到数组
    while (c != ' ' && c != '\n' && c != '\t') {
        *(str + i) = c;
        i++;
        c = (char) getchar();
    }
    // 读取之后，丢掉该行中其他的字符
    while (getchar() != '\n')
        continue;
    *(str + i) = '\0'; // 最后一个字符为空字符，这样返回的就是一个指向字符串的指针
    return str;
}
