//
// Created by klause on 2020/6/29.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100000

int count_char(char *st);

int count_words(char *st);

int count_punctuation(char *st);

int count_lowercase(char *st);

int count_capital_letter(char *st);

int count_digital(char *st);

int main(void) {
    char input[SIZE];

    printf("Please input your string:\n");
    fgets(input, SIZE, stdin);

    printf("Your string is:\n");
    printf("%s\n", input);

    printf("chars number: %d\n", count_char(input));
    printf("words number: %d\n", count_words(input));
    printf("digital number: %d\n", count_digital(input));
    printf("punctuation number: %d\n", count_punctuation(input));
    printf("lowercase number: %d\n", count_lowercase(input));
    printf("capital letter number: %d\n", count_capital_letter(input));
    return 0;
}

//统计字符数
int count_char(char *st) {
    return (int) strlen(st);
}

// 统计单词数，前一位不是空格，当前位是空格才算是一个单词
int count_words(char *st) {
    int n = 1;
    for (int i = 1; i < (int) strlen(st); ++i) {
        if (st[i] == ' ' && st[i - 1] != ' ') {
            n++;
        }
    }
    return n;
}

//统计标点符号
int count_punctuation(char *st) {
    int n = 0;
    for (int i = 0; i < strlen(st); ++i) {
        if (ispunct(st[i]))
            n++;
    }
    return n;
}

//统计小写字母
int count_lowercase(char *st) {
    int n = 0;
    for (int i = 0; i < strlen(st); ++i) {
        if (islower(st[i]))
            n++;
    }
    return n;
}

//统计大写字母
int count_capital_letter(char *st) {
    int n = 0;
    for (int i = 0; i < strlen(st); ++i) {
        if (isupper(st[i]))
            n++;
    }
    return n;
}

//统计数字字符数
int count_digital(char *st) {
    int n = 0;
    for (int i = 0; i < strlen(st); ++i) {
        if (isdigit(st[i]))
            n++;
    }
    return n;
}
