//
// Created by klause on 2020/6/25.
//
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch, char_count = 0, word_count = 0;

    printf("Enter text to be analyzed: \n");
    while ((ch = getchar()) != '#') {
        if (ispunct(ch))            // 遇到标点符号就跳过（除空格、字母、数字外的任何可打印字符）
            continue;
        if (isspace(ch)) {          // 遇到空格，单词数+1，然后跳过
            word_count++;
            continue;
        }
        char_count++;               // 前面两个都没有跳过，说明遇到的是字母或数字，字符数+1
    }
    printf("The average number of words per word: %.2f", (double) char_count / word_count);
    return 0;
}
